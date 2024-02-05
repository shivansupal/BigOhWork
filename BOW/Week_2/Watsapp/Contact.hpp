
class Contact {
public:
    string name;
    vector<Message*> messages;
    Status* status;

    Contact(string _name) : name(_name), status(nullptr) {}

    void sendMessage(Message* message) {
        messages.push_back(message);
    }

    void setStatus(Status* _status) {
        status = _status;
    }
};