[...Array(3)]; // [undefined, undefined, undefined]
[...Array(3)].map((_, i) => i); // [0, 1, 2]
[...Array(3)].map((_, i) => console.log(`${ i + 1 } times`)); // 1 times, 2 times, 3 times
[...Array(3).keys()]; // [0, 1, 2]
[...Array(3).keys()].map(i => i + 1); // [1, 2, 3]
[...Array(3).keys()].map(i => console.log(`${ i + 1 } times`)); // 1 times, 2 times, 3 times
