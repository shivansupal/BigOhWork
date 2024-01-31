#include<bits/stdc++.h>
using namespace std;

// Parking Spot class
class ParkingSpot {
public:
    enum SpotType { Compact, Large, Handicapped, Motorcycle, Electric };
    int spotNumber;
    SpotType type;
    bool occupied;

    ParkingSpot(int number, SpotType t) : spotNumber(number), type(t), occupied(false) {}
};