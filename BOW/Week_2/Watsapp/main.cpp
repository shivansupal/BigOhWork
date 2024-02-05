#include<bits/stdc++.h>

using namespace std;

#include"Message.hpp"
#include"TextMessage.hpp"
#include"AudioMessage.hpp"
#include"VideoMessage.hpp"
#include"Status.hpp"
#include"TextStatus.hpp"
#include"ImageStatus.hpp"
#include"Contact.hpp"
#include"User.hpp"


int main() {
    User user;

    Contact contact1("Shivansu");
    Contact contact2("Ritesh");

    user.addContact(&contact1);
    user.addContact(&contact2);

    TextMessage textMsg("Hello, Ritesh");
    AudioMessage audioMsg("Video message content");
    VideoMessage videoMsg("Audio message content");

    contact1.sendMessage(&textMsg);
    contact1.sendMessage(&audioMsg);
    contact2.sendMessage(&videoMsg);

    TextStatus textStatus("Going to Noida");
    ImageStatus imageStatus("Exploring Noida", "/image/.jpg");

    contact1.setStatus(&textStatus);
    contact2.setStatus(&imageStatus);

    // Displaying user's contacts and their messages
    for (Contact* contact : user.contacts) {
        cout << "Contact: " << contact->name << endl;
        for (Message* message : contact->messages) {
            cout << " - Message: " << message->content << endl;
        }
        if (contact->status != nullptr) {
            cout << " - Status: " << contact->status->content << endl;
            if (dynamic_cast<ImageStatus*>(contact->status) != nullptr) {
                cout << "   - Image Path: " << dynamic_cast<ImageStatus*>(contact->status)->imagePath << endl;
            }
        }
    }

    return 0;
}