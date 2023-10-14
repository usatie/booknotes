# 2.1 JavaScript
# 2.1.1 The World's Most Misunderstood Programming Language
- First class functions and closures
- Flexible object model
- Highly expressive object literal notation

- Lisp in C's Clothing

# 2.1.2 Evolving language
- ES2015 = ES6
- ECMAScript 2022

# 2.2 Declare variables
- Use `const` and `let` instead of `var`
- Problems of `var`
1. `var` can be redeclared
2. Hoisting is allowed for `var`
3. Scope of `var` is function level

- `const` for the first choice
- If you need to reassign, use `let`
- Never use `var`

# 2.3. Data Types
## 2.3.1 Primitive Types
- Non object types
- No instance methods

1. Boolean
2. Number ( 2^53 - 1 )
3. BigInt
4. String
5. Symbol
6. Null
7. Undefined ( different from null )

- Falsy values
    - false
    - 0
    - NaN
    - ''(= empty string)
    - null
- undefined 
## 2.3.2 Primitive Type Literals and Wrapper Objects

## 2.3.3 Object Types

# 2.4 Define Functions
## 2.4.1 Function Declaration and Function Expression
- Statement(instruction) vs Expression(value)
```
// Statement cannot be assigned to a variable
const a = if (true) { 1 } else { 2 } // error
// Expression can be assigned to a variable
const a = true ? 1 : 2 // ok
```
- In Functional Programming, most of syntax are expressions
- Declare Statement has the same problem as `var`
  1. Hoisting
  2. Redeclare
- functions are First-Class Object.
- a function is an instance of embedded `Function` Object.
- assignable, passable, returnable
- In other words, "First-Class Function"
- Function expression is a literal to generate a `Function` object
- A function which is a property of an object is called "Method"

## 2.4.2 Arrow function expression and Anonymous function
- Anonymous functions dissapear right after they are defined unless they are assigned
- Arrow functions are not the same as `function` keyword functions
- 3 ways of defining functions
1. Function Staetment
2. Function Expression
3. Arrow Expression
- In React, arrow functions are favaorable

## 2.4.3 Various expression of parameters
- Default parameters
- Rest parameters (variadic function)
- Spread syntax

# 2.5 Class
## 2.5.1 Class syntax
- Private fields (`#fieldName`)
- Public fields (`fieldName`)
- Constructor can't be written as an arrow function
- `new` to create an instance
- `extends` to inherit a class
- Class is a constructor function
- Constructor function is inheritant of `Prototype Object`
- "JavaScript におけるコンストラクタ関数というのは、プロトタイプオブジェクトを継承してオ ブジェクトインスタンスを生成するための独立した関数のこと"

## 2.5.2 Prototype base Object Oriented Programming
https://developer.mozilla.org/en-US/docs/Glossary/Prototype-based_programming
- Class base vs Prototype base
- The output is different from the book
`console.log('JavaScript'.__proto__)`
// `[String: '']` : Text Book
// `{}` : My environment
- `Array` is constructor function
- `String` is constructor function

# 2.6 Convenient syntax for Array and Object
## 2.6.1 Destructuring Assignment and Spread syntax
- Keys of an object
    - Symbol (`key`)
    - Quoted String (`'key'`)
    - Computed Property Name (`[key]`)
- Shorthand property assignment
- Destructuring assignment
- Spread syntax

## 2.6.2 Object merge and copy
- Object.assign is destructive
- Spread syntax is non-destructive
- Spread syntax is shallow copy
    - To copy deeply, it is necessary to copy recursively
1. `JSON.parse(JSON.stringify(obj))`
    - Date object is not copied
    - Function is not copied
    - undefined is not copied
2. Lodash's `cloneDeep(obj)`
3. rfdc (recursive fast deep clone)
