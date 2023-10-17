if (true) {
	const he = 'Kakeru';
	const saveHim = () => {
		console.log(`${he} is alive!`);
	};
}
// `he` is already freed

let friendship;
if (true) {
	const he = 'Kakeru';
	const saveHim = () => {
		console.log(`${he} is alive!`);
	};
	friendship = saveHim; // This makes `he` alive
}
// `he` is still alive
