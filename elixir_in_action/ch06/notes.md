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
