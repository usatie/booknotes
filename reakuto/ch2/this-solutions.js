class Person {
	constructor(name) {
		this.name = name;
	}

	greet1() {
		function doIt() {
			console.log(`1) Hi, I'm ${this.name}`);
		}
		const boudDoIt = doIt.bind(this); // 1. bind instance's `this` to doIt
		boudDoIt();
	}

	greet2() {
		function doIt() {
			console.log(`2) Hi, I'm ${this.name}`);
		}
		doIt.call(this); // 2. call doIt with instance's `this`
	}

	greet3() {
		const _this = this; // 3. Assign instance's `this` to a variable
		function doIt() {
			console.log(`3) Hi, I'm ${_this.name}`);
		};
		doIt();
	}

	greet4() {
		const doIt = () => { // 4. Use arrow function
			console.log(`4) Hi, I'm ${this.name}`);
		};
		doIt();
	}

	greet5 = () => { // 5. Use arrow function for method of itself
		const doIt = () => {
			console.log(`5) Hi, I'm ${this.name}`);
		}
		doIt();
	}
}

const creamy = new Person('Mami');
creamy.greet1();
creamy.greet2();
creamy.greet3();
creamy.greet4();
creamy.greet5();

const doIt = () => {
	console.log(`6) Hi, I'm ${this.name}`);
}
doIt();
doIt.call(creamy); // Arrow function's `this` is not bindable
