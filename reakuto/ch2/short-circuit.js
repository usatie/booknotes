const hello = undefined || null || 0 || NaN || '' || 'hello';
console.log(hello); // hello

const chao = ' ' && 100 && [] && {} && 'chao';
console.log(chao); // chao

// Short circuit can be used as `if` expression
true && console.log('1.', hello);  // 1. hello
false && console.log('2.', hello); // 
true || console.log('3.', chao);   //
false || console.log('4.', chao);  // 4. chao
