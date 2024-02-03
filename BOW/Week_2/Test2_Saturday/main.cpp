#include<bits/stdc++.h>

using namespace std;

#include"person.hpp"
#include"hotel.hpp"
#include"feedback.hpp"
#include"useradmin.hpp"
#include"normaluser.hpp"
#include"hotelagent.hpp"
#include"administration.hpp"

int main() {
    Hotel sampleHotel("Hotel 123", "Ghaziabad", 50, {"Wi-Fi", "Pool", "Restaurant"});

    NormalUser normalUser("Manu", 22, "Male", "manu123", "password", sampleHotel);
    normalUser.registerUser();
    normalUser.searchHotels();
    normalUser.bookRoom();
    normalUser.modifyDetails();

    Feedback normalUserFeedback("Great service!", 4);
    normalUser.provideFeedback(normalUserFeedback);  // User specific functionality

    HotelAgent hotelAgent("Shiva", 21, "Male", "Shiva123", "password", sampleHotel);
    hotelAgent.registerUser();
    hotelAgent.addOrUpdateHotelDetails();
    hotelAgent.searchHotels();  // Hotel Agent-specific functionality


    Administrator admin("Ritesh", 23, "Male", "admin1", "adminPass");
    admin.registerUser();
    admin.approveHotelDetails();
    admin.deleteUserDetails();
    admin.deleteHotelDetails();



    return 0;
}