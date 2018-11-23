#include "BankingApplication.h"
#include "Client.h"
#include "Bank.h"
#include "SavingBankAccount.h"
#include <iostream>
#include <fstream>

using namespace std;

BankingApplication::BankingApplication() {}

void BankingApplication::menu()
{
    int choice;
    cout<<"Welcome to FCI Banking Application and Information \n"
        <<"1. Create a New Account \n"
        <<"2. List Clients and Accounts \n"
        <<"3. Withdraw Money \n"
        <<"4. Deposit Money \n"
        <<"or ctr+z to end the program \n";
    cin>>choice;
    if(choice==1)
    {
        string name,address,phoneNumber;
        Client person;//create a client object to save the basics data
        cout<<"Enter client name : ";
        cin>>name;
        person.setName(name);
        cout<<"Enter client address : ";
        cin>>address;
        person.setAddress(address);
        cout<<"Enter client phone number : ";
        cin>>phoneNumber;
        person.setPhoneNumber(phoneNumber);

        int choice2;
        cout<<"What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 : ";
        cin>>choice2;
        if (choice2==1)
        {
            Bank account;//create a normal account because he choose to
            int balance;
            cout<<"Please Enter the Starting Balance : ";
            cin>>balance;
            account.setbalance(balance);
            cout<<"an account was created with ID : "<<account.getaccountId()<<" and starting balance "<<account.getbalance()<<"L.E. \n \n"<<endl;
            ofstream information("information.txt",ios::app);//saving his data in a file
            information<<person.getName()<<" "<<person.getAddress()<<" "<<person.getPhoneNumber()<<" "<<account.getaccountId()<<" "<<account.getbalance()<<" "<<choice2;
            information.close();
        }
        else
        {
            SavingsBankAccount account;//create a saving account because he choose to
            cout<<"an account was created with ID : "<<account.getaccountId()<<" and starting balance "<<account.getbalance()<<"L.E. \n \n"<<endl;
            ofstream information("information.txt",ios::app);//saving his data in a file
            information<<person.getName()<<" "<<person.getAddress()<<" "<<person.getPhoneNumber()<<" "<<account.getaccountId()<<" "<<account.getbalance()<<" "<<choice2;
            information.close();
        }
    }
    else if(choice==2)
    {
        ifstream read("information.txt");
        string name,address,phoneNumber;
        int id,choice2;
        double balance;
        while(read>>name>>address>>phoneNumber>>id>>balance>>choice2)//loop in the file and save the data in variables to display it
        {
            if (choice2==1)//distinguish between the basic account and the saving account
                cout<<"client name : "<<name<<"\n"<<"client address : "<<address<<"\n"<<"client phone number : "<<phoneNumber<<"\n"<<"client ID : "<<id<<"\n"<<"client balance : "<<balance<<"\n"<<"account type : basic \n \n";
            else
                cout<<"client name : "<<name<<"\n"<<"client address : "<<address<<"\n"<<"client phone number : "<<phoneNumber<<"\n"<<"client ID : "<<id<<"\n"<<"client balance : "<<balance<<"\n"<<"account type : saving \n \n";
        }
    }
    else if(choice==3)
    {
        string name,address;
        int balance,id,idFile,choice2,mobilPhone;
        cout<<"Enter Account ID : ";
        cin>>id;
        ifstream read("information.txt");
        while(read>>name>>address>>mobilPhone>>idFile>>balance>>choice2)//loop in the file and save the data in variables
        {
            if(id==idFile)//compare the input ID to the one in the file
            {
                cout<<"Account ID : "<<id<<"\n"<<"balance : "<<balance<<endl;
                if (choice2==1)//thats mean that he has a basic account
                {
                    Bank user(balance);
                    int withdraw;
                    cout<<"Please Enter The Amount to Withdraw : ";
                    cin>>withdraw;
                    user.withdraw(withdraw);
                    ofstream information("information.txt");//editing the file with the new information
                    information<<name<<" "<<address<<" \n"<<mobilPhone<<"\n "<<id<<"\n "<<user.getbalance()<<" \n"<<choice2;
                    information.close();

                }
                if (choice2==2)//thats mean that he has a saving account
                {
                    SavingsBankAccount user2;
                    int withdraw;
                    cout<<"Please Enter The Amount to Withdraw : ";
                    cin>>withdraw;
                    user2.withdraw(withdraw);
                    ofstream information("information.txt");//editing the file with the new information
                    information<<name<<" "<<address<<" \n"<<mobilPhone<<"\n "<<id<<"\n "<<user2.getbalance()<<" \n"<<choice2;
                    information.close();

                }

            }
        }
    }


    else if(choice==4)//same as the withdraw but we use function deposit instead
    {
        string name,address;
        int balance,id,idFile,choice2,mobilPhone;
        cout<<"Enter Account ID : ";
        cin>>id;
        ifstream read("information.txt");
        while(read>>name>>address>>mobilPhone>>idFile>>balance>>choice2)//loop in the file and save the data in variables
        {
            if(id==idFile)
            {
                cout<<"Account ID : "<<id<<"\n"<<"balance : "<<balance<<endl;
                if (choice2==1)
                {
                    Bank user(balance);
                    int deposit;
                    cout<<"Please Enter The Amount to deposit : ";
                    cin>>deposit;
                    user.deposit(deposit);
                    ofstream information("information.txt");
                    information<<name<<" "<<address<<" \n"<<mobilPhone<<"\n "<<id<<"\n "<<user.getbalance()<<" \n"<<choice2;
                    information.close();

                }
                if (choice2==2)
                {
                    SavingsBankAccount user;
                    int deposit;
                    cout<<"Please Enter The Amount to deposit : ";
                    cin>>deposit;
                    user.deposit(deposit);
                    ofstream information("information.txt");
                    information<<name<<" "<<address<<" \n"<<mobilPhone<<"\n "<<id<<"\n "<<user.getbalance()<<" \n"<<choice2;
                    information.close();

                }

            }
        }
    }

}
