// BalanceManager.cpp
#include "BalanceManager.h"

double BalanceManager::balance = 10000.0;

double BalanceManager::getBalance() {
    return balance;
}

void BalanceManager::updateBalance(double newBalance) {
    balance = newBalance;
}
