function Bird(name) {
	const className = 'Bird';
	this.name = name;

	this.cry = function(sound) {
		console.log(`${className} ${this.name} says ${sound}`);
	}

	this.introduce = function() {
		console.log(`I am ${className} ${this.name}`);
	}
	return this;
}

Bird.explain = function() {
	console.log(`This is a bird class`);
};

function FlyableBird(name) {
	Bird.call(this, name);
	this.fly = function() {
		console.log(`${this.name} is flying`);
	};
	return this;
}

FlyableBird.prototype.__proto__ = Bird.prototype;
