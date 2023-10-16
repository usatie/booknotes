{
	const multiply = (a, b) => a * b;
	console.log(multiply(2, 5)); // 10
}

// Currying
{
	const withMultiple = (n) => {
		return (a) => a * n;
	};
	console.log(withMultiple(2)(5)); // 10
}

// Currying with Arrow Function Expression
{
	const withMultiple = (n) => (a) => a * n;
	console.log(withMultiple(2)(5)); // 10
}

// Partial Application
{
	const withMultiple = (n) => (a) => a * n;
	console.log(withMultiple(3)(5)); // 15

	const triple = withMultiple(3);
	console.log(triple(5)); // 15
}
