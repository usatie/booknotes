# 2.4 Understanding the type system
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
