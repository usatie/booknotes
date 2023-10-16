const arr = [4, 8, 2, 6];
console.log(arr);
console.log(
	arr, // Why this arr is also sorted? The evaluation order is from right to left?
	arr.sort((a, b) => a < b ? -1 : 1),
	arr
);
