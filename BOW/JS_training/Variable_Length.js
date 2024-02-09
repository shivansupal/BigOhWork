/*
    function calculator
    @param: rest parameter
    @return: 
*/

function calculator(...args) {

    if (args.length < 2) {

      return "Insufficient number of arguments";
      
    }
  
    const [firstOperand, operator, ...restOperands] = args;
  
    let result;
  
    switch (operator) {
      case "+":
        result = restOperands.reduce((acc, operand) => acc + operand, firstOperand);
        break;
      case "-":
        result = restOperands.reduce((acc, operand) => acc - operand, firstOperand);
        break;
      case "*":
        result = restOperands.reduce((acc, operand) => acc * operand, firstOperand);
        break;
      case "/":
        result = restOperands.reduce((acc, operand) => acc / operand, firstOperand);
        break;
      default:
        return "Invalid operator";
    }
  
    return result;
  }
  
  // Example usage
  console.log(calculator(2, "+", 3, 5));  // Output: 10
  console.log(calculator(10, "*", 2));   // Output: 20
  console.log(calculator(8, "-", 4, 2));  // Output: 2
  console.log(calculator(10, "/"));       // Output: "Insufficient number of arguments"
  console.log(calculator(6, "%", 3));      // Output: "Invalid operator"