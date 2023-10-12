'Serval lives in savanna'.replace('savanna', 'jungle');

console.log(true);
console.log(false);
console.log(36);
console.log(-9);
console.log(0x10); // hex
console.log(0o10); // octal
console.log(0b10); // binary
console.log(3.14);
console.log(2.1e8);
console.log(1_000_000);
console.log(100n); // BigInt
console.log('JavaScript');
console.log("ECMAScript");
const year = 2021;
console.log(`ECMAScript ${year}
is the latest version of JavaScript.
`);
console.log(Symbol('symbol'));
console.log(null); // null is a literal for the null type
console.log(undefined); // undefined is a global variable whose value is undefined

// Wrapper Object
const s1 = 'JavaScript';
const s2 = new String('JavaScript');
console.log(typeof s1); // string
console.log(typeof s2); // object
console.log(s1 === s2); // false
console.log(s1 === s2.valueOf()); // true

'Serval lives in savanna'.replace('savanna', 'jungle'); // This line is internally translated
(new String('Serval lives in savanna')).replace('savanna', 'jungle'); // to this line

// 2.3.3 Object Types and literals
console.log([1, 2, 3]);
const symbol = Symbol('foo');
console.log(symbol === Symbol('foo')); // false
console.log({
	name: 'Serval',
	age: 3,
	42: 'meaning of life', // Number is converted to string
	symbol: 'symbol', // Symbol can be used as a key
	'key with spaces': 'can be used as a key',
}
);
console.log(/pattern/s); // Regular expression literal `/pattern/flags`

// Literals are similar to Embedded Objects' constructors
const arr1 = [1, 2, 3];
const arr2 = new Array(1, 2, 3);
console.log(arr1, arr2);

const obj1 = { 'key': 'value' } ;
const obj2 = new Object({ 'key': 'value' });
console.log(obj1, obj2);

const regexp1 = /pattern/i;
const regexp2 = new RegExp('pattern', 'i');
console.log(regexp1, regexp2);

// Underlying type
console.log("Object");
console.log(obj1.constructor);
console.log(obj1.__proto__.constructor);
console.log("Array");
console.log(arr1.constructor);
console.log(arr1.__proto__.constructor);
console.log(arr1.__proto__.__proto__.constructor);
console.log("RegExp");
console.log(regexp1.constructor);
console.log(regexp1.__proto__.constructor);
console.log(regexp1.__proto__.__proto__.constructor);
