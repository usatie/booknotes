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
