# Exploring EcmaScript Decorators
https://medium.com/google-developers/exploring-es7-decorators-76ecb65fb841

## The Decorator Pattern
- A Python decorator is a function that takes another function, extending the behavior of the latter function without explicitly modifying it.
- The simplest decorator in Python could look like this:
```
@mydecorator
def myfunc():
    pass
```

## ES2016 Decorators in action
### Decorating a property
```
class Cat {
    meow() { return `${this.name} says Meow!`; }
}
```
