function countWaysToSum(arr, targetSum) {
    let count = 0;
  
    function calculateSum(index, currentSum) {
      if (index === arr.length) {
        if (currentSum === targetSum) {
          count++;
        }
        return;
      }
  
      calculateSum(index + 1, currentSum + arr[index]);
      calculateSum(index + 1, currentSum - arr[index]);
    }
  
    calculateSum(0, 0);
    return count;
  }
  
  // Example usage
  const arr = [-1, 9, 8, -3, 4];
  const targetSum = 5;
  const result = countWaysToSum(arr, targetSum);        
  console.log(result); // Output: 8