# 8. Fault tolerance basics
- The core tool for error handling is concurrency.
- Instead of trying to reduce the number of errors, the priority is to minimize effects of errors and recover from errors automatically.
## 8.1 Run-time errors
### 8.1.1 Error types
Three types of run-time errors:
1. errors
2. exits
3. throws
- `raise/1`: Raise your own error with error string
- If your function explicitly raises an error, you should append the ! character to its name : `File.open!`
- `exit/1`: Deliberately terminates a process with arbitrary term
- `throw/1`: Allow nonlocal returns with arbitrary term
```
spawn(fn -> raise("error string") end)
spawn(fn -> exit(:arbitrary_term) end)
spawn(fn -> throw(:arbitrary_term) end)
```
### 8.1.2 Handling errors
```
try do
catch
  error_type, error_value -> ...
after
  ...
end
```
- error_type will contain an atom :error, :exit, or :throw
```
try_helper = fn fun ->
  try do
    fun.()
    IO.puts("No error.")
  catch type, value ->
    IO.puts("""
      Error
        #{inspect(type)}
        #{inspect(value)}
    """)
  end
end

try_helper.(fn -> raise("Something went wrong") end)
try_helper.(fn -> throw("Thrown value") end)
try_helper.(fn -> exit("I'm done") end)
```
- With try, the return value is the result of the last executed expression, either from the do block or the catch block
- The after clause doesn't affect the result of the entire try expression
```
result = try do
  throw("Thrown value")
catch type, value -> {type, value}
end
{:throw, "Thrown value"}
result
{:throw, "Thrown value"}
```
- Because catch block is a pattern, multiple caluses can be specified
- The after block is useful for cleaning up resources
- `defexception` macro (https://hexdocs.pm/elixir/Kernel.html#defexception/1)
- try documentation (https://hexdocs.pm/elixir/Kernel.SpecialForms.html#try/1)
- Getting Started section (https://elixir-lang.org/getting-started/try-catch-and-rescue.html)
Q. Why rescue is necessary? Isn't catch enough?
- A run-time error has a type, which can be :error, :exit, or :throw
- A run-time error also has a value, which can be any arbitrary term
- If a run-time error sin't handled, the corresponding process will terminate
- Common idiom is to let the process crash and then do something about it
## 8.2 Errors in concurrent systems
- Automatic isolation and protection.
- A crash on one process won't leave memory garbage.
```
spawn(fn -> 
    spawn(fn -> 
      Process.sleep(1000)
      IO.puts("Process 2 finished")
    end)
    raise("Something went wrong")
end)
```
### 8.2.1 Linking processes
```
spawn(fn -> 
    spawn_link(fn -> 
      Process.sleep(1000)
      IO.puts("Process 2 finished")
    end)
    raise("Something went wrong")
end)
```
- When a process terminates abnormally, the lniked process is also taken down.
- Link as a communication channel for providing notifications about process terminations
- If two processes are linked, and one of them terminates, the other process receives an exit signal - a notification that a process has crashed.
- An exit signal contains the PID and exit reason
#### Trapping exits
- `msg` : `{:EXIT, from_pid, exit_reason}`
- `exit_reason` : `{reason, where}`
```
spawn(fn -> 
    Process.flag(:trap_exit, true)

    spawn_link(fn -> raise("Something went wrong") end)
    
    receive do
      msg -> IO.inspect(msg)
    end
end)
```
### 8.2.2 Monitors
- `Process.monitor(target_pid)` for unidirectional propagation
- Observer process won't crash when the monitored process terminates
- `Process.demonitor(monitor_ref)` to stop monitoring
- `msg` : `{:DOWN, monitor_ref, :process, from_pid, exit_reason}`
```
target_pid = spawn(fn -> 
  Process.sleep(1000)
end)

Process.monitor(target_pid)
receive do
  msg -> IO.inspect(msg)
end
```
## 8.3 Supervisors
- A supervisor is a generic process that manages the life cycle of other processes
- A worker is a non-supervisor process
### 8.3.1 Preparing the existing code
- `Supervisor.start_link(module, init_arg, options \\ [])`
- `:strategy` known as restart strategy is mandatory
- When `GenServer.call` is called, it sets up a temporary monitor that targets the server process.
```
Supervisor.start_link([Todo.Cache], strategy: :one_for_one)
bobs_list = Todo.Cache.server_process("Bob's list")
```
### 8.3.2 Starting the supervisor process
- Register the to-do cache under a local name to allow process discovery
```
cache_pid = Process.whereis(Todo.Cache)
db_pid = Process.whereis(Todo.Database)
Process.exit(cache_pid, :kill)
Process.whereis(Todo.Cache)
```
### 8.3.3 Child specification
1. How shoudl the child be started?
2. What should be done if the child terminates?
3. What term should be used to uniquely identify each child?
```
%{
  id: Todo.Cache,
  start: {Todo.Cache, :start_link, [nil]},
}
```
- start field is a triplet: `{module, start_function, list_of_arguments}`
- supervisor will call `apply(module, start_function, list_of_arguments)`
```
Supervisor.start_link(
  [
    %{
      id: Todo.Cache,
      start: {Todo.Cache, :start_link, [nil]},
    }
  ],
  strategy: :one_for_one
)
```
- This will invoke `Todo.Cache.start_link(nil)`
```
Todo.Cache.child_spec(nil)
```
https://hexdocs.pm/elixir/GenServer.html#module-how-to-supervise
### 8.3.4 Wrapping the supervisor
```
Todo.System.start_link()
```
### 8.3.5 Using a callback module
- `use Supervisor` to get more control (e.g. extra initialization before starting children)
- more flexible with respect to hot-code reloading
### 8.3.6 Linking all processes
- We need to take down all existing to-do servers when cache server is down
- After linking all the processes, the code below shows that length is not changed before/after exit
```
Todo.System.start_link()
Todo.Cache.server_process("Bob's list")
Todo.Cache.server_process("Bob's list")
length(Process.list())
Process.exit(Process.whereis(Todo.Cache), :kill)
Todo.Cache.server_process("Bob's list")
length(Process.list())
```
### 8.3.7 Restart frequency
- maximum restart frequency
- By default, 3 restarts in 5 seconds
- After the maximum restart frequency was exceeded, the supervisor gave up and terminated, taking down the child processes as well
```
for _ <- 1..4 do
  Process.exit(Process.whereis(Todo.Cache), :kill)
  Process.sleep(200)
end
```
