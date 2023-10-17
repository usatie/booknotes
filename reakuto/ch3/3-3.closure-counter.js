/*
const counter = () => {
	let count = 0;
	const countUp = () => {
		return count += 1;
	};
	return countUp;
}
*/

const counter = (count = 0) => (adds = 1) => count += adds;
