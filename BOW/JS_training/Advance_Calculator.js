/*
      function calculator
      @param : operation, num1 , num2
      @return : int 
*/
function calculator(operation, num1, num2) {

    switch (operation.toLowerCase()) {              //using switch case

      case 'square':  return num1 * num1;           // for squaring the numbers
      break;

      case 'squareroot': return Math.sqrt(num1);    //for square_root
      break;

      case 'log': return Math.log10(num1);          //for finding log10
      break;

      case 'ln': return Math.log(num1);             //for finding log
      break;

      case 'sin': return Math.sin(num1);            //for sine function
      break;

      case 'cos': return Math.cos(num1);            //for cosine function
      break;

      case 'tan': return Math.tan(num1);            //for finding tan
      break;

      case 'power': return Math.pow(num1, num2);     //for finding the power
      break;

      case 'areaofcircle': return Math.PI * Math.pow(num1, 2);   //for finding the area of circle
      break;

      default:

        return 'Invalid operation';   // default condition
    }

}
  
  // Example usage:
  console.log(calculator('square', 5)); // Output: 25
  console.log(calculator('sin', Math.PI / 2)); // Output: 1
  console.log(calculator('power', 2, 3)); // Output: 8
  console.log(calculator('areaofcircle', 4)); // Output: 50.26548245743669