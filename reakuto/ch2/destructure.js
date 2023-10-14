const [a, b] = ['foo', 'bar'];
console.log(a); // foo
console.log(b); // bar

const [, n] = [1, 4];
console.log(n); // 4

const [, , i, , j, , , k] = [1, 2, 3, 4, 5, 6, 7];
console.log(i, j, k); // 3 5 undefined

const profile = {name: 'Kanae', age: 24, gender: 'f'};
const {name, age} = profile;
console.log(name, age); // Kanae 24

// Advanced
const response = {
	data: [
		{
			id: 1,
			name: 'Patty Rabbit',
			email: 'patty@maple.town',
		},
		{
			id: 2,
			name: 'Rolley Cocker',
			email: 'rolley@palm.town',
		},
		{
			id: 3,
			name: 'Bobby Bear',
			email: 'bobby@maple.town',
		},
	],
};

// The key name `data` is destructed as `users`
// The default value is `[]`
const { data: users = [] } = response;
console.log(users);
// const { data: users } = { data: [{}, {}, {}] };
// const { 'data': users } = { 'data': [{}, {}, {}] };
