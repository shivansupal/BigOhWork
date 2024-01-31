#include<bits/stdc++.h>
using namespace std;

// Parking Ticket class
class ParkingTicket {
public:
    double fee;
    time_t entryTime;
    time_t exitTime;

    ParkingTicket(double fee, time_t entryTime) : fee(fee), entryTime(entryTime), exitTime(0) {}
};