# 4. Data abstraction
- In a typical OO language, the basic abstraction building blocks are classes and objects.
- In Elixir, modules are bulding blocks, which are collections of functions.
- `String` and `List` are examples of modules that are dedicated to a specific data type.

1. A module is in charge of abstracting some behavior.
2. The module's functions usually expect an instance of the abstraction as the first argument.
3. Modifier functions return a modified version of the abstraction.
4. Query functions return some other type of data.

## 4.3 Polymorphism with protocols
### 4.3.1 Protocol basics
- Contract is called a protocol
- Roughly equivalent to an OO interface
```
defprotocol String.Chars do
  def to_string(term)
end

String.Chars.to_strin(1)
String.Chars.to_strin(:an_atom)
String.Chars.to_strin([1,2,3])
#String.Chars.to_strin(TodoList.new())   # Error!
#IO.puts(TodoList.new())                 # Error!
```

## 4.2 Working with hierarchical data
### 4.2.1 Generating IDs
```
$ iex todo_crud.ex

todo_list = TodoList.new() |>
  TodoList.add_entry(%{date: ~D[2023-12-19], title: "Dentist"}) |>
  TodoList.add_entry(%{date: ~D[2023-12-20], title: "Shopping"}) |>
  TodoList.add_entry(%{date: ~D[2023-12-20], title: "Movies"})

TodoList.entries(todo_list, ~D[2023-12-19])
TodoList.entries(todo_list, ~D[2023-12-20])
```
### 4.2.2 Updating entries
```
todo_list = TodoList.update_entry(todo_list, 1, &Map.put(&1, :date, ~D[2023-12-24]))
```
### 4.2.3 Imutable hierarchical updates
- If you have hierarchical data, you can't directly modify part of it that resides deep in its tree.
```
def update_entry(todo_list, entry_id, updater_fun) do
  case Map.fetch(todo_list.entries, entry_id) do
    :error ->
      todo_list
    {:ok, old_entry} ->
      new_entry = updater_fun.(old_entry)
      new_entries = Map.put(todo_list.entries, new_entry.id, new_entry)
      %TodoList{todo_list | entries: new_entries}
  end
end
```
#### Provided helpers
- `Kernel.put_in/2` macro
- Source : `todo_list`
- Path : `[3].title`
- `get_in/2, put_in/2, get_and_update_in/2` macros
- `get_in/3, put_in/3, get_and_update_in/3` functions
- these macros and functions rely on the Access module
https://hexdocs.pm/elixir/Access.html
```
todo_list = %{
  1 => %{date: ~D[2023-12-19], title: "Dentist"},
  2 => %{date: ~D[2023-12-20], title: "Shopping"},
  3 => %{date: ~D[2023-12-19], title: "Movies"}
}
put_in(todo_list[3].title, "Theater")
put_in(todo_list, [3, :title], "Theater")
```
#### Exercise: Deleting an entry
### 4.2.4 Iterative updates
```
todo_list = TodoList.new(entries)
```
### 4.2.5 Exercise: Importing from a file
```
todo_list = TodoList.CsvImporter.import("todos.csv")
```

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
### 4.1.2 Composing abstractions
### 4.1.3 Structuring data with maps
### 4.1.4 Abstracting with structs
https://hexdocs.pm/elixir/Kernel.html#defstruct/1
```
defmodule Fraction do
  defstruct a: nil, b: nil
  ...
end

one_half = %Fraction{a: 1, b: 2}
one_half.a
one_half.b
%Fraction{a: foo, b: bar} = one_half
%Fraction{} = one_half               # match
%Fraction{} = %{a: 1, b: 2}          # no match
one_quater = %Fraction{one_half | b: 4 }
```
#### Structs vs maps
```
one_half = %Fraction{a: 1, b: 2}
# Enum.to_list(one_half)                         # Error (struct is not enumerable by default)
Map.to_list(one_half)                            # OK
one_quater = %{a: 1, b: 4, __struct__: Fraction} # This is Fraction!

# %Fraction{a: a, b: b} = %{a: 1, b: 2}          # Error
%{a: a, b: b} = %Fraction{a: 1, b: 2}            # OK

another = Map.put(one_half, :d, 100)             # OK
Fraction.value(another)                          # OK (pattern match can't guarantee that it has no extra keys)
```
#### Records
https://hexdocs.pm/elixir/Record.html
- `defrecord` and `defrecordp`
- Records are present mostly for historical reasons
- Interface Erlang library using `Record.extract/2` and `defrecord`
### 4.1.5 Data transparency
- Data in Elixir is always transparent
- Clients can read any information from your structs
```
mapset = MapSet.new([:monday, :tuesday])
inspect(mapset, structs: false)

iex(1)> Fraction.new(1, 4) |> 
...(1)> IO.inspect() |>
...(1)> Fraction.add(Fraction.new(1, 4)) |>
...(1)> IO.inspect() |>
...(1)> Fraction.add(Fraction.new(1, 2)) |>
...(1)> IO.inspect() |>
...(1)> Fraction.value()
```
