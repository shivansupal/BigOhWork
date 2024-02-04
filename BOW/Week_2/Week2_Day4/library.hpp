class Library {
public:
    vector<Book> books;
    vector<BookItem> bookItems;
    vector<LibraryMember> members;

    void addBook(const Book& book) {

        books.push_back(book);

        // Assume adding book items for simplicity

        for (int i = 0; i < 3; ++i) {

            bookItems.emplace_back(bookItems.size() + 1, books.size());

        }
        
    }

    void addMember(const LibraryMember& member) {

        members.push_back(member);

    }

    void checkOutBook(int memberId, int bookItemId) {

        // Check if the book is available and member can check out more books
        // Update book item availability and member's checked-out books

        for (auto& item : bookItems) {

            if (item.bookItemId == bookItemId && item.available) {

                item.available = false;

                members[memberId - 1].checkedOutBooks.push_back(item.bookItemId);

                cout << "Book checked out successfully." << endl;

                return;
        
            }
        }

        cout << "Book not available for checkout." << endl;


    }

    void reserveBook(int memberId, int bookId) {

        // Check if the book is not currently available
        // Update member's reserved books

        for (auto& item : bookItems) {

            if (item.bookId == bookId && item.available) {

                cout << "Book is currently available. No need to reserve." << endl;

                return;

            }
            
        }

        members[memberId - 1].reservedBooks.push_back(bookId);

        cout << "Book reserved successfully." << endl;
    }

    void renewBook(int memberId, int bookId) {

        // Check if the book is checked out to the member
        // Update due date or check-out count

        for (auto& item : bookItems) {
            if (item.bookId == bookId && !item.available) {

                // Additional logic for renewal (e.g., updating due date) can be added

                cout << "Book renewed successfully." << endl;

                return;

            }

        }

        cout << "Book not checked out to the member." << endl;

    }


    void returnBook(int memberId, int bookId) {

        // Update book item availability and member's checked-out books
        // Calculate fines if returned after the due date

        for (auto& item : bookItems) {

            if (item.bookId == bookId && !item.available) {

                item.available = true;

                time_t currentTime = time(nullptr);

                tm* dueDate = localtime(&currentTime);  // Get the current date and time

                dueDate->tm_mday += 10;  // Assuming a 10-day due date for simplicity


                cout << "Book returned successfully." << endl;

                return;

            }

        }

        cout << "Book not checked out to the member." << endl;

    }

};
