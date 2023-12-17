// BalanceManager.h
#pragma once

class BalanceManager {
private:
    static double balance;

    BalanceManager() {} // Private constructor to prevent instantiation

public:
    static double getBalance();
    static void updateBalance(double newBalance);
};
