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

# 2.7 Operators and Expressions for shorter code
## 2.7.1. Short circuit evaluation
- `&&`
- `||`
- `!`
- There are times when you want to `if` as EXPRESSION not statement

## 2.7.2 Nullish coalescing and Optional chaining
- `??`
- `?.`
- `??` behaves similarly to `||`
    - But only when `null` and `undefined`, it returns the right operand
    - '', 0 and other falsy values are not nullish

# 2.8 this
## 2.8.1 What is `this` in JavaScript?
- `this` is a reference to the object of the current execution context
    - there is an exception
- `global` in Node.js
- `window` in browser

## 2.8.2 Four patterns of `this`
### (1) new operator: newly created object
### (2) executed as a method of an object: the object itself (method-this.js)
### (3) Other than the above [non strict mode]: global object (global-this.js)
- Global object is passed as `this` to the function
### (4) Other than the above [strict mode]: undefined (strict-this.js)
- Global object can be easily contaminated
```
function Person(name) {
	this.name = name;
	return this;
}

Person('somebody'); // Person { name: 'somebody' }
this.name
name
```
- To avoid this, use strict mode.
- In strict mode, undefined is passed as `this`
```
function Person(name) {
    'use strict';
	this.name = name;
	return this;
}

Person('somebody'); // Person { name: 'somebody' }
this.name
name
```
- class syntax is automatically strict mode
```
class Foo { constructor() { console.log('`this` is', this); } }
Foo();
new Foo();
```
- globalThis is a new feature of ES2020
```
class Foo { constructor() { 'use strict'; console.log(this); console.log('`this` is', this); } }
Foo();
new Foo();
```

## 2.8.3 The problems of `this` and the solutions
- Arrow function binds `this` in the context when it is declared
- However, `call()` and `bind()` can't change `this` of arrow function
https://stackblitz.com/edit/react-6tvyxi?file=src%2FApp.js
- Only use `this` in class syntax
- In class, other than constructor, use arrow function for methods and internal functions

# 2.9 Modules
## 2.9.1 Three kingdoms of JavaScript Module 
- Before Modules, `<script src="...">` was used.
    - Everything was global
- CommonJS
    - 'require' and 'module.exports'
    - Node.js
    - Browserify ( to use CommonJS in browser )
    - Problem was that CommonJS's synchronous loading was not suitable for browser
- AMD (Asynchronous Module Definition)
    - RequireJS ( to use AMD in browser )
    - Problem was that the syntax was too complicated
- ES Modules
    - `<script type="module">` is used to load ES Modules
        - `import` and `export`
        - Always strict mode
        - top level variables are not global, module local variables
    - Syntax(`import` and `export`) are intuitive
    - static analysis
    - synchronous and asynchronous loading
## 2.9.2 ES Modules `import` and `export`
```package.json
  "type": "module",
```
