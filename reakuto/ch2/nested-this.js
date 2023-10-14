class Person {
	constructor(name) {
		this.name = name;
	}

	greet() {
		// undefined is passed as `this`
		// because `doIt` is not a method of any object
		// AND 'strict mode' is enabled (which it is by default in classes)
		function doIt() {
			console.log(`Hello I'm ${this.name}`);
		}
		doIt();
	}
}

const minky = new Person('Momo');
minky.greet(); // Hello I'm undefined
