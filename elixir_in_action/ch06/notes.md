# 6. Generic server processes
## 6.1 Building a generic server process
- Spawn a separate process
- Run an infinite loop in the process
- Maintain the process state
- React to messages
- Send a response back to the caller
### 6.1.1 Plugging in with modules
- Make the generic code a plug-in module as the argument. That module is called a callback module
```
some_module = IO
some_module.puts("Hello")
```
### 6.1.2 Implementing the generic code
- `server_process.ex`
- ServerProcess.start, ServerProcess.loop, ServerProcess.call
```
pid = ServerProcess.start(KeyValueStore)
ServerProcess.call(pid, {:put, :some_key, :some_value})
ServerProcess.call(pid, {:get, :some_key})
```
### 6.1.3 Using the generic abstraction
- KeyValueStore.init, KeyValueStore.handle_call, KeyValueStore.start, KeyValueStore.put, KeyValueStore.get
- Interface functions run in client processes, whereas callback functions are always invoked in the server process.
```
pid = KeyValueStore.start()
KeyValueStore.put(pid, :some_key, :some_value)
KeyValueStore.get(pid, :some_key)
```
### 6.1.4 Supporting asynchronous requests
- `call` for synchronous requests
- `cast` for asynchronous requests
### 6.1.5 Exercise: Refactoring the to-do server
```
todo_server = TodoServer.start()
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-19], title: "Dentist"})
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-20], title: "Shopping"})
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-19], title: "Movie"})
TodoServer.entries(todo_server, ~D[2023-12-19])
TodoServer.entries(todo_server, ~D[2023-12-20])
```
## 6.2 Using GenServer
- calls and casts
- Customizable timeouts for call requests
- Propagation of server process crashes to client processes waiting for aresponse
- Support for distribuetd systems
### 6.2.1 OTP behaviours
https://hexdocs.pm/elixir/Module.html#module-behaviour
https://erlang.org/doc/design_principles/des_princ.html
Erlang behaviours (Elixir wrapper)
- gen_server (GenServer)
- supervisor (Supervisor)
- application (Application)
- gen_event
- gen_statem
### 6.2.2 Plugging into GenServer
https://hexdocs.pm/elixir/1.13.4/Module.html#c:__info__/1
```
defmodule KeyValueStore do
  use GenServer
end
KeyValueStore.__info__(:functions)
GenServer.start(KeyValueStore, nil)
```
### 6.2.3 Handling requests
```
$ iex key_value_gen_server.ex

{:ok, pid} = GenServer.start(KeyValueStore, nil)
GenServer.cast(pid, {:put, :some_key, :some_value})
GenServer.call(pid, {:get, :some_key})

{:ok, pid} = KeyValueStore.start()
KeyValueStore.put(pid, :some_key, :some_value)
KeyValueStore.get(pid, :some_key)
```
### 6.2.4 Handling plain messages
- GenServer.handle_info/2
### 6.2.5 Other GenServer features
#### Compile-time checking
https://erlang.org/doc/man/gen_server.html
- @impl will generate a warning when improperly implemented
```
defmodule EchoServer do
  use GenServer

  @impl GenServer
  def handle_call(some_request, server_state) do
    {:reply, some_request, server_state}
  end
end
```
#### Name registration
- Local registration is important because it supports patterns of fault tolerance and distribuetd systems.
- `__MODULE__` can be used to be replaced with the name of the module during compilation
```
GenServer.start(CallbackModule, init_param, name: :some_name)
GenServer.call(:some_name, ...)
GenServer.cast(:some_name, ...)

defmodule KeyValueStore do
  def start() do
    GenServer.start(KeyValueStore, nil, name: KeyValueStore)
  end

  def put(key, value) do
    GenServer.cast(KeyValueStore, {:put, key, value})
  end
  
  ...
end

defmodule KeyValueStore do
  def start() do
    GenServer.start(__MODULE__, nil, name: __MODULE__)
  end

  def put(key, value) do
    GenServer.cast(__MODULE__, {:put, key, value})
  end
  
  ...
end
```
#### Stoppping the server
- Common cases
    - {:ok, initial_state}                 from init/1
    - {:reply, response, new_state}        from hande_call/3
    - {:noreply, new_state}                from handle_cast/2 and handle_info/2
- To stop the server, 
    - {:stop, reason} or :ignore           from init/1
    - {:stop, reason, new_state}           from handle_*
    - {:stop, reason, response, new_state} from handle_call
- The reason why you need to return a new state is that it's useful for performing cleanup. The new state can be available from terminate/2 callback function.
### 6.2.6 Process life cycle
- Erlang is an accidental implementation of the actor model
### 6.2.7 OTP-compliant processes
- In production, you should avoid using plain proceses started with `spawn`
- You should use OTP-compliant processes
- Task for running one-off jobs
- Agent for managing and exposing states
https://hexdocs.pm/elixir/Task.html
https://hexdocs.pm/elixir/Agent.html
- GenState for back pressure and load control
https://hexdocs.pm/gen_stage
- Phoenix.Channel to facilitate bidirectional communication between a cliant and web server over protocols such as WebSocket or HTTP
https://hexdocs.pm/phoenix/Phoenix.Channel.html
### 6.2.8 Exercise: GenServer-powered to-do server
```
{:ok, todo_server} = TodoServer.start()
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-19], title: "Dentist"})
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-20], title: "Shopping"})
TodoServer.add_entry(todo_server, %{date: ~D[2023-12-19], title: "Movie"})
TodoServer.entries(todo_server, ~D[2023-12-19])
TodoServer.entries(todo_server, ~D[2023-12-20])
```
