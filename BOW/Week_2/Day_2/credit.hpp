#include<bits/stdc++.h>
using namespace std;

// Credit card payment
class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        cout << "Processing credit card payment: " << amount << endl;
    }
};
