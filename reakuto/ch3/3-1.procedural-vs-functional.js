// Procedural way
// 1. Mutable variables
// 2. Statements
// 3. Bottom-up approach
{
	const octuples = [];

	for (let n = 1; n <= 100; n += 1) {
		if (n % 8 === 0) {
			octuples.push(n);
		}
	}

	console.log(octuples);
}

// Functional way
// 1. Immutable variables
// 2. Expressions
// 3. Top-down approach
{
	const range = (start, end) => [...Array(end-start)].map((_, i) => start + i);
	const octuples = range(1, 101).filter(n => n % 8 === 0);
	console.log(octuples);
}
