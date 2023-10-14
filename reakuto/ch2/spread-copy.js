const original = { a: 1, b: 2, c: 3 };

const copy = { ...original };
console.log(copy);
console.log(copy === original); // false

const assigned = {...original, ...{c: 10, d: 50}, d: 100};
console.log(assigned); // new object ( shallow copy )
console.log(original); // original object


// Shallow Copy
const patty = {
	name: 'Patty Rabbit',
	email: 'patty@maple.town',
	address: { town: 'Maple Town' },
};

const rolley = { ...patty, name: 'Rolley Cocker' };
rolley.email = 'rolley@palm.town';
rolley.address.town = 'Palm Town';

console.log(patty); // address is modified!
