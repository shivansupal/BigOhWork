#include<bits/stdc++.h>
using namespace std;


// Cash payment
class CashPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processing cash payment: $" << amount << endl;
    }
};