# 4. Data abstraction
- In a typical OO language, the basic abstraction building blocks are classes and objects.
- In Elixir, modules are bulding blocks, which are collections of functions.
- `String` and `List` are examples of modules that are dedicated to a specific data type.

1. A module is in charge of abstracting some behavior.
2. The module's functions usually expect an instance of the abstraction as the first argument.
3. Modifier functions return a modified version of the abstraction.
4. Query functions return some other type of data.
## 4.1 Abstracting with modules
- Module-based abstractions aren't proper data types
- For example, a MapSet instance is also a map
```
days =
    MapSet.new() |>
    MapSet.put(:monday) |>
    MapSet.put(:tuesday)
MapSet.member?(days, :monday)
is_map(MapSet.new())
```
### 4.1.1 Basic abstraction
```
$ iex simple_todo.ex
todo_list =
    TodoList.new() |> 
    TodoList.add_entry(~D[2023-12-19], "Dentist") |>
    TodoList.add_entry(~D[2023-12-20], "Shopping") |>
    TodoList.add_entry(~D[2023-12-19], "Movies")
TodoList.entries(todo_list, ~D[2023-12-20])
TodoList.entries(todo_list, ~D[2023-12-19])
TodoList.entries(todo_list, ~D[2023-12-18])
```
