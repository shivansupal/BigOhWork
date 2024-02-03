class HotelAgent : public UserAdmin {
public:
    HotelAgent(const string& n, int a, const string& g, const string& uname, const string& pwd, const Hotel& hotel): UserAdmin(n, a, g, uname, pwd, hotel) {}

    void registerUser() override {
        cout << "Hotel Agent Registration: " << name << " with username " << username << "\n";
    }

    void addOrUpdateHotelDetails() override {
        cout << "Adding/Updating Hotel Details: " << userHotel.name << "\n";

    }

    void searchHotels() override {
        cout << "Search Hotels in " << userHotel.location << "\n";
    }

    void provideFeedback(const Feedback& feedback) override {
        cout << "Providing Feedback as Hotel Agent: " << feedback.comment << ", Rating: " << feedback.rating << "/5\n";
    }
};