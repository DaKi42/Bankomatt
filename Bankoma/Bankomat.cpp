#include "Bankomat.h"
#include <iostream>
#include <string>

using namespace std;

bankmat::bankmat(string address, int balance, int min_nominal, int max_nominal)
    : machine_address(address), machine_balance(balance), min_nominal_value(min_nominal), max_nominal_value(max_nominal), machine_id(0) {}

void bankmat::show_info() const {
    cout << "-----------------------------" << endl;
    cout << "|      ATM Information      |" << endl;
    cout << "-----------------------------" << endl;
    cout << "| Machine Address: " << machine_address << "|" << endl;
    cout << "| Available Funds: " << machine_balance << " UAH|" << endl;
    cout << "| Minimum Bill Denomination: " << min_nominal_value << " UAH|" << endl;
    cout << "| Maximum Bill Denomination: " << max_nominal_value << " UAH|" << endl;
    cout << "-----------------------------" << endl;
}

string bankmat::balance_as_string(int amount) const {
    return to_string(amount);
}

void bankmat::set_machine_id(int new_id) {
    machine_id = new_id;
}

void bankmat::deposit_funds(int amount) {
    bool valid_denomination = false;
    int valid_denominations[] = { 10, 50, 100, 200, 500, 1000 };

    for (int i = 0; i < 6; i++) {
        if (amount == valid_denominations[i]) {
            valid_denomination = true;
            break;
        }
    }

    cout << "-----------------------------" << endl;
    cout << "|       Deposit Funds       |" << endl;
    cout << "-----------------------------" << endl;

    if (valid_denomination) {
        if (machine_balance + amount <= max_nominal_value) {
            machine_balance += amount;
            cout << "| Deposited: " << amount << " UAH ";
            cout << "|" << endl;
            cout << "| Current Balance: " << machine_balance << " UAH ";
            cout << "|" << endl;
            cout << "-----------------------------" << endl;
        }
        else {
            cout << "| The maximum allowable amount of money in the ATM has been exceeded! |" << endl;
            cout << "-----------------------------" << endl;
        }
    }
    else {
        cout << "| Invalid bill denomination. Deposit failed.                       |" << endl;
        cout << "-----------------------------" << endl;
    }
}


int bankmat::withdraw_funds(int amount) {
    if (amount >= min_nominal_value && amount <= max_nominal_value && amount <= machine_balance) {
        bool valid_denomination = false;
        int valid_denominations[] = { 10, 50, 100, 200, 500, 1000 };

        for (int i = 0; i < 6; i++) {
            if (amount == valid_denominations[i]) {
                valid_denomination = true;
                break;
            }
        }

        cout << "-----------------------------" << endl;
        cout << "|    Withdraw Funds         |" << endl;
        cout << "-----------------------------" << endl;

        if (valid_denomination) {
            if (amount % 10 == 0) {
                machine_balance -= amount;
                cout << "| Withdrawn: " << amount << " UAH ";
                cout << "|" << endl;
                cout << "| Current Balance: " << machine_balance << " UAH ";
                cout << "|" << endl;
                cout << "-----------------------------" << endl;
                return amount;
            }
            else {
                cout << "| The amount to be withdrawn must be a multiple of 10 UAH!        |" << endl;
                cout << "-----------------------------" << endl;
                return -1;
            }
        }
        else {
            cout << "| Invalid bill denomination. Unable to withdraw " << amount << " UAH from ATM.  |" << endl;
            cout << "-----------------------------" << endl;
            return -1;
        }
    }
    else {
        cout << "| Unable to withdraw " << amount << " UAH from ATM.                     |" << endl;
        cout << "-----------------------------" << endl;
        return -1;
    }
}
