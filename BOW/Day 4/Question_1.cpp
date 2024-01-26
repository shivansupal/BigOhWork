//driver code
#include<bits/stdc++.h>

using namespace std;

//function for spiralAntiClockwise traversal

void spiralAntiClockwise(vector<vector<int>>& matrix) {
    
 
    int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        
        // Traversing top row
        
        for (int i = right; i >= left; --i) {
            cout << matrix[top][i] << " ";
        }
        
        top++;
        
        // Traversing left column
        
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][left] << " ";
        }
        
        left++;
        
        // Traversing bottom row
        
        for (int i = left; i <= right; ++i) {
            
            cout << matrix[bottom][i] << " ";
        }
        
        bottom--;

        // Traversing right column
        
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        
        right--;
        
    }
     
}

//function is traversing the matrix clockwise

void generate_clockwise (vector<vector<int>>a, int row, int column){

 int left = 0, right = column-1, top = 0, bottom = row-1;

    while (left <= right && top <= bottom) {

        /* Print the first row from the remaining rows */
        
        for (int i = left; i <= right; ++i) {
            
            cout<<a[top][i]<<" ";
        }
        
        top++;

        /* Print the last column from the remaining columns */
        
        for (int i = top; i <= bottom; ++i) {
            
         cout<<a[i][right]<<" ";
         
        }
        
        right--;
    
        /* Print the last row from the remaining rows */
        if (top <= bottom) { 
            
            for (int i = right; i >= left; --i) {
                
            cout<<a[bottom][i]<<" ";
            
          }
          
          bottom--;
          
        }
    
        /* Print the first column from the remaining columns */
        
        if (left <= right) { for (int i = bottom; i >= top; --i) {
            
            cout<<a[i][left]<<" ";
            
        }
        
        left++;
        
    }
        
}

    
}

//----------------printing matrix element------------------------//

/*void printmatrix_element ( vector<vector<int>>matrix ){
   
   cout<<"Matrix is =" << endl << endl;
    
   for(int i=0 ; i<matrix.size() ; i++){
       
       for(int j=0; j<matrix[i].size() ; j++){
           
           cout<<matrix[i][j]<<" ";
       }
       
       cout<<endl;
   }
    
}*/

//----------------------------main function-------------------------//

int main(){
    
    int row ;   //varibale for storing number of rows;
    int column ;  //variable for storing number of columns;
    
    cout<<"Please Enter the number of Rows = ";
    cin >> row;
    
    cout<< "Please Enter the number of Columns = ";
    cin >> column;
    
    vector<vector<int>>matrix;  //vector for storing matrix;
    
    cout<<"Please Enter the array Elements = "<<" "<< endl << endl;
    
    for(int i = 0; i < row ; i ++){ //loop for rows
    
        vector <int> elements;
        
        
        for( int j = 0; j < column; j++){   //loop for columns
            
            int element;
            
            
            
            cin >> element;   //user input elements
            
            elements.push_back(element);  //pushing elements in 1D vector
            
        }
        
        matrix.push_back(elements);   //pushing elements in 2D vector
        
    }
    
    cout<<endl;
    
    generate_clockwise(matrix, row, column);
    
    cout<<endl<<endl;
    
    spiralAntiClockwise(matrix);
     
   /* printmatrix_element(matrix); 
    */
    
 return 0;
 
}