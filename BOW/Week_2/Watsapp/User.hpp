class User {
public:
    vector<Contact*> contacts;

    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }
};
