# 3. Control flow
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