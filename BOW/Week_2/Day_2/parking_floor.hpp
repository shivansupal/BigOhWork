#include<bits/stdc++.h>
using namespace std;


// Parking Floor class
class ParkingFloor {
public:
    int floorNumber;
    double hourlyRate;
    vector<ParkingSpot> spots;

    ParkingFloor(int number, double rate, int compactSpots, int largeSpots, int handicappedSpots,
                 int motorcycleSpots, int electricSpots)
        : floorNumber(number), hourlyRate(rate) {
        for (int i = 0; i < compactSpots; ++i) spots.push_back(ParkingSpot(i + 1, ParkingSpot::Compact));
        for (int i = 0; i < largeSpots; ++i) spots.push_back(ParkingSpot(i + 1, ParkingSpot::Large));
        for (int i = 0; i < handicappedSpots; ++i) spots.push_back(ParkingSpot(i + 1, ParkingSpot::Handicapped));
        for (int i = 0; i < motorcycleSpots; ++i) spots.push_back(ParkingSpot(i + 1, ParkingSpot::Motorcycle));
        for (int i = 0; i < electricSpots; ++i) spots.push_back(ParkingSpot(i + 1, ParkingSpot::Electric));
    }

    bool isFull() const {
        for (const auto& spot : spots) {
            if (!spot.occupied) return false;
        }
        return true;
    }
};

