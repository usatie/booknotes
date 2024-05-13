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
