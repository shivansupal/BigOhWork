#include<bits/stdc++.h>

class WithdrawalService {
public:
    static void withdrawCash(Currency& currency, int amount) {
        for (Note& note : currency.notes) {
            if (note.count > 0 && amount >= note.value) {
                int numNotes = amount / note.value;
                int withdrawnNotes = min(numNotes, note.count);
                amount -= withdrawnNotes * note.value;
                note.count -= withdrawnNotes;

                cout << " Distribute " << withdrawnNotes << " notes of " << note.value << " INR\n";
            }
        }
    }
};