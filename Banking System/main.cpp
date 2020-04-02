#include <iostream>
#include "Bank.h"
#include "SavingBankAccount.h"
#include "Client.h"
#include "BankingApplication.h"

using namespace std;

int main()
{
    /*
    to run the program all you have to do is to create an object from BankingApplication
    and call the function menu
    */
    BankingApplication m;
    m.menu();
    return 0;
}
