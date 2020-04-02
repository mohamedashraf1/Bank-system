#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include "SavingBankAccount.h"

using namespace std;

class Client{
    public:
      Client();
      Client(string name,string address,string phoneNumber);
      void setName(string name);
      string getName();
      void setAddress(string address);
      string getAddress();
      void setPhoneNumber(string phoneNumber);
      string getPhoneNumber();
    private:
        string name,address,phoneNumber;//making the phone Number string because it's too big to be int
};


#endif // CLIENT_H
