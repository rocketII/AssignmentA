//
// Created by root on 2016-04-08.
//

#include "Container.h"
#include <sstream>
using namespace std;
Container::Container()
{
    this->capacity=2;
    this->cache = new Gift*[this->capacity];
    this->nrOfElements=0;
}

Container::~Container()
{
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        delete this->cache[i];
    }
    delete[] this->cache;
}

void Container::newGift(string string1, string recipient, int price)
{
    if(this->nrOfElements < this->capacity )
    {
        this->cache[this->nrOfElements]= new Gift(string1,recipient, price);
        this->nrOfElements++;
    }
    else
    {
        this->expandCacheArray();
        this->cache[this->nrOfElements]= new Gift(string1,recipient, price);
        this->nrOfElements++;
    }
}

string Container::getGift_notBought(void) const
{
    return " ";
}

string Container::getAllBought_Gifts(void) const
{
    stringstream dd;
    dd<<"\n The Following matches are: ";
    dd<<"\n--------------------------------------------------";
    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getBought() == true)
        {


            dd <<'\n'<<this->cache[i]->toString();
            dd<<"\n--------------------------------------------------";
        }


    }
    return dd.str();
}

string Container::getGiftsProposals_forPerson(string string1) const
{
    stringstream tt;

    tt<<"\n The Following matches are: ";
    tt<<"\n#########################@_*_@####################";

    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getBought() == false && this->cache[i]->getRecipient() == string1)
        {

            tt << this->cache[i]->toString();
            tt<<"\n--------------------------------------------------";

        }


    }

    tt <<"\n#########################@_R_@####################";
    return tt.str() ;
}

int Container::getTotalSpentMoney(void) const
{
    int totz=0;
    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getBought() == true)
        {
            totz += this->cache[i]->getPrice();
        }


    }
    return totz;
}

string Container::getGiftsNotBought_GivenPriceRange(int i, int end)
{
    return " ";
}

string Container::get_TotalCost_And_GiftsBoughtForPerson(string string1) const {
    stringstream tt;
    int totz=0;
    tt<<"\n The Following matches are: ";
    tt<<"\n#########################@_*_@####################";

    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getBought() == true && this->cache[i]->getRecipient() == string1)
        {
            totz += this->cache[i]->getPrice();
            tt << this->cache[i]->toString();
            tt<<"\n--------------------------------------------------";

        }


    }

    tt <<"\nAnd the sum for the above:"<<totz<<"\n#########################@_R_@####################";
    return tt.str() ;
}

void Container::rm_GiftProposal(string string1)
{

}

void Container::rm_BoughtGift(string string1)
{

}

void Container::change_GiftBoughtStatus(string what)
{
    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
           if(this->cache[i]->getWhat() == what)
           {
               if(this->cache[i]->getBought() == false)
               {
                   this->cache[i]->setBought(true);
               }
               else
                   this->cache[i]->setBought(false);
           }

    }
}

void Container::change_GiftData(string what, string recipient, int price, bool bought)
{
    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getWhat() == what)
        {
            this->cache[i]->setWhat(what);
            this->cache[i]->setPrice(price);
            this->cache[i]->setRecipient(recipient);
            this->cache[i]->setBought(bought);
        }

    }
}

Container::Container(const Container &container)
{
    this->capacity= container.capacity;
    this->nrOfElements=container.nrOfElements;
    this->cache = new Gift*[this->capacity];
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        this->cache[i]= new Gift(*(container.cache[i]));
    }
}

Container &Container::operator=(const Container &container)
{
    if(this != &container)
    {

        for (int i = 0; i < this->nrOfElements ; ++i)
        {
            delete this->cache[i];
        }
        delete[] this->cache;

        this->capacity= container.capacity;
        this->nrOfElements=container.nrOfElements;

        this->cache = new Gift*[this->capacity];
        //Deep copy
        for (int i = 0; i < this->nrOfElements ; ++i)
        {
            this->cache[i]= new Gift(*(container.cache[i]));
        }
    }
    return *this;
}

void Container::expandCacheArray(void)
{
    Gift** tmp = new Gift*[this->capacity];
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        tmp[i]= new Gift(*(this->cache[i]));
    }
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        delete this->cache[i];
    }
    delete[] this->cache;

    this->capacity+= 3;

    this->cache = new Gift*[this->capacity];

    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        this->cache[i]= new Gift(*(tmp[i]));
    }
}

void Container::toString_containerData(string array[]) const
{
    for (int i = 0; i < this->getNrOfElements() ; ++i)
    {
        array[i] = this->cache[i]->toString();
    }

}

int Container::getNrOfElements() const
{
    return this->nrOfElements;
}
