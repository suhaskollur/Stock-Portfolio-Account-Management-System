#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>

using namespace std;

class account
{
protected:
    double balance;

public:
    account();

    virtual ~account();

    void set_balance();
};
#endif