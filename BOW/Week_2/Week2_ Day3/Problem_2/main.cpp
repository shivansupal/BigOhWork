#include <iostream>
#include <vector>
using namespace std;

#include"Note.hpp"
#include"currency.hpp"
#include"WithdrawlValid.hpp"
#include"WithdrawlService.hpp"
#include"ATM.hpp"

int main() {
    Currency initialCurrency{{100, 0}, {200, 0}, {500, 0}, {2000, 0}};
    ATM atm(initialCurrency);

    // Top-up example
    atm.topUp(20, 2000);
    atm.topUp(2, 500);

    // Withdraw examples
    atm.withdrawCash(2300);
    atm.withdrawCash(4100);

    return 0;
}