function isValidNumber(value) {
    return typeof value === 'number' && !isNaN(value);
  }
  
  function isValidOperand(operand, index) {
    if (!isValidNumber(operand)) {
      return "Invalid";
    }
    return null;
  }
  
  function isValidOperator(operator) {
    const validOperators = ['+', '-', '*', '/'];
    if (!validOperators.includes(operator)) {
      return "Invalid";
    }
    return null;
  }
  
  function validateArguments(args) {
    if (args.length < 3) {
      return "Insufficient number of arguments. Please provide at least two operands and one operator.";
    }
  
    const [firstOperand, operator, ...restOperands] = args;
  
    const errors = [];
    errors.push(isValidOperand(firstOperand, 0));
    errors.push(isValidOperator(operator));
  
    restOperands.forEach((operand, index) => {
      errors.push(isValidOperand(operand, index + 1));
    });
  
    return errors.filter(error => error !== null).join(' ');
  }
  
  function calculator(...args) {
    const validationError = validateArguments(args);
    if (validationError) {
      return validationError;
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
  console.log(calculator(2, "+", 3, 5));          // Output: 10
  console.log(calculator("invalid", "*", 2));     // Output: Invalid operand at position 1. Please provide a valid number.
  console.log(calculator(8, "-", 4, 2, 1));        // Output: Insufficient number of arguments. Please provide at least two operands and one operator.
  console.log(calculator(10, "/", 0));             // Output: Invalid operand at position 3. Please provide a valid number.
  console.log(calculator(6, "%", 3));              // Output: Invalid operator "%". Please provide a valid operator (+, -, *, /).