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
