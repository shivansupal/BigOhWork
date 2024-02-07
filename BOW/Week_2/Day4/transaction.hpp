class Transaction {
public:
    int transactionId;
    int memberId;
    int bookItemId;
    time_t issueDate;
    time_t dueDate;
    bool returned;
    bool reserved;
};
