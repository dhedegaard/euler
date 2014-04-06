// npm install big-integer
var bigInt = require('big-integer');

var result = bigInt(2).pow(1000).toString().split('').reduce(function(prev, cur) {
    return parseInt(prev) + parseInt(cur);
});

console.log(result);