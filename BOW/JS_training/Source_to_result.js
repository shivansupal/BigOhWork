/*  function  convertSourveToResult
    @param: Source object file
    @return: result object file

*/
function convertSourceToResult(sourceArray) {
    
  const resultObject = {};
  
  sourceArray.forEach(item => {

      const { batch_id, ...rest } = item;   //We are using Rest Parameter for Indefinte Arguments
  
      if (!resultObject[batch_id]) {

        resultObject[batch_id] = [];

      }
  
      resultObject[batch_id].push(rest);

    });
  
    return resultObject;
    
  }
  
  // Example usage
  const sourceArray = [
    { batch_id: 1, name: 'Shivansu', contact: '123-456-7890' },
    { batch_id: 2, name: 'Manu', contact: '987-654-3210' },
    { batch_id: 1, name: 'Ritesh', contact: '111-222-3333' },
    { batch_id: 2, name: 'Aditya', contact: '444-555-6666' },
  ];
  
  const resultObject = convertSourceToResult(sourceArray);
  
  console.log(resultObject);