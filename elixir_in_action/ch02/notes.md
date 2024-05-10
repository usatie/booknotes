## 2.3.7 Comments
```
# comments
# This is a comment
a = 3.14 # so is this
```

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
