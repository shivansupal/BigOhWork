#include<bits/stdc++.h>

class ATM {
public:
    Currency currency;

    ATM(const Currency& curr) : currency(curr) {}

    void topUp(int count, int value) {
        currency.addNotes(count);
        cout << "ATM topped up with " << count << " notes of " << value << " INR\n";
    }

    void withdrawCash(int amount) {
        if (!WithdrawalValidator::isValidWithdrawal(currency, amount)) {
            cout << "Error: Insufficient balance or invalid amount\n";
            return;
        }

        WithdrawalService::withdrawCash(currency, amount);
    }
};
