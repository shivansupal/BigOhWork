#include<bits/stdc++.h>
using namespace std;

#include "payment.hpp"
#include "cashpayment.hpp"
#include "credit.hpp"
#include "vehicle.hpp"
#include "parking_spot.hpp"
#include "parking_ticket.hpp"
#include "parking_floor.hpp"
#include "parking_lot.hpp"

int main() {
    
    // Example usage of the parking lot system
    ParkingLot parkingLot;

    // Simulate a customer entering and getting a parking ticket

    ParkingTicket ticket = parkingLot.takeTicket();
    cout << "Customer took a parking ticket." << endl;

    // Simulate a customer parking in a spot
    ParkingSpot spot = parkingLot.assignParkingSpot(ticket);

    if (spot.spotNumber != -1) {

        cout << "Customer parked in spot number " << spot.spotNumber << endl;

        // Simulate a customer paying the ticket with cash
        CashPayment cashPayment;
        parkingLot.processPayment(ticket, cashPayment);

    } 

    else {

        cout << "Parking lot is full. No available spots." << endl;
    }



    return 0;
}