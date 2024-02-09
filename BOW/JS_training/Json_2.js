/* Declare a flatten function that takes 
*  object as parameter and returns the 
*  flatten object */
const flattenObj = (object_1) => {

	//Taking object which stores the final result
	let result = {};

	// loop through the object "object_1"
	for (const index in object_1) {

		if ((typeof object_1[index]) === 'object' && !Array.isArray(object_1[index])) {

			const temp = flattenObj(object_1[index]);

			for (const index2 in temp) {

				// Store temp in result
                
				result[index + '.' + index2] = temp[index2];
			}
		}

		// Else store ob[i] in result directly
		else {

			result[index] = object_1[index];
		}
	}
	return result;
};


// Declare an object
let object_1 = {
	key1: "Value_1",
	key2: "Value_2",
	key3: "Vlaue_3",
	key4: {
		key4One: "Value 4 one",
		key4Two: "Value 4 Two",
		key4Three: "Value 4 Three"
	}
};

console.log(flattenObj(object_1));
