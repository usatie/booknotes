var __ = require('underscore');
var a = ['foo', 'bar'];
var b = ['foo'];

console.log(__.difference(a, b));
console.log(__.difference(b, a));
console.log(a.map(s => s.toUpperCase()));
