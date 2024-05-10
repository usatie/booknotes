# 2.4 Understanding the type system
## 2.4.4 Lists
- Singly linked lists
- `prime_numbers = [2, 3, 5, 7]`
- `length(prime_numbers)`
- `Enum.at(prime_numbers, 3)`
- `5 in prime_numbers`
- `4 in prime_numbers`
- List.replace_at(prime_numbers, 1, 11)
- List.insert_at(prime_numbers, 0, 11)
- List.insert_at(prime_numbers, -1, 11)
- List.insert_at(prime_numbers, 10000, 11)
- [1,2,3] ++ [4,5]
- it really looks like Lisp's cons cells
- hd([1,2,3,4])
- tl([1,2,3,4])

```
a_list = [head | tail]
```
https://hexdocs.pm/elixir/List.html
https://hexdocs.pm/elixir/Enum.html

## 2.4.3 Tuples
- `person = {"Bob", 25}`
- `elem(person, 1)`
- `put_elem(person, 1, 27`
- `put_elem` returns new version

## 2.4.2 Atoms
- literally named constatns
- enumerations in C/C++
- `variable = :some_atom`, the variable only contains a reference to the atom table
```
iex(1)> :an_atom
:an_atom
iex(2)> :another_atom
:another_atom
iex(3)> :"an atom with spaces"
:"an atom with spaces"
```

### alias
- `AnAtom == Elixir.AnAtom`
- `AnAtom == :"Elixir.AnAtom"`
- `alias IO, as: MyIO`
```
iex(5)> AnAtom
AnAtom
iex(6)> AnAtom == :some_atom
false
iex(7)> AnAtom == :"Elixir.AnAtom"
true
iex(8)> AnAtom == :"AnAtom"
false
iex(9)> AnAtom == :AnAtom
false
iex(2)> AnAtom == Elixir.AnAtom
true
```

```
iex(4)> alias IO, as: MyIO
IO
iex(5)> MyIO
IO
iex(6)> MyIO.puts("hello")
hello
:ok
iex(7)> MyIO == Elixir.IO
true
iex(8)> MyIO == :"Elixir.IO"
true
```

### Atoms as booleans
- Boolean is atom, but not type
```
iex(9)> true and false
false
iex(10)> true and true
true
iex(11)> false or false
false
iex(12)> false or true
true
iex(13)> not false
true
iex(14)> not :some_other_atom
** (ArgumentError) argument error
    :erlang.not(:some_other_atom)
    iex:14: (file)
```

### Nil and truthy values
- short-circuit operators `||`, `&&`, `!`
- `read_cached() || read_from_disk() || read_from_database()`
- `database_value = connection && read_data(connection)`
```
iex(1)> nil
nil
iex(2)> nil == :nil
true
iex(3)> nil || false || 5 || true
5
iex(4)> true && 5
5
iex(5)> false && -1
false
iex(6)> nil && 5
nil
```

## 2.4.1 Numbers

# 2.3 Organizing your code
## 2.3.7 Comments
```
# comments
# This is a comment
a = 3.14 # so is this
```

- `div(5,2)` and `rem(5,2)` for integer division/modulo
- number is BIGNUM?, can use arbitrarily large numbers
- `Small integer` vs `Large integer`
https://www.erlang.org/doc/efficiency_guide/advanced.html

## 2.3.6 Module attributes
```
vim circle.ex
elixirc circle.ex
iex
> Code.fetch_docs(Circle)
> h Circle
> h Circle.area
```
https://hexdocs.pm/ex_doc

### Type Specifications
```
  @spec area(number) :: number
  def area(r), do: r*r*@pi :: number
```

`dialyzer`
https://hexdocs.pm/elixir/typespecs.html
