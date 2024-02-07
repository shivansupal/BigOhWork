/*
      function calculator
      @param : operation, num1 , num2
      @return : int 
*/

function calculator(operation, num1, num2) {

    switch (operation.toLowerCase()) {  //using switch case

      case 'square':  return num1 * num1;
      break;

      case 'squareroot': return Math.sqrt(num1);
      break;

      case 'log': return Math.log10(num1);
      break;

      case 'ln': return Math.log(num1);
      break;

      case 'sin': return Math.sin(num1);
      break;

      case 'cos': return Math.cos(num1);
      break;

      case 'tan': return Math.tan(num1);
      break;

      case 'power': return Math.pow(num1, num2);
      break;

      case 'areaofcircle': return Math.PI * Math.pow(num1, 2);
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