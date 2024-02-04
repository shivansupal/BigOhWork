#include<bits/stdc++.h>
using namepspace std;

#include"book.hpp"
#include"issue.hpp"
#include"librarymember.hpp"
#include"library.hpp"


int main() {

    Library library;

    // Example: Adding a book and member
    Book book1(1, "Book1 ", "Book2", "Book3", 2023, 101);
    library.addBook(book1);

    LibraryMember member1(1, "Shivansu_Pal");

    library.addMember(member1);

    return 0;
    
}