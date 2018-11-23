#ifndef SAVINGBANKACCOUNT_H
#define SAVINGBANKACCOUNT_H
#include "Bank.h"

class SavingsBankAccount : public Bank{
    public:
        SavingsBankAccount();
        void setminimumBalance(int minimumBalance);
        int getminimumBalance();
        void withdraw(int amount);
        void deposit(int amount);
    private:
        int minimumBalance;

};
#endif // SAVINGBANKACCOUNT_H
