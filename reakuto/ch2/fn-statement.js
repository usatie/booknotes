console.log(fn())

function fn() {
	return `foo`;
}

function fn() {
	return 'bar';
}

console.log(fn.__proto__.constructor.name);
console.log(fn.__proto__.__proto__.constructor.name);

const sum = new Function('n', 'm', 'return n + m');

const add = function (n, m) {
	return n + m;
};

console.log(sum(1, 2));
console.log(add(1, 2));

const foo = {
	bar: 'bar',
	// baz is a method
	baz: function () {
		console.log('I am `baz` method');
	},
};

foo.baz(); // I am `baz` method

// Another way of defining a method
const fuu = {
	bar: 'bar',
	baz() {
		console.log('I am `baz` method');
	},
};
fuu.baz();

// Arrow function expression
const plusOne = function (n) {
	return n + 1;
};

const addOne = (n) => {
	return n + 1;
}

const increment = n => n + 1;

console.log(plusOne(4));
console.log(addOne(4));
console.log(increment(4));

// Anonymous function
function mercury() {}
console.log(mercury.name); // mercury

const f = function mars() {};
console.log(f.name); // mars

console.log((() =>{}).name);

const venus = function() { console.log('I am venus') };
venus();
console.log(venus.name); // the name of the variable

const jupiter = () => { console.log('I am Jupiter!'); };
jupiter();
console.log(jupiter.name);
