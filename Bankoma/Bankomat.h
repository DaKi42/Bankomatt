#pragma once
#include <iostream>
#include <string>

using namespace std;

class bankmat {
    string machine_address;
    int machine_balance;
    int min_nominal_value; 
    int max_nominal_value;
    int machine_id;
    int nominals[6] = { 10, 50, 100, 200, 500, 1000 };

public:
    bankmat() = default;
    bankmat(string address, int balance, int min_nominal, int max_nominal);

    void show_info() const;
    void set_machine_id(int new_id);
    string balance_as_string(int amount) const;
    void deposit_funds(int amount);
    int withdraw_funds(int amount);
};
