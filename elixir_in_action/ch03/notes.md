# 3. Control flow
## 3.4 Loops and iterations
- The principal looping tool in Elixir is `recursion`
### 3.4.1 Iterating with recursion
- It is very basic recursion
- iex natural_nums.ex
- iex sum_list.ex

### 3.4.2 Tail function calls
- Tail recursion doesn't consume additional memory
- a tail call can also happen in a conditional expression
- `recursion_practice.ex`
- `recursion_practice_tc.ex`

### 3.4.3 Higher-order function
- Enum.map/2
- Enum.filter/2
- Enum.reduce/3
https://hexdocs.pm/elixir/Enum.html
```
Enum.map([1, 2, 3], fn x -> 2 * x end)
Enum.map([1, 2, 3], &(2 * &1))

Enum.filter([1, 2, 3], fn x -> rem(x, 2) == 1 end)
Enum.filter([1, 2, 3], &(rem(&1, 2) == 1))

# var sum = 0;
# [1,2,3].forEach(function(element) {
#   sum += element;
# })
Enum.reduce([1,2,3], 0, fn element, sum -> sum + element end))
```

### 3.4.4 Comprehensions
- Specify the collectable
- Comprehension filter
```
for x <- [1,2,3], do: x*x
for x <- [1,2,3], y <- [1,2,3], do: {x, y, x*y}
for x <- 1..9, y <- 1..9, do: {x, y, x*y}
multiplication_table = for x <- 1..9, y <- 1..9, into: %{}, do: {{x, y}, x*y}
multiplication_table = for x <- 1..9, y <- 1..9, x <= y, into: %{}, do: {{x, y}, x*y}
Map.get(multiplication_table, {7, 6})
Map.get(multiplication_table, {6, 7})
```

### 3.4.5 Streams
```
employees = ["Alice", "Bob", "Charlie"]
Enum.with_index(employees)
employees
|> Enum.with_index()
|> Enum.each(fn {employee, index} -> IO.puts("#{index + 1}. #{employee}") end)

[9, -1, "foo", 25, 49]
|> Stream.filter(&(is_number(&1) and &1 > 0))
|> Stream.map(&{&1, :math.sqrt(&1)})
|> Stream.with_index()
|> Enum.each(fn {{input, result}, index} -> IO.puts("#{index + 1}. sqrt(#{input}) = #{result}") end)

def large_lines!(path) do
  File.stream!(path)
  |> Stream.map(&String.trim_trailing(&1, "\n"))
  |> Enum.filter(&(String.length(&1) > 80))
end
```
#### Infinite Streams
```
natural_numbers = Stream.iterate(1, fn previous -> previous + 1 end)
Enum.take(natural_numbers, 10)

Stream.repeatedly(fn -> IO.gets("> ") end)
|> Stream.map(&String.trim_trailing(&1, "\n"))
|> Enum.take_while(&(&1 != ""))
```
#### Practice Exercises
- `enum_streams_practice.ex`

## 3.3 Conditionals
### 3.3.1 Branchinig with multiclause functions
- All the benefits of pattern matching
- Recursions
- j
```
defmodule TestList do
  def empty?([]), do: true
  def empty?([_|_]), do: false
end

defmodule Polymorphic do
  def double(x) when is_number(x), do: 2 * x
  def double(x) when is_binary(x), do: x <> x
end

Polymorphic.double(3)
Polymorphic.double("hello")

# Recursions
defmodule Fact do
  def fact(0), do: 1
  def fact(n), do: n * fact(n - 1)
end

# Looping
defmodule ListHelper do
  def sum([]), do: 0
  def sum([head | tail]), do: head + sum(tail)
end
```

### 3.3.2 Classical branching expressions
#### if and unless
- Even one-liners
```
if condition, do: something, else: another_thing
Kernel.if(condition, do: something, else: another_thing)
def max(a, b) do
  if a >= b, do: a, else: b
end
```
```
if result != :error, do: send_notification(...)
unless result == :error, do: send_notification(...)
```
#### cond
- Can be thought of as `if-else-if` pattern
```
def call_status(call) do
  cond do
    call.ended_at != nil -> :ended
    call.started_at != nil -> :started
    true -> :pending                     # Equivalent of a default clause
  end
end
```
#### case
- Most suitable if you don't want to define a separate multiclause function
```
case expression do
  pattern_1 -> ...
  pattern_2 -> ...
  ...
  _ -> ...         # The default clause that always matches
end

def max(a, b) do
  case a >= b do
    true -> a
    false -> b
  end
end
```

### 3.3.3 The with expression
- Useful when you need to chain a couple of expressions and return the error of the first expression that fails
- Chaining with `case` is noisy
- Chaining with `with` is clean
```
with {:ok, login} <- {:ok, "alice"},
     {:ok, email} <- {:ok, "some_email"} do
  %{login: login, email: email}
end
```
```
UserExtraction.extract_user(%{})
UserExtraction.extract_user(%{"login" => "Bob"})
UserExtraction.extract_user(%{"login" => "Bob", "email" => "hello"})
UserExtraction.extract_user(%{"login" => "Bob", "email" => "hello", "password" => "some_password"})
```

## 3.2 Matching with functions
- The argument specifiers are patterns
```
defmodule Rectangle do
  def area({a, b}) do
    a * b
  end
end

Rectangle.area {2, 3}
```
### 3.2.1 Multiclause functions
- Multiple definitions of the same function with the same arity
- In the order they're specified in the source code and attempts to match the provided argument specifiers
- The first clause that successfully matches all arguments is executed
- Multiclause function is a single function
- Default clause can be defined in the end
```
defmodule Geometry do
  def area({:rectangle, a, b}) do
    a * b
  end
  def area({:square, a}) do
    a * a
  end
  def area({:circle, a}) do
    a * a * 3.14
  end
  def area(unknown) do
    {:error, {:unknown_shape, unknown}}
  end
end

rectangle = {:rectangle, 4, 5}
square = {:square, 5}
circle = {:circle, 4}

Geometry.area(rectangle)
Geometry.area(circle)
Geometry.area(square)

fun = &Geometry.area/1
fun.(rectangle)
fun.(circle)
fun.(square)
```

### 3.2.2 Guards
- Type order
  - number < atom < reference < fun < port < pid < tuple < map < list < bitstring (binary)
- Comparison operators
- Boolean operators
- Arithmetic operators
- Type-check functions from the Kernel module (is_number/1, is_atom/1, and so on)
- Errors in the guard expression is internally handled, and the guard expression will just return false
```
defmodule TestNum do
  def test(x) when is_number(x) and x < 0 do
    :negative
  end

  def test(x) when x == 0 do
    :zero
  end

  def test(x) when is_number(x) and x > 0 do
    :positive
  end
end
```
### 3.2.3 Multiclause lambdas
- Multiclause lambdas play an important role in conditional runtime branching
```
test_num = fn
  x when is_number(x) and x < 0 -> :negative
  x when x == 0 -> :zero
  x when is_number(x) and x > 0 -> :positive
end
test_num.(1)
test_num.(0)
test_num.(-1)
```

## 3.1 Pattern matching
### 3.1.1 The match operator
- `=` is the match operator
- `person = {"Bob", 25}` is a pattern match
- left side : a pattern
- right side : an expresion that evaluates to an Elixir term
- a variable always matches

### 3.1.2 Matching tuples
- match operation also returns a value
```
{ name, age } = { "Bob", 25 }
{ date, time } = :calendar.local_time()
{ {year, month, day}, time } = :calendar.local_time()
```

### 3.1.3 Matching constants
```
1 = 1
person = {:person, "Bob", 25}
{:person, name, age} = {:person, "Bob", 25}
{:animal, name, age} = {:person, "Bob", 25}
** (MatchError) no match of right hand side value: {:person, "Bob", 25}
    (stdlib 5.2.3) erl_eval.erl:498: :erl_eval.expr/6
    iex:4: (file)
```

### 3.1.4 Variables in patterns
- Q. When is `_date` garbage-collected?
- Q. Is `_` garbage-cllected as soon as possible?
```
{_, time} = :calendar.local_time()
{_date, time} = :calendar.local_time() # anonymous variable
{_, {hour, _, _}} = :calendar.local_time()
{amount, amount, amount} = {127, 127, 127}
{amount, amount, amount} = {127, 127, 1}
expected_name = "Bob"
{^expected_name, _} = {"Alice", 30}
{^expected_name, _} = {"Bob", 30}
person = {^expected_name, _} = {"Bob", 30}
```

### 3.1.5 Matching lists
```
[first, second, third] = [1, 2, 3]
[head | tail] = [1, 2, 3]
[min | _] = Enum.sort([3,2,1])
[^some_value | _] = Enum.sort([3,2,1])
[_ | ^some_value | rest] = [1,2,3,4,5,6,7]
```

### 3.1.6 Matching maps
```
%{name: name, age: age} = %{name: "Bob", age: 25}
%{age: age} = %{name: "Bob", age: 25}
%{name: name, works_at: works_at} = %{name: "Bob", age: 25}
** (MatchError) no match of right hand side value: %{name: "Bob", age: 25}
```

### 3.1.7 Matching bitstrings and binaries
bitstrings : a chunk of bits
binary: a special case of a bitstring that's always aligned to the byte size
```
binary = <<1, 2, 3>>
<<b1, b2, b3>> = <<1, 2, 3 ,4>>
** (MatchError) no match of right hand side value: <<1, 2, 3, 4>>
<<b1, b2, b3>> = <<1, 2, 3>>
<<b1, rest :: binary>> = <<1, 2, 3, 4>>
<< a :: 4, b :: 4>> = <<155>>
<< a:: 1, b :: bitstring>> = <<155>>
```
#### Matching binary strings
```
<< b1, b2, b3 >> = "abc"
<<b1, rest :: binary>> = "Hello world"
<<b1, b2:: 4, rest :: binary>> = "Hello world"
** (MatchError) no match of right hand side value: "Hello world"
<<b1, b2a :: 4, b2b :: 4, rest :: binary>> = "Hello world"
<< a :: 1, b :: bitstring, c :: binary>> = "hello"
error: a binary field without size is only allowed at the end of a binary pattern, at the right side of binary concatenation and never allowed in binary generators.
command = "ping www.example.com"
"ping " <> url = command
hello <> " world" = "hello world"
** (ArgumentError) cannot perform prefix match because the left operand of <> has unknown size. The left operand of <> inside a match should either be a literal binary or an existing variable with the pin operator (such as ^some_var). Got: hello
"hello " <> world = "hello world"

"hello" <> " " <> world = "hello world"
"hello" <> <<b1>> <> world = "hello world"
"hello" <> <<_>> <> world = "hello world"
"hello" <> <<_::3>> <> world = "hello   world"
error: expected <<_::integer-size(3)>> to be a binary but its number of bits is not divisible by 8
"hello" <> <<_::24>> <> world = "hello   world"
```
### 3.1.8 Compound matches
```
[_, {name, _}, _] = [{"bob", 25}, {"Alice", 30}, {"John", 35}]
[_, {("Alice" = name), _}, _] = [{"bob", 25}, {"Alice", 30}, {"John", 35}]
[_, {("Bob" = name), _}, person] = [{"bob", 25}, {"Alice", 30}, {"John", 35}]
** (MatchError) no match of right hand side value: [{"bob", 25}, {"Alice", 30}, {"John", 35}]
a = b = 1 + 3
4
a + b = 1 + 3
error: cannot invoke remote function :erlang.+/2 inside a match
date_time = {_, {15, _, _}} = :calendar.local_time()
date_time = {_, {23, _, _}} = :calendar.local_time()
** (MatchError) no match of right hand side value: {{2024, 5, 13}, {15, 59, 37}}
```
### 3.1.9 General behavior
- `pattern = term`
1. ASSERT your expectations about the right-side term. If these expectations aren't met, an error is raised.
2. BIND some parts of the term to variables from the pattern.
https://hexdocs.pm/elixir/patterns-and-guards.html
```
~c"hello " ++ world = ~c"hello world"
[?h, ?e, ?l, ?l, ?o, ?\s | world2] = ~c"hello world"
```

