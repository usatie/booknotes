# 7. Building a concurrent system
## 7.1 Working with the Mix project
https://hexdocs.pm/elixir/introduction-to-mix.html
https://hexdocs.pm/mix
```
$ mix new todo
$ cd todo
$ mix compile
$ mix test
$ iex -S mix

{:ok, todo_server} = Todo.Server.start()
Todo.Server.add_entry(
    todo_server,
    %{date: ~D[2023-12-19], title: "Dentist"}
)
Todo.Server.entries(todo_server, ~D[2023-12-19])
```
## 7.2 Managing multiple to-do lists
### 7.2.1 Implementing a cache
```
{:ok, cache} = Todo.Cache.start()
Todo.Cache.server_process(cache, "Bob's list")
Todo.Cache.server_process(cache, "Bob's list")
Todo.Cache.server_process(cache, "Alice's list")
Todo.Cache.server_process(cache, "Alice's list")
bobs_list = Todo.Cache.server_process(cache, "Bob's list")
Todo.Server.add_entry(
  bobs_list,
  %{date: ~D[2023-12-19], title: "Dentist"}
)
Todo.Server.entries(bobs_list, ~D[2023-12-19])
Todo.Cache.server_process(cache, "Alice's list") |>
Todo.Server.entries(~D[2023-12-19])
```
### 7.2.2 Writing tests
- A test file must reside in the test folder, and its name must end with `_test.exs`
- `.exs` stands for Elixir script
```
defmodule Todo.CacheTest do
  use ExUnit.Case
end
```
- comparisons: ==, !=, >, <
    - assert A == B
    - assert A != B
    - assert A > B
    - assert A < B
- pattern-matching: =
    - assert A = B
```
left_value = bob_pid
right_value = Todo.Cache.server_process(cache, "alice")

if left_value == right_value do
  # raise an error
end
```
### 7.2.3 Analyzing process dependencies
- Sufficient for a load of at least 200,000 requests per second
- (at least 251,889 rps in my environment)
- If you need to make sure part of the code is synchronized, it's best to run that code in a dedicated process.
```
$ mix new todo_cache
$ cd todo_cache
$ elixir --erl "+P 2000000" -S mix run -e LoadTest.run
average put 3.970946 µs
average get 1.381032 µs
```
## 7.3 Persisting data
- Encode the data into the Erlang external term format
### 7.3.1 Encoding and persisting
- :erlang.term_to_binary/1
### 7.3.2 Using the database
```
{:ok, cache} = Todo.Cache.start()
bobs_list = Todo.Cache.server_process(cache, "bobs_list")
Todo.Server.add_entry(
    bobs_list,
    %{date: ~D[2023-12-19], title: "Dentist"}
)
```
### 7.3.3 Analyzing the system
- If requests to the database come in ifaster than they can be handled, the process mailbox will grow and increasingly consume memory.
- Q. What if a server get reply from timeout-request? Does it remain in the server's mailbox forever?
### 7.3.4 Addressing the process bottleneck
#### Bypassing the process
- The reason for running a piece of code in a dedicated server:
  - The code must manage a long-living state
  - The code handles a kind of resource that can and should be reused between multiple invocations, such as a TCP connection, database connection, file handle, and so on.
  - A critical section of the code must be synchronized. Only one instance of this code may be running in any momemnt.
- We can store to the file directly from the to-do server process.
- But the problem with this approach is that concurrency is unbound.
#### Handling requests concurrently
- Each request is serialized through the central database server process
- But this server process spawns one-off worker processes that perform the actual request handling.
- The concurrency is still unbound, so too many simultaneous clients might overload the disk I/O
```
def handle_cast({:store, key, data}, state) do
  spawn(fn ->
    key
    |> file_name()
    |> File.write!(:erlang.term_to_binary(data))
  end)

  {:noreply, state}
end

def handle_call({:get, key}, caller, state) do
  spawn(fn ->
    data = case File.read(file_name(key)) do
      {:ok, contents} -> :erlang.binary_to_term(contents)
      _ -> nil
    end

    GenServer.reply(caller, data)
  end)

  {:noreply, state}
end
```
#### Limiting concurrency with pooling
- A typical remedy for this problem is to introduce pooling
- Essentially, this technique keeps the concurrency level under control
- It works best when dealing with resources that can't handle unbound concurrency.
https://github.com/devinus/poolboy
https://github.com/elixir-lang/ecto
### 7.3.5 Exercise: Pooling and synchronizing
