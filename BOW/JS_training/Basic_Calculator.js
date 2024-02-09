// JavaScript program for 
// simple mathematical calculations 

let first_Number = 20 ; 
let second_Number = 12 ;

let operation = '*' ;    //Operation we are performing is "+"

/*
    Calculator function
    @param : operation , first_Number , second_Number
    @return : integer or string 

*/
function Calculator ( operation, first_Number, second_Number){

    let result = 0 ;    // result variable for storing the result

    //switch case for multiple operation handling

    switch ( operation ) {                 

        case '+':  result = first_Number + second_Number ;   //for addition
        break; 

        case '-': result = first_Number - second_Number ;    // for subtraction
        break;

        case '*': result = first_Number * second_Number ;    // for multiplication
        break;

        case '/': if(second_Number ==0) result = "Infinity";  // for division

        else {

            result = first_Number / second_Number ;
        }

        break;

        default: 

        result = "Invalid Operation ";        // deafult if operation is invalid

        }

        return result;    //returning the result

}

console.log(Calculator(operation, first_Number, second_Number))

// function calling is performed here