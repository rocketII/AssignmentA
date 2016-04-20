//
// Created by root on 2016-04-08.
//

#include "Gift.h"
#include <sstream>
int Gift::getPrice() const
{
    return this->price;
}

string Gift::getRecipient() const
{
    return this->recipient;
}

string Gift::getWhat() const
{
    return this->what;
}

void Gift::setPrice(int price)
{
    this->price=price;
}

void Gift::setRecipient(string recipient)
{
    this->recipient= recipient;
}

void Gift::setWhat(string what)
{
    this->what= what;
}
string Gift::toString() const
{
    stringstream rr;
    rr <<"\npresent: "<< this->getWhat() <<"\npris: "<< this->getPrice() << "\nMottagare: "<<this->getRecipient();
    return rr.str() ;
}

bool Gift::getBought(void) const
{
    return this->bought;
}

void Gift::setBought(bool bought)
{
    this->bought=bought;
}
