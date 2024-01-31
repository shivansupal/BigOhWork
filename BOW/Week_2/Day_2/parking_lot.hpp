#include<bits/stdc++.h>
using namespace std;

// Parking Lot class
class ParkingLot {
public:

    vector<ParkingFloor> floors;

    ParkingLot() {
        // Initialize the parking lot with floors and spots
        floors.push_back(ParkingFloor(1, 5.0, 10, 10, 5, 5, 2));
        floors.push_back(ParkingFloor(2, 4.0, 15, 12, 6, 8, 3));
        // Add more floors as needed
    }

    ParkingTicket takeTicket() {
        // Simulate a customer taking a parking ticket
        double initialFee = 0.0; // Initial fee can be calculated based on any initial charges
        return ParkingTicket(initialFee, time(nullptr));
    }

    ParkingSpot assignParkingSpot(const ParkingTicket& ticket) {
        // Simulate assigning a parking spot to a vehicle
        for (auto& floor : floors) {
            if (!floor.isFull()) {
                for (auto& spot : floor.spots) {
                    if (!spot.occupied) {
                        spot.occupied = true;
                        return spot;
                    }
                }
            }
        }
        // If no available spot is found, return a default spot
        return ParkingSpot(-1, ParkingSpot::Compact);
    }

    void processPayment(const ParkingTicket& ticket, Payment& paymentMethod) {
        // Simulate processing payment for a ticket
        double totalFee = calculateTotalFee(ticket);
        paymentMethod.processPayment(totalFee);
    }

    double calculateTotalFee(const ParkingTicket& ticket) const {
        // Simulate calculating the total fee based on the parking duration and hourly rate
        // ...
        return ticket.fee; // Placeholder, replace with actual calculation
    }
};