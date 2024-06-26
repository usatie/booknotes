# 2.7 Understanding the runtime
## 2.7.1 Modules and functions in the runtime
### Module Names and Atoms
- `defmodule Geometry do ... end`
- `Geometry` is an alias that corresponds to `:Elixir.Geometry`
- module names are aliases, aliases are atoms!
- The first time you call the function of a module, BEAM tries to find the corresopnding file on the disk
- in-memory compilation

### Pure Erlang Modules
- `:code.get_path`
- At run time, module names are atoms
```
> Circle.area(10)
> :"Elixir.Circle".area(10)
> Elixir.Circle.area(10)
```

### Dynamically calling functions
- `apply(IO, :puts, ["Dynamic function call."])`
- Kernel.apply/3
- MFA(Module, Function, Arguments)

## 2.7.2 Starting the runtime
### Interactive Shell
- input is interpreted (non byte code, not performant)
- modules are always compiled (byte code!)

### Running scripts
1. The BEAM instance is started.
2. The file is compiled in-memory, and the resulting modules are loaded to the VM.
3. Whatever code resides outside of a module is interpreted
4. Once everything is finished, BEAM is stopped.
```
echo 'IO.puts("Hello world") > my_source.ex
elixir my_source.ex
```
- `.exs` extension is recommended
```
defmodule MyModule do
  def run do
    IO.puts("Called MyModule.run")
  end
end
MyModule.run
```
### The mix tool
```
mix new my_project
cd my_project
mix compile
mix run -e "IO.puts(MyProject.hello())"
mix test
```

# 2.6 Macros
- macros are compile-time code transformers
https://hexdocs.pm/elixir/quote-and-unquote.html

### Special forms
- capture syntax `&(...)`
- `for` comprehension `for`
- `receive` expression
- `try` blocks
https://hexdocs.pm/elixir/Kernel.SpecialForms.html

# 2.5 Operators
https://hexdocs.pm/elixir/operators.html
- `+`, `-`, `*`, `/`
- `===`, `!==` for strict equality/inequality
- `==, `!-` for strict equality/inequality
- `<`, `>`, `<=`, `>=`
- `and`, `or`, `not`
- `||`, `&&`
- `!`
## Q. What is the difference between strict and weak equality?
- Relevant only when comparing floats and integers
```
iex(10)> 1 == 1.0
true
iex(11)> 1 == 1.1
false
iex(12)> 1 == 1.000000000000001
false
iex(13)> 1 == 1.0000000000000001
true
```
## Operator override
```
defmodule WrongMath do
def a +++ b, do: max(a, b)
def a + b, do: a - b
end
> import WrongMath
> import Kernel, except: [+: 2]
> 20 + 2
18
```

# 2.4 Understanding the type system
## 2.4.12 IO lists
- integer in the range of 0 to 255
- a binary
- an IO list
```
iex(10)> iolist = []
[]
iex(11)> iolist = [iolist, "This"]
[[], "This"]
iex(12)> iolist = [iolist, " is"]
[[[], "This"], " is"]
iex(13)> iolist = [iolist, " an"]
[[[[], "This"], " is"], " an"]
iex(14)> iolist = [iolist, " IO list."]
[[[[[], "This"], " is"], " an"], " IO list."]
iex(15)> IO.puts(iolist)
This is an IO list.
:ok
iex(16)> List.flatten(iolist)
["This", " is", " an", " IO list."]
```
```
> IO.puts([72, [<<101, 108, 108>>, "o", [~s( )]], [~c"worl"], 'd'])
Hello world
:ok
```
## 2.4.11 Higher-level types
### Range
- `1..3`
- `1 in 1..3`
- `range = 1..3`
- `Enum.each(1..3, &IO.puts/1)` : 1,2,3
- `Enum.each(1..-3, &IO.puts/1)` : 1,0,-1,-2,-3
- `Enum.each(1..12//3, &IO.puts/1)` : 1,4,7,10
### Keyword Lists
- List of pairs, whose each first element is atom
- `[]` access operator can be used, just like Maps
- `def my_func(arg1, arg2, opts \\ []) do end`
- `my_func(x, y)`
- `my_func(x, y, [width: 1, height: 2])`
- `my_func(x, y, width: 1, height: 2)`
```
days = [{:monday, 1}, {:tuesday, 2}, {:wednesday, 3}]
days = [monday: 1, tuesday: 2, wednesday: 3]
```
### MapSet
- A store of unique values
```
days = MapSet.new([:monday, :tuesday, :wednesday])
MapSet.member?(days, :monday)
MapSet.member?(days, :noday)
days = MapSet.put(days, :thursday)
# Enumerable
Enum.each(days, &IO.puts/1)
```
### Times and Dates
- Date          : ~D[2023-01-31]
- Time          : ~T[11:59:12.000007]
- NaiveDateTime : ~N[2023-01-31 11:59:12.000007]
- Datetime      : ~U[2023-01-31 11:59:12.000007Z]

## 2.4.10 Other built-in types
- reference : `Kernel.make_ref()`
- process identifier(PID)
- port identifier
  - File I/O
  - communication with external programs

## 2.4.9 First-class functions
```
square = fn x ->
  x * x
end
```
- `square = fn x -> x * x end`
- `square.(5)`
- `print_element = fn x -> IO.puts(x) end`
- `print_element = &IO.puts/1`
- `Enum.each([1,2,3], print_element)`
- `Enum.each([1,2,3], fn x -> IO.puts(x) end)`
### lambdas
- `lambda = fn x,y,z -> x * y + z end`
- `lambda = &(&1 * &2 + &3)`
- `* &some_code(&1, ...)` expression must at least contain one argument as &1
### Closures
- The original location for 5 is not garbage-collected because the closure is capturing ti
```
outside_var = 5
my_lambda = fn -> IO.puts(outside_var) end
my_lambda.()
outside_var = 6
my_lambda.()
```

## 2.4.8 Strings
### Binary strings
- `"hello world"`
- `"hello #{3 + 0.14} \n\r\tworld"`
- sigils : `~s(hello world \r\n\t #{3 + 0.14})`
- sigils(ignore interpolation) : `~S(hello world \r\n\t #{3 + 0.14})`
- heredoc
```
"""

hello
world
#{3+0.14}
\n\n\n
"""
```
- concatenation : `"hello" <> " " <> "world"`
- `"ABC"`
- `"ABC"`
- `String.to_charlist("ABC")`

### Character Lists
- `'ABC'`
- `~c"ABC"`
- `[65, 66, 67]`
- `[0x41, 0x42, 0x43]`
- `List.to_string(~c"ABC")`

## 2.4.7 Binaries and bitstrings
- `<<1,2,3>>`
- `<<256>>`
- `<<1,2,3>> <> <<4,5>>`
- `<<1::1>>`
- `<<1::1, 0::1, 1::1>>`

```
iex(1)> <<>>
""
iex(2)> <<1>>
<<1>>
iex(3)> <<1, 2, 3>>
<<1, 2, 3>>
iex(4)> <<1, 2, 3, 256>>
<<1, 2, 3, 0>>
iex(5)> <<1, 2, 3, 256, 257>>
<<1, 2, 3, 0, 1>>
iex(6)> <<1, 2, 3, 256, 257:16>>
** (SyntaxError) invalid syntax found on iex:6:20:
    error: unexpected token: ":" (column 20, code point U+003A)
    │
  6 │ <<1, 2, 3, 256, 257:16>>
    │                    ^
    │
    └─ iex:6:20
    (iex 1.16.2) lib/iex/evaluator.ex:295: IEx.Evaluator.parse_eval_inspect/4
    (iex 1.16.2) lib/iex/evaluator.ex:187: IEx.Evaluator.loop/1
    (iex 1.16.2) lib/iex/evaluator.ex:32: IEx.Evaluator.init/5
    (stdlib 5.2.3) proc_lib.erl:241: :proc_lib.init_p_do_apply/3
iex(6)> <<1, 2, 3, 256, 257::16>>
<<1, 2, 3, 0, 1, 1>>
iex(7)> <<1, 2, 3, 256, 257::16, 511::16>>
<<1, 2, 3, 0, 1, 1, 1, 255>>
iex(8)> <<1, 2, 3, 256, 257::16, 511::16, 1::4>>
<<1, 2, 3, 0, 1, 1, 1, 255, 1::size(4)>>
iex(9)> <<1, 2, 3, 256, 257::16, 511::16, 1::4, 2::2>>
<<1, 2, 3, 0, 1, 1, 1, 255, 6::size(6)>>
iex(10)> <<1, 2, 3, 256, 257::16, 511::16, 1::4, 2::2, 3::2>>
<<1, 2, 3, 0, 1, 1, 1, 255, 27>>
iex(11)> <<1, 2, 3, 256, 257::16, 511::16, 1::4, 2::2, 3::2>> <> <<>>
<<1, 2, 3, 0, 1, 1, 1, 255, 27>>
iex(12)> <<1, 2, 3, 256, 257::16, 511::16, 1::4, 2::2, 3::2>> <> <<1,2,3>>
<<1, 2, 3, 0, 1, 1, 1, 255, 27, 1, 2, 3>>
``
```
iex(1)> <<256>> == <<0>>
true
iex(2)> <<257>> == <<0>>
false
iex(3)> <<257>> == <<0, 1>>
false
iex(4)> <<256, 257>> == <<0, 1>>
true
iex(5)> <<256>> == <<0::4>>
false
iex(6)> <<256>> == <<0::8>>
true
```
## 2.4.6 Maps
- `%{}`
- `squares = %{ 1=>2, 2=>4, 3=>9}`
- `squares = Map.new([{1, 1}, {2, 4}, {3, 9}])`
- `squares[2]`
- `squares[4]`
- `Map.get(squares, 2)`
- `Map.fetch(squares, 4)`
- `Map.fetch!(squares, 4)`
- `Map.put(squares, 4)`

## 2.4.5 Immutability
### Benefits
- side-effect-free functions
  1. easier to analyze
  2. easier to understand
  3. easier to test
- data consistency (atomic operations)
- Q. Do I need something like ` || original_data`?
- A. `try/rescue` or `case` is recommended.
```
# Does this return original_data on error?

def complex_transformation(original_data) do
  original_data
  |> transformation_1(...)
  |> transformation_2(...)
  ...
end
```

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
