class Bird {
	// This is a private class field.
	#className = '鳥類';

	// Constructor can't be arrow function.
	constructor(name) {
		this.name = name;
	}

	cry = (sound) => {
		console.log(`${this.name} cried ${sound}!`);
	}

	introduce = () => {
		console.log(`I'm ${this.name} and I'm a ${this.#className} !`);
	}

	static explain = () => {
		console.log('Birds are warm-blooded, egg-laying vertebrates.');
	}
}

class FlyableBird extends Bird {
	constructor(name) {
		super(name);
	}

	fly = () => {
		console.log(`${this.name} is flying!`);
	}
}

Bird.explain();

const penguin = new Bird('Penguin');
penguin.introduce();

const hawk = new FlyableBird('Hawk');
hawk.cry('Peep');
hawk.fly();

console.log(typeof Bird); // function
console.log(penguin.constructor.name); // {}
console.log(penguin.__proto__.constructor.name); // {}
console.log(penguin.__proto__.__proto__.constructor.name); // function


// Prototype
console.log(Object.prototype.toString()); // [object Object]
console.log(hawk.toString()); // [object Object]
Bird.prototype.toString = () => { return `Bird { name: ${this.name} }`; };
console.log(hawk.toString()); // Bird { name: Hawk }

// `function () {}` not equal to `() => {}`
Bird.prototype.toString = function () { return `Bird { name: ${this.name} }`; };
console.log(hawk.toString()); // Bird { name: Hawk }
delete Bird.prototype.toString;
console.log(hawk.toString()); // [object Object]
