// Custom decorator to add a new property
function AddNewProperty(propertyName: string, propertyValue: any) {
  return function(target: any) {
    Object.defineProperty(target.prototype, propertyName, {
      value: propertyValue,
      writable: true,
      enumerable: true,
      configurable: true
    });
  };
}

// Example class
@AddNewProperty('newProperty', 'This is a dynamically added property!')
class MyClass {
  // Other class members and methods...
}

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
