
class LibraryMember {
public:
    int memberId;
    string name;
    vector<int> checkedOutBooks;
    vector<int> reservedBooks;

    LibraryMember(int id, const string& n) : memberId(id), name(n) {}
};