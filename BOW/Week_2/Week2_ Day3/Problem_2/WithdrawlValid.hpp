#include<bits/stdc++.h>

//Valid the amount
class WithdrawalValidator {
public:
    static bool isValidWithdrawal(const Currency& currency, int amount) {
        for (const Note& note : currency.notes) {
            if (note.count > 0 && amount >= note.value) {
                int numNotes = amount / note.value;
                if (numNotes <= note.count) {
                    return true;
                }
            }
        }
        return false;
    }
};
