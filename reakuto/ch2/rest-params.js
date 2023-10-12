const showNames = (a, b, ...rest) => {
	console.log(a);
	console.log(b);
	console.log(rest);
};
showNames('John', 'Jane', 'Johnny', 'Jenny', 'Julia');

const showAllArgs = (...args) => {
	console.log(args);
};
showAllArgs('Moon', 'Mercury', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune', 'Pluto');

const sum = (i, ...[j, k, l]) => i + j + k + l;

console.log(sum(1, 2, 3, 4)); // 10
console.log(sum(1, 2, 3));    // NaN
console.log(sum(1, 2));       // NaN
console.log(sum(1));          // NaN
console.log(sum(1, 2, 3, 4, 5, 6)); // 10
