let Tom: 'cat' = 'cat';
Tom = 'mouse'; // Error: Type '"mouse"' is not assignable to type '"cat"'.

let Mary: 'Cat' | 'Dog' | 'Rabbit' = 'Cat';
Mary = 'Rabbit'; // OK
Mary = 'Parrot'; // Error: Type '"Parrot"' is not assignable to type '"Cat" | "Dog" | "Rabbit"'.
