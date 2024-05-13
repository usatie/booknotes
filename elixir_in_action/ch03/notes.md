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
