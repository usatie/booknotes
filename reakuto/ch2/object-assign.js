const original = { a: 1, b: 2, c: 3 };

const copy = Object.assign({}, original);
console.log(copy); // { a: 1, b: 2, c: 3 }
console.log(copy === original); // false (copy is a new object)

// Object.assign() is destructive.
// A shallow copy is made, so nested objects are still referenced.
const assigned = Object.assign(original, { c: 10, d: 50 }, { d: 100 });
console.log(assigned); // { a: 1, b: 2, c: 10, d: 100 }
console.log(original); // { a: 1, b: 2, c: 10, d: 100 } (it's modified)
