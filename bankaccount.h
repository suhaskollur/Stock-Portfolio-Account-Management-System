#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>

#include "account.h"

using namespace std;

class bankaccount : public account
{
private:
    double balance;

public:
    string file_transactions;
    bankaccount();
    ~bankaccount();
    void set_balance();
    void view_acc_balance();
    void deposit_money();
    void withdraw_money();
    void print_history() const;
    void transaction_list(string occured, double money);
};
#endif