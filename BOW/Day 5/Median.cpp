//driver code

#include<bits/stdc++.h>

using namespace std;

//----------------function to merge and find meedian--------------------------//

float find_median(int first_Array[], int second_Array[], int n1,int n2){
    
    int size= n1+ n2;  //calculating total size
    
    int arr[size];    //new array of size = total =n1+n1
    
    int j=0;       //pointer for storing number in array
    
    for(int i=0;i< n1;i++){
        
        arr[j++]=first_Array[i];  //storing element of first array
    }
    
    for(int i=0;i<n2; i++){
         
        arr[j++]=second_Array[i];   //storing element of second array
    }
    
    
    if(size/2==0) return arr[size/2];  //if size is odd
    
    
    else{
        
        return (arr[size/2]+arr[(size/2)+1])/2;  //if size is even
    }
    
    
}

//-------------------main_function---------------------------------------
int main(){
    
    int n1;   //size of first array
    int n2;   //size of second array
    
    int First_array [ n1 ];    //first array
    int Second_array [ n2 ];   //second array
    
    cout<<"Enter the number of elements in First Array"<<endl;
    
    cin>>n1;   //user input
    
    cout<<"Enter the number of elements in Second Array" <<endl;
    
    cin>>n2;    //user input
    
    for(int i=0; i <n1 ; i++){
        
        cin>>First_array[i];  //taking input from user
        
    }
    
    for(int j=0; j<n2; j++){
        
        cin>>Second_array[j];  //taking input from user
    }
    
    cout<<find_median(First_array, Second_array, n1, n2);  //calling function
    
    
   return 0;
}