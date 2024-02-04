class BookItem {
public:
    int bookItemId;
    int bookId;
    bool available;

    BookItem(int itemId, int id) : bookItemId(itemId), bookId(id), available(true) {}
};


