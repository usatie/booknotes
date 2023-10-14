const foo = 'dummy';
const bar = 'key';
const baz = 1024;
const foobar = 2048;

// Symbol, Quoted String, Computed Property Name
const obj1 = {
	foo: 4,            // quotes can be omitted if the key is valid token
	'foo': 8,          // This will override the previous one
	'<fuu>': 16,
	[bar]: 128,		   // [] for computed property name
	[`_${bar}2`]: 256, // [] can be used with template literal
	baz: baz / 2,
	foobar,            // Shorthand property assignment
};
console.log(obj1);

// Shorthand Property Assignment
const obj2 = { baz };
console.log(obj2);
