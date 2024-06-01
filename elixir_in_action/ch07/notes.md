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
