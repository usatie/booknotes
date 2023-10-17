enum Pet { Cat, Dog, Rabbit };

console.log(Pet.Cat, Pet.Dog, Pet.Rabbit); // 0 1 2

let Tom: Pet = Pet.Cat;
console.log(Tom); // 0

Tom = Pet.Dog;
console.log(Tom); // 1
Tom = 12;
console.log(Tom); // 12 (no error before TypeScript 5.0)
				  // Error in TypeScript 5.0: Type '12' is not assignable to type 'Pet'.
