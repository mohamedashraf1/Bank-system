#include "Bank.h"
#include <iostream>
#include <fstream>

using namespace std;

int Bank::counter=0;

Bank::Bank()
{
    balance=0;
    counter++;
    accountId=counter;//now every object has a different ID
}

Bank::Bank(int balance)
{

    this->balance=balance;

}

int Bank::getaccountId()
{
    return accountId;
}

void Bank::setbalance(int balance)
{
    this->balance=balance;
}

int Bank::getbalance()
{
    return balance;
}

void Bank::withdraw(int amount)
{
    if (amount<=balance)//make sure that he will withdraw in the limits
    {
        balance-=amount;
        cout<<"thank you"<<endl;
        cout<<"new balance : "<<getbalance();
    }
    else if(amount>balance)
        cout<<"sorry, this is more than you can withdraw"<<endl;

}

void Bank::deposit(int amount)
{
    balance+=amount;
    cout<<"thank you"<<endl;
    cout<<"new balance : "<<getbalance()<<"\n";

}
