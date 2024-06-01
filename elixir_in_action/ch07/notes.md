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
