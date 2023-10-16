const arr = [1, 2, 3, 4, 5];

console.log(
	arr.reduce((acc, n) => acc + n, 0), // 15
	arr.sort((a, b) => a > b ? -1 : 1), // [5, 4, 3, 2, 1]
)
