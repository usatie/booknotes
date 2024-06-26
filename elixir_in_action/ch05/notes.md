# 5. Concurrency Primitives
## 5.1 Concurrency in BEAM
- on a quad-core machine, one OS process and four OS threads
- initial memory footprint is a few kilobytes for a single process
- (whereas OS threads usually use a couple megabytes just for the stack)
- processes share no memory
- each process can manage some state
- each process can receive messages from other processes

## 5.2 Working with processes
- To run something concurrently, you must create a separate process
```
run_query =
  fn query_def ->
    Process.sleep(2000)
    "#{query_def} result"
  end
Enum.map(1..5, fn index -> run_query.("query #{index}") end)
```
### 5.2.1 Creawting process
- `spawn/1` returns PID, which can be used to communicate with the process
- After the lambda finishes, the spawned process is stoped
- can pass data to the created process via the closure mechanism
- When it's passed to another process, the data is deep copied because two processes can't share any memory
```
spawn(fn ->
  expression_1
  ...
  expression_n
end)
```
```
spawn(fn ->
  query_result = run_query.("query 1")
  IO.puts(query_result)
end)

async_query = 
  fn query_def ->
    spawn(fn ->
      query_result = run_query.(query_def)
      IO.puts(query_result)
    end)
  end
async_query.("query 1")
Enum.map(1..5, &async_query.("query #{&1}"))
```
### 5.2.2 Message passing
- "fire-and-forget"
- a message is deep copied when it's sent
- FIFO queue
- `self/0` to obtain the PID of the current process
- `receive` can block if there's no message (match)
- `receive` tries to find the first(oldest) match
- If a message doesn't match, it's put back into the queue
```
receive do
  pattern_1 -> do_something
  pattern_2 -> do_something_else
after
  5000 -> IO.puts("message not received")
end

send(self(), "a message")
receive do
  message -> IO.inspect(message)
end

send(self(), {:message, 42})
receive do
  {:message, id} -> IO.puts("received message #{id}")
end
```
#### Receive behavior
```
send(self(), {:message, 42})
result =
  receive do
    {:message, x} ->
      x + 2
  end
IO.inspect(result)
```
#### Synchronous sending
- The caller must include its own PID in the message contents and then wait for a response from the receiver
sender
```
send(pid, {self(), some_message})
receive do
  {:response, response} -> ...
end
```
receiver
```
receive do
  {caller_pid, message) ->
    response = ...
    send(caller_pid, {:response, response})
end
```
#### Collecting query results
```
run_query =
  fn query_def ->
    Process.sleep(2000)
    "#{query_def} result"
  end

async_query = 
  fn query_def ->
    caller = self()
    spawn(fn ->
      query_result = run_query.(query_def)
      send(caller, {:query_result, query_result})
    end)
  end
Enum.each(1..5, &async_query.("query #{&1}"))

get_result =
  fn ->
    receive do
      {:query_result, result} -> result
    end
  end
results = Enum.map(1..5, fn _ -> get_result.() end)
```
## 5.3 Stateful server processes
- long-running and maintain some internal state
### 5.3.1 Server processes
- process that runs for a long time (or forever)
- by endless tail recursion
- The loop isn't CPU intensive, because waitinig for a message puts the process in a suspended state and doesn't waste CPU cycles.
- Interface functions are public and are executed in the caller process
- Implement functions are usualy private and run in the server process
```
server_pid = DatabaseServer.start()

DatabaseServer.run_async(server_pid, "query 1")
DatabaseServer.get_result()

DatabaseServer.run_async(server_pid, "query 2")
DatabaseServer.get_result()
```
#### Server processes are sequential
- You can start a pool of server processes and then for each query, you can somehow choose one of the processes
```
pool = Enum.map(1..100, fn _ -> DatabaseServer.start() end)
Enum.each(
  1..5,
  fn query_def ->
    server_pid = Enum.at(pool, :rand.uniform(100) - 1) # selects a random process
    DatabaseServer.run_async(server_pid, query_def)
  end
)
Enum.map(1..5, fn _ -> DatabaseServer.get_result() end)
```
### 5.3.2 Keeping a process state
- To keep state in the process, you can extend the loop function with aditional argument(s)
```
def start do
  spawn(fn ->
    initial_state = ...
    loop(initial_state)
  end)
end

defp loop(state) do
  ...
  loop(state)
end
```
### 5.3.3 Mutable state
- From the outside, stateful processes are mutable
- Sending a message is an operation with possible side effects
- Server handles messages in the order received, so requests are handled in the proper order
-
```
defp loop(state) do
  new_state = 
    receive do
      ...
    end
  loop(new_state)
end
```
```
pid = Calculator.start()
Calculator.value(pid)
Calculator.add(pid, 10)
Calculator.sub(pid, 5)
Calculator.mul(pid, 3)
Calculator.div(pid, 5)
Calculator.value(pid)
```
### 5.3.4 Complex states
- It's worth extracting the state manipulation to a separate module
- Keeping the server process focused only on passing messages and keeping the state
- You shouldn't abuse processes to avoid using the functional approach of transforming immutable data
```
todo_server = TodoServer.start()
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-19], title: "Dentist"})
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-20], title: "Shopping"})
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-19], title: "Movie"})
TodoServer.entries(todo_server, ~D[2023-12-19])
TodoServer.entries(todo_server, ~D[2023-12-20])
```
### 5.3.5 Registered processes
- Give a process a local name
- Only in the currently running BEAM instance
- Important role in process discovery
- Increasingly important when dealing with restarting processes and distribuetd system
```
Process.register(self(), :some_name)
send(:some_name, :msg)
receive do
  msg -> IO.puts("received #{msg}")
end
```
```
todo_server = TodoServer.start()
TodoServer.add_entry(%{date: ~D[2023-12-19], title: "Dentist"})
TodoServer.add_entry(%{date: ~D[2023-12-20], title: "Shopping"})
TodoServer.add_entry(%{date: ~D[2023-12-19], title: "Movie"})
TodoServer.entries(~D[2023-12-19])
TodoServer.entries(~D[2023-12-20])
```
## 5.4 Runtime considerations
### 5.4.1 A process is sequential
- Identify the bottleneck, and optimize it
- Parallelization isn't a remedy for a poorly structured algorithm
### 5.4.2 Unlimited process mailboxes
- Theoretically unlimited
- In practice, limited by available mmeory
- Overgrown mailbox contents can significantly affect performance
- You should introduce a match-all receive clause to deal with unexpected kinds of messages
```
defp loop
  receive do
    {:message, msg} -> do_something(msg)
    other -> warn_about_unknown_message(other)
  end

  loop()
end
```
### 5.4.3 Shared-nothing concurrency
- Having many processes frequently send big messages may affect system performance
- special case in which the data is copied by reference:
1. binaries (including string) larger than 64 bytes
2. hardcoded constants (also known as literals)
3. terms created via the `:persistent_term` API
https://www.erlang.org/doc/man/persistent_term.html
- Garbage collection is concurrent and distribuetd
- Instead of one large "stop-the-entire-system" collection, many smaller, typically faster, collections
### 5.4.4 Scheduler inner workings
- m:n threading
- `iex --erl "+S 1"`
- small execution window of approximately 2,000 function calls
- Long-running CPU-bound work or a larger garbage collection might be performed on another thread (`dirty scheduler`)
- I/O proces yields the execution to the scheduler
```
System.schedulers()
```
- `smp:8:8` vs `smp:1:1`
```
$ iex
Erlang/OTP 26 [erts-14.2.5] [source] [64-bit] [smp:8:8] [ds:8:8:10] [async-threads:1] [jit] [dtrace]
$ iex --erl "+S 1"
Erlang/OTP 26 [erts-14.2.5] [source] [64-bit] [smp:1:1] [ds:1:1:10] [async-threads:1] [jit] [dtrace]
```
- Runs an infinite CPU-bound loop:
```
spawn(fn ->
  Stream.repeatedly(fn -> :rand.uniform() end)
  |> Stream.run()
end)

Enum.sum(1..1_000_000_000)
```
