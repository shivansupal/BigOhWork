
class Administrator : public UserAdmin {
public:
    Administrator(const string& n, int a, const string& g, const string& uname, const string& pwd)
        : UserAdmin(n, a, g, uname, pwd, Hotel("", "", 0, {})) {}

    void registerUser() override {
        cout << "Administrator Registration: " << name << " with username " << username << "\n";
    }

    void approveHotelDetails() override {
        cout << "Approving Hotel Details: " << userHotel.name << "\n";
    }

    void deleteUserDetails() override {
        cout << "Deleting User Details: " << name << "\n";
        
    }

    void deleteHotelDetails() override {
        cout << "Deleting Hotel Details: " << userHotel.name << "\n";

    }

    void provideFeedback(const Feedback& feedback) override {
        cout << "Providing Feedback as Administrator: " << feedback.comment << ", Rating: " << feedback.rating << "/5\n";
    }



};
