#ifndef BANK_H
#define BANK_H
#include <iostream>

using namespace std;

class Bank
{
    public:
        Bank();
        Bank(int balance);
        int getaccountId();
        void setbalance(int balance);
        int getbalance();
        virtual void withdraw(int amount);
        virtual void deposit(int amount);


    protected:
        int balance,accountId;
        static int counter; //i made it static so every time an object created the counter increment
};






#endif // BANK_H
