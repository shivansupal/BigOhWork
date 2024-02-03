class UserAdmin : public Person {
public:
    string username;
    string password;
    Hotel userHotel;

    UserAdmin(const string& n, int a, const string& g, const string& uname, const string& pwd, const Hotel& hotel) : Person(n, a, g), username(uname), password(pwd), userHotel(hotel) {}

    virtual void registerUser() {
        cout << "User Registration: " << name << " with username " << username << "\n";
    }

    virtual void searchHotels() {
        cout << "Searching Hotels in " << userHotel.location << "\n";
    }
    

    virtual void bookRoom() {
        cout << "Booking a room at " << userHotel.name << "\n";
    }

    virtual void modifyDetails() {
        cout << "Modifying User Details: " << name << "\n";
    }

    virtual void addOrUpdateHotelDetails() {
        cout << "Not applicable for normal user\n";
    }

    virtual void approveHotelDetails() {
        cout << "Not applicable for normal user\n";
    }

    virtual void deleteUserDetails() {
        cout << "Not applicable for normal user\n";
    }

    virtual void deleteHotelDetails() {
        cout << "Not applicable for normal user\n";
    }

    virtual void provideFeedback(const Feedback& feedback) {
        cout << "Providing Feedback: " << feedback.comment << ", Rating: " << feedback.rating << "/5\n";
    }
};
