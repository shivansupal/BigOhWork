
class Book {
public:
    int bookId;
    string title;
    string author;
    string subject;
    int publicationYear;
    int rackNumber;

    Book(int id, const string& t, const string& a, const string& s, int year, int rack)
        : bookId(id), title(t), author(a), subject(s),publicationYear(year), rackNumber(rack) {}
};