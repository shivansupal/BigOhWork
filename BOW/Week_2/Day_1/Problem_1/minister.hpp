#include<bits/stdc++.h>
using namespace std;

class Minister : public MP {
public:
    Minister(const ::string& constituency) : MP(constituency) {}

    bool exceedsSpendingLimit() const override {
        // Minister spending limit: 10 lakhs
        return true;  
    }
};

