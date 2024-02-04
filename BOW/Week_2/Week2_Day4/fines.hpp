#include<bits/stdc++.h>

using namepace std;

class Library{

   string book_name;
   int Book_id;
   string Author;
   string Subject;
   string Publication;
   int Rack_no;

   public:

   Library(string book_name){
      
    this->book_name=book_name;

   }   

   Library(int Book_id){

    this->Book_id= Book_id;
    
   }

   Library(string Author){

    this->Author= Author;

   }

   Library(string Subject){

    this->Subject=Subject;

   }

   Library(string Publication){

    this->Publication=Publication;

   }

   Library(int Rack_no){

    this->Rack_no=Rack_no;

   }

   void print(string book_name, int Book_id, string Author, string Subject, string Publication, string Rack_no){


    cout<<"Book Name is" << book_name;
    cout<<<"Book id is " <<Book_id;
    cout<<"Author "<<Author;
    cout<<"Subject is"<<Subject;
    cout<<"Publication "<< Publication;
    cout<"Rack No is"<<Rack_no;


   }

};

int main(){

    Library L1("S_p",101,"Shivansu Pal", "Fiction","Disha",20);

    L1.print;

    return 0;

}