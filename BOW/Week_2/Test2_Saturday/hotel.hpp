
class Hotel {
public:
    string name;
    string location;
    int numRooms;
    vector<string> facilities;

    Hotel(const string& n, const string& loc, int rooms, const vector<string>& fac): name(n), location(loc), numRooms(rooms), facilities(fac) {}

    
};