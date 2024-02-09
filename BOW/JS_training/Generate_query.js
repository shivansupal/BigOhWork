/*
*   function generateQueryString
*   @param: Object and url
*   @return: queryString
*/
function generateQueryString(obj, url) {
    let queryString = url;
    let hasQueryString = url.includes('?');
    for (let key in obj) {

        if (Object.hasOwnProperty.call(obj, key)) {
            if (!hasQueryString) {

                queryString += `?${encodeURIComponent(key)}=${encodeURIComponent(obj[key])}`;

                hasQueryString=true;

            }
            else {

                queryString += `&${encodeURIComponent(key)}=${encodeURIComponent(obj[key])}`;
            }
        }
    }

    return queryString;
}

// Example usage:
const obj = {
    "keyOne": "value One",
    "keyTwo": "value Two",
    "keyThree": "value Three",
};

const url = "https://localhost:400";

const queryStringURL = generateQueryString(obj, url);
console.log(queryStringURL);