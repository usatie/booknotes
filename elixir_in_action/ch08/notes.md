# 8. Fault tolerance basics
- The core tool for error handling is concurrency.
- Instead of trying to reduce the number of errors, the priority is to minimize effects of errors and recover from errors automatically.
## 8.1 Run-time errors
### 8.1.1 Error types
Three types of run-time errors:
1. errors
2. exits
3. throws
- `raise/1`: Raise your own error with error string
- If your function explicitly raises an error, you should append the ! character to its name : `File.open!`
- `exit/1`: Deliberately terminates a process with arbitrary term
- `throw/1`: Allow nonlocal returns with arbitrary term
```
spawn(fn -> raise("error string") end)
spawn(fn -> exit(:arbitrary_term) end)
spawn(fn -> throw(:arbitrary_term) end)
```
### 8.1.2 Handling errors
```
try do
catch
  error_type, error_value -> ...
after
  ...
end
```
- error_type will contain an atom :error, :exit, or :throw
```
try_helper = fn fun ->
  try do
    fun.()
    IO.puts("No error.")
  catch type, value ->
    IO.puts("""
      Error
        #{inspect(type)}
        #{inspect(value)}
    """)
  end
end

try_helper.(fn -> raise("Something went wrong") end)
try_helper.(fn -> throw("Thrown value") end)
try_helper.(fn -> exit("I'm done") end)
```
- With try, the return value is the result of the last executed expression, either from the do block or the catch block
- The after clause doesn't affect the result of the entire try expression
```
result = try do
  throw("Thrown value")
catch type, value -> {type, value}
end
{:throw, "Thrown value"}
result
{:throw, "Thrown value"}
```
- Because catch block is a pattern, multiple caluses can be specified
- The after block is useful for cleaning up resources
- `defexception` macro (https://hexdocs.pm/elixir/Kernel.html#defexception/1)
- try documentation (https://hexdocs.pm/elixir/Kernel.SpecialForms.html#try/1)
- Getting Started section (https://elixir-lang.org/getting-started/try-catch-and-rescue.html)
Q. Why rescue is necessary? Isn't catch enough?
- A run-time error has a type, which can be :error, :exit, or :throw
- A run-time error also has a value, which can be any arbitrary term
- If a run-time error sin't handled, the corresponding process will terminate
- Common idiom is to let the process crash and then do something about it
