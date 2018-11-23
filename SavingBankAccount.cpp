#include "SavingBankAccount.h"
#include <iostream>

SavingsBankAccount::SavingsBankAccount()
{
    minimumBalance=1000;//set the minimumBalance and the balance to 1000 because it's saving account
    balance=1000;
}

void SavingsBankAccount::withdraw(int amount)
{
    if (amount<=balance && amount>minimumBalance)//make sure that he will withdraw in the limits
    {
        balance=balance-amount;
        cout<<"thank you"<<endl;
        cout<<"new balance : "<<getbalance()<<endl;
    }
    else
        cout<<"sorry, this is more than you can withdraw"<<endl;

}

void SavingsBankAccount::deposit(int amount)
{
    if(amount>=100)//he can only add a 100 or more because it's a saving account
    {
        balance+=amount;
        cout<<"thank you"<<endl;
        cout<<"new balance : "<<getbalance()<<"\n";
    }
    else
        cout<<"you must add at least 100 pound"<<endl;
}
