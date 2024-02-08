//JS program for bracket traversal


function minBracketReversals(expression) {

    if (expression.length % 2 !== 0) {

      // If the expression length is odd, it can't be balanced

      return -1;
    }
  
    let stack = [];
    let reversals = 0;
  
    for (let char of expression) {
        
      if (char === '{') {

        stack.push(char);

    } else if (char === '}') {

        if (stack.length > 0 && stack[stack.length - 1] === '{') {

          // Match found, pop the opening bracket

          stack.pop();

        }
        else {

        // Reversal needed, push the current closing bracket
          
          stack.push(char);
          reversals++;

        }
    }
}
  
    // Remaining unmatched brackets
    reversals += stack.length / 2;
  
    return stack.length % 2 === 0 ? reversals : -1;
  }
  
  // Example usage
  const input1 = "{{{";
  const output1 = minBracketReversals(input1);
  console.log(output1); // Output: -1
  
  const input2 = "{{{{}}";
  const output2 = minBracketReversals(input2);
  console.log(output2); // Output: 1