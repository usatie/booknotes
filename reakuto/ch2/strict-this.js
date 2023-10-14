function Person(name) {
	this.name = name;
	return this;
}

console.log(Person('somebody')); // Person { name: 'somebody' }
console.log(this.name); // Why is this undefined?
// A. Because we are in strict mode. In strict mode, the global object is not
//   eligible for the default binding, so the this is undefined.
console.log(name);
