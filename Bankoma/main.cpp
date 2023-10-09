#include <iostream>
#include <string>
#include "Bankomat.h"
using namespace std;

int main() {
    bankmat atm("Sadovaya 3", 1000, 1, 100);

    atm.show_info();

    int amount_to_withdraw = 50;
    int withdrawn_amount = atm.withdraw_funds(amount_to_withdraw);

    if (withdrawn_amount != -1) {
        cout << "Successfully withdrawn: " << withdrawn_amount << " UAH" << endl;
    }

    int amount_to_deposit = 50;
    atm.deposit_funds(amount_to_deposit);

    atm.show_info();

}