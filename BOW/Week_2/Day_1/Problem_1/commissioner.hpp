#include<bits.stdc++.h>
using namespace std;

class Commissioner {
public:
    void canArrest(const MP& member) const {
        if (member.exceedsSpendingLimit()) {
            cout << "Arresting " << member.getConstituency() << " MP." << endl;
        }
        else {
            cout << "No arrest for " << member.getConstituency() << " MP." << endl;
        }
    }

    void canArrest(const Minister& minister, const PM& pm) const {
        if (minister.exceedsSpendingLimit()) {
            cout << "Arresting " << minister.getConstituency() << " Minister with PM's permission." << endl;
        }
        else {
            cout << "No arrest for " << minister.getConstituency() << " Minister." << endl;
        }
    }
};
