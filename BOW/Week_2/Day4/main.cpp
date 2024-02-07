#include <iostream>
#include <vector>
#include <ctime>


using namespace std;


class LibraryRepository : public IRepository {
private:
    vector<Book> books;
    vector<BookItem> bookItems;
    vector<Member> members;
    vector<Transaction> transactions;

public:
    void addBook(const Book& book) override {
        books.push_back(book);
        for (int i = 1; i <= 3; ++i) {
            BookItem item;
            item.copyId = i;
            item.bookId = book.id;
            item.available = true;
            bookItems.push_back(item);
        }
    }

    void registerMember(const Member& member) override {
        members.push_back(member);
    }

    void checkOutBook(int memberId, int bookId) override {
        // Find an available book item
        int bookItemId = getAvailableBookItemId(bookId);

        if (bookItemId != -1) {
            // Update book item status
            for (auto& item : bookItems) {
                if (item.copyId == bookItemId) {
                    item.available = false;
                    break;
                }
            }

            // Update member's checked-out count and create a transaction
            for (auto& member : members) {
                if (member.memberId == memberId) {
                    member.booksCheckedOut++;
                    Transaction transaction;
                    transaction.transactionId = transactions.size() + 1;
                    transaction.memberId = memberId;
                    transaction.bookItemId = bookItemId;
                    transaction.issueDate = time(0);
                    transaction.dueDate = transaction.issueDate + (10 * 24 * 60 * 60); // 10 days due date
                    transaction.returned = false;
                    transaction.reserved = false;
                    transactions.push_back(transaction);
                    break;
                }
            }
        } else {
            cout << "All copies of the book are currently checked out." << endl;
        }
    }

    void reserveBook(int memberId, int bookId) override {
        int bookItemId = getAvailableBookItemId(bookId);

        if (bookItemId != -1) {
            Transaction transaction;
            transaction.transactionId = transactions.size() + 1;
            transaction.memberId = memberId;
            transaction.bookItemId = bookItemId;
            transaction.issueDate = 0;  // Reserved, not issued yet
            transaction.dueDate = 0;
            transaction.returned = false;
            transaction.reserved = true;
            transactions.push_back(transaction);
        } else {
            cout << "All copies of the book are currently checked out." << endl;
        }
    }

private:
    int getAvailableBookItemId(int bookId) {
        for (const auto& item : bookItems) {
            if (item.bookId == bookId && item.available) {
                return item.copyId;
            }
        }
        return -1; // No available copy found
    }
};

int main() {
    // Sample usage of the Library System
    LibraryRepository repository;

    // Adding books to the library
    Book book1{1, "BOOK1", "AB", "Fiction", "1951-07-16", 101};
    repository.addBook(book1);

    Book book2{2, "BOOK2", "CD", "Drama", "1960-07-11", 102};
    repository.addBook(book2);

    // Registering members
    Member member1{1001, "Shivansu", "M1001", 0};
    repository.registerMember(member1);

    // Checking out a book
    repository.checkOutBook(member1.memberId, book1.id);

    // Reserving a book
    repository.reserveBook(member1.memberId, book2.id);

   
    return 0;
}