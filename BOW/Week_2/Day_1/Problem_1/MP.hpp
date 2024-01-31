#include <bits/stdc++.h>
using namespace std;

class MP {
protected:
    string winningConstituency;
    string driver;

public:

    MP(const string& constituency) : winningConstituency(constituency), driver("Car") {}

    string getConstituency() const {
        return winningConstituency;
    }

    string getDriver() const {
        return driver;
    }

    virtual bool exceedsSpendingLimit() const {
        return false;
    }
};