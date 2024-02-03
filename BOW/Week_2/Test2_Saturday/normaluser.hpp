#include<bits/stdc++.h>

class NormalUser : public UserAdmin {
public:
    
    //has-a relationship NormalUser inherting from UserAdmin
    // n is name, a is age, g is gender
    
    NormalUser(const string& n, int a, const string& g, const string& uname, const string& pwd, const Hotel& hotel) : UserAdmin(n, a, g, uname, pwd, hotel) {}

    //OverRiding useradmin
   
    void registerUser() override {
        cout << "Normal User Registration: " << name << " with username " << username << "\n";
    }

    void searchHotels() override {
        cout << "Search Hotels in " << userHotel.location << "\n";
    }

    void bookRoom() override {
        cout << "Book a room at " << userHotel.name << "\n";
    }

     void modifyDetails() override {
        cout << "Modify User Details: " << name << "\n";
    }

    void provideFeedback(const Feedback& feedback) override {
        cout << "Providing Feedback as Normal User: " << feedback.comment << ", Rating: " << feedback.rating << "/5\n";
    }

};
