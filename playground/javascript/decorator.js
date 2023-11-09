var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
// Custom decorator to add a new property
function AddNewProperty(propertyName, propertyValue) {
    return function (target) {
        Object.defineProperty(target.prototype, propertyName, {
            value: propertyValue,
            writable: true,
            enumerable: true,
            configurable: true
        });
    };
}
// Example class
let MyClass = class MyClass {
};
MyClass = __decorate([
    AddNewProperty('newProperty', 'This is a dynamically added property!')
], MyClass);
// Creating an instance of the class
const myInstance = new MyClass();
// Accessing the dynamically added property
console.log(myInstance['newProperty']); // Output: This is a dynamically added property!
console.log(myInstance);
/*
function foobar(target: any, propertyKey: string, descriptor: PropertyDescriptor) {
  console.log('foobar');
}

function addGender(target: any) {
  console.log('addGender');
  target.prototype.gender = 'unknown';
}

function addNickname(nickname: string) {
  console.log('addNickname');
  return function (target: any) {
      console.log('addNickname again');
      target.prototype.nickname = nickname;
  };
}

function foo() {
    console.log('foo is called');
    return function (target: any, propertyKey: string, descriptor: PropertyDescriptor) {
        console.log('foo is called again');
        const originalMethod = descriptor.value;
        descriptor.value = function (...args: any[]) {
            console.log('foo');
            originalMethod.apply(this, args);
        }
    };
}

function bar() {
    console.log('bar is called');
    return function (target: any, propertyKey: string, descriptor: PropertyDescriptor) {
        console.log('bar is called again');
        const originalMethod = descriptor.value;
        descriptor.value = function (...args: any[]) {
            console.log('bar');
            originalMethod.apply(this, args);
        }
    };
}

@addGender
@addNickname('Johnny')
class Person {
    constructor() {
        this.first = 'John';
        this.last = 'Doe';
    }
    first: string;
    last: string;

    @foo()
    @bar()
    @foobar
    hello() { console.log(`Hello, my name is ${this.first} ${this.last}`); }
}

console.log('-------------------');
let john = new Person();
console.log('-------------------');
john.hello();
console.log(john);
console.log('-------------------');
*/
