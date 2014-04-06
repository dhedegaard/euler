// npm install big-integer
var bigInt = require('big-integer');

var a = bigInt(1), b = bigInt(0), tmp = bigInt(), i;
for (i = 1;a.toString().length < 1000; i++) {
    tmp = a;
    a = a.plus(b);
    b = tmp;
}
console.log(i);