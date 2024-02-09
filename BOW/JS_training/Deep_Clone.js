/*
   function deepClone: If object is not object, then return Null
   @param: obj
   @return: obj
*/

function deepClone(obj) {
    if (typeof obj !== 'object' || obj === null) {
        return obj;
    }

    // Creating a new object to store the cloned properties
    const clone = {};

    // Iterate through each property of the object

    for (let key in obj) {

        // Check if the property belongs to the object itself (not from prototype chain)

        if (Object.prototype.hasOwnProperty.call(obj, key)) {

            // If the property is an object, recursively clone it

            if (typeof obj[key] === 'object' && obj[key] !== null) {

                // Recursive call to deepClone function

                clone[key] = deepClone(obj[key]);

            } else {

                // If the property is not an object, assign it directly to the clone

                clone[key] = obj[key];

            }
        }
    }

    return clone;
}

// Example usage:

const originalObj = {
    a: 1,
    b: {
        c: 2,
        d: {
            e: {
                name:"Shivansu",
                address:{
                    city:"Kanpur",
                    state:"Lko"
                }
            }
        }
    }
};


const clonedObj = deepClone(originalObj);
console.log(JSON.stringify(clonedObj)); 

// Modifying the clonedObj should not affect the originalObj

clonedObj.b.d.e.name = "Ritesh";

console.log(JSON.stringify(clonedObj)); 
console.log(JSON.stringify(originalObj)); 