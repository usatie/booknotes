// Spread array
const arr1 = ['a', 'b', 'c'];
const arr2 = [...arr1, 'd', 'e'];
const arr3 = ['Y', 'Z', ...arr2];
console.log(arr2); // [ 'a', 'b', 'c', 'd', 'e' ]
console.log(arr3); // [ 'Y', 'Z', 'a', 'b', 'c', 'd', 'e' ]

// Spread object
const obj1 = { a: 1, b: 2, c: 3, d: 4 };
const obj2 = { ...obj1, d: 99, e: 5 };
console.log(obj2);


// Spread and destructure
const user = {
	id: 1,
	name: 'Patty Rabbit',
	email: 'patty@maple.town',
	age: 8,
};
const { id, ...userWithoutId } = user;
console.log(id);
console.log(userWithoutId);
