#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <filesystem>
#include <ctime>

#include "bankaccount.h"

using namespace std;

bankaccount :: bankaccount()
{
    balance = 10000;
}

bankaccount :: ~bankaccount()
{
    std::fstream balance_file;
    balance_file.open("cash_balance.txt", std::fstream::out);
    balance_file << balance;
    balance_file.close();
}

void bankaccount :: set_balance()
{
    std::fstream Balance;
    Balance.open("Balance.txt", std::fstream::in);
    if(!Balance) 
    {
        Balance.open("Balance.txt", std::fstream::in);
        balance = 10000;
        Balance << balance;
        Balance.close();
    }
    else
    {
        Balance >> balance;
        Balance.close();
    }
    return;
}

void bankaccount :: view_acc_balance()
{
    cout << "Total Amount Available in Your Bank Account: " << balance;
    return;
}

void bankaccount :: deposit_money()
{
    double money;
    cout << "Enter the Amount You Would Like to Deposit in Your Account: " << endl;
    cin >> money;
    if(money <= 25000)
    {
        cout << "Total Amount Available in Your Bank Account: " << (balance + money);
        transaction_list("MONEY DEPOSITED", money);
    }
    else 
    {
        cout << "Amount Exceeds $25000. Please Do Multiple Transactions or Try Again the Next Day" << endl;
    }
}

void bankaccount :: withdraw_money()
{   
    double money;
    cout << "Enter the Amount You Would Like to Withdraw From Your Account: " << endl;
    cin >> money;
    if (balance < money)
    {
        cout << "Transaction Failed due to Insufficient Funds" << endl;
    }
    else if (money <= 10000)
    {
        cout << "Total Amount Available in Your Bank Account: " << (balance - money);
    }
    else 
    {
        cout << "Amount Exceeds $10000. Please Do Multiple Transactions or Try Again the Next Day" << endl;
    }
    transaction_list("MONEY WITHDRAWN", money);
}

void bankaccount :: print_history() const
{
    
    fstream file_transaction;
    file_transaction.open("recorded_transactions.txt", fstream::in);
    if(!file_transaction)
    {
        cout << "No Transactions Exist for This Bank Account." << endl;
    }
    else
    {
        cout << left << "\tOccurence" << "\tAmount" << "\tDate" << "\tBalance" << endl;
        while(!file_transaction.eof())
        {
            string alphabhet;
            int cnt = 1;
            while (cnt <= 4)
            {
                if(cnt == 2 || cnt == 4)
                {
                    file_transaction >> alphabhet;
                    cout << "\t" << alphabhet;
                    cnt++;
                }
                else 
                {
                    file_transaction >> alphabhet;
                    cout << "\t" << alphabhet;
                    cnt++;
                }
            }
            cout << endl;
        }
    }
    file_transaction.close();
    return;
}

void bankaccount :: transaction_list(string occured, double money)
{
    char date[11];
    time_t transaction_seconds;
    time(&transaction_seconds);
    // transaction_seconds = time(NULL);

    // struct tm* transaction_time;
    // transaction_time = localtime(&transaction_seconds);
    struct tm* transaction_time = localtime(&transaction_seconds);

    strftime(date, 11, "%m/%d/20%y", transaction_time);
    std::fstream transactions;
    transactions.open("Transaction_History.txt", std::fstream::app);
    if(!transactions)
    {
        transactions.open("Transaction_History.txt", std::fstream::out);
        cout << left << "\tOccurence" << "\tAmount" << "\tDate" << "\tBalance" << endl;
    }
    else 
    {
        cout << "\n" << left << "\tOccurence" << "\tAmount" << "\tDate" << "\tBalance" << endl;
    }
    transactions.close();
    return;
}


