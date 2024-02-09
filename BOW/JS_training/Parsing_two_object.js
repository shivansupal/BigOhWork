/*
*   function asserObjectsEqual
*   @param: actual, expected, message
*   @return : true or false;
*/
function assertObjectsEqual(actual, expected, message) {
    const actualString = JSON.stringify(actual);
    const expectedString = JSON.stringify(expected);

    if (actualString === expectedString) {
        return "Passed";
    } 
    else {
        return `FAILED Expected ${expectedString}, but got ${actualString}`;
    }
}

// Example usage:

var expected = {foo: 5, bar: 6};
var actual = {foo: 5, bar: 6};
console.log(assertObjectsEqual(actual, expected, 'detects that two objects are equal'));

var expected2 = {foo: 6, bar: 5};
var actual2 = {foo: 5, bar: 6};
console.log(assertObjectsEqual(actual2, expected2, 'detects that two objects are equal'));