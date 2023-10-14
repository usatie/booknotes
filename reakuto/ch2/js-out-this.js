class Person {
	constructor(name) {
		this.name = name;
	}
};

function greet(eos) {
	console.log(`Hello I'm ${this.name}${eos}`);
}

// `call`
const minky = new Person('Momo');
greet.call(minky, '!'); // Hello I'm Momo!

// `bind`
const boundGreet = greet.bind(minky);
boundGreet('!'); // Hello I'm Momo!

// Add method to object
minky.greet = greet;
minky.greet('!'); // Hello I'm Momo!
