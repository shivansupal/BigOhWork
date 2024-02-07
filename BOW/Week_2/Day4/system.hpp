class user {
public:
    virtual void addBook(const Book& book) = 0;
    virtual void registerMember(const Member& member) = 0;
    virtual void checkOutBook(int memberId, int bookId) = 0;
    virtual void reserveBook(int memberId, int bookId) = 0;
    
};