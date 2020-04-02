#include "Client.h"
#include <iostream>

Client::Client() {};
Client::Client(string name,string address,string phoneNumber)
{
    this->name=name;
    this->address=address;
    this->phoneNumber=phoneNumber;

}
void Client::setName(string name)
{
    this->name=name;
}
string Client::getName()
{
    return name;
}
void Client::setAddress(string address)
{
    this->address=address;
}
string Client::getAddress()
{
    return address;
}
void Client::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber=phoneNumber;
}
string Client::getPhoneNumber()
{
    return phoneNumber;
}
