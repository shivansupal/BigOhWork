#include<bits/stdc++.h>
using namespace std;

class PM : public Minister {
private:
    string aircraft;
    string designatedDriver;

public:
    PM(const string& constituency) : Minister(constituency), aircraft("Aircraft"), designatedDriver("Special Driver") {}

    bool exceedsSpendingLimit() const override {
        // PM spending limit: 1 crore
        return true; 
    }

    friend class Commissioner;
};
