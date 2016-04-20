//
// Created by root on 2016-04-08.
//

#include "Container.h"
#include <sstream>
using namespace std;
Container::Container()
{
    this->capacity=2;
    this->cache = new House *[this->capacity];
    this->nrOfElements=0;
}

Container::Container(int capacity)
{
    this->capacity=capacity;
    this->cache = new House *[this->capacity];
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
        this->cache[this->nrOfElements]= new House(string1, recipient, price, false);
        this->nrOfElements++;
    }
    else
    {
        this->expandCacheArray();
        this->cache[this->nrOfElements]= new House(string1, recipient, price, false);
        this->nrOfElements++;
    }
}

string Container::getGift_notBought(void) const
{
    stringstream t;

    t<<"\n The Following matches are: ";
    t<<"\n#########################@_*_@####################";

    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getBought() == false)
        {

            t << this->cache[i]->toString();
            t<<"\n--------------------------------------------------";

        }


    }

    t <<"\n#########################@_R_@####################";
    return t.str() ;
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

string Container::getGiftsNotBought_GivenPriceRange(int start, int end)
{
    stringstream tri;

    tri<<"\n The Following matches are: ";
    tri<<"\n#########################@_*_@####################";

    for(int i =0 ; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getBought() == false && (this->cache[i]->getPrice() < end || this->cache[i]->getPrice() == end ) && (this->cache[i]->getPrice() > start || this->cache[i]->getPrice() == start  ))
        {

            tri << this->cache[i]->toString();
            tri<<"\n--------------------------------------------------";

        }


    }

    tri <<"\n#########################@_R_@####################";
    return tri.str() ;
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

string Container::rm_GiftProposal(string string1)
{
    stringstream gg;
    gg << "No matching hit";
    for(int i =0 ; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getWhat() == string1)
        {
            gg.str("");

            delete this->cache[i];
            this->cache[i]= this->cache[this->nrOfElements-1];
            this->nrOfElements--;

        }


    }
    return gg.str();
}

void Container::rm_BoughtGift(string string1)
{
    for(int i =0 ; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getWhat() == string1 && this->cache[i]->getBought() == true)
        {

            delete this->cache[i];
            this->cache[i]= this->cache[this->nrOfElements-1];
            this->nrOfElements--;

        }


    }
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
    this->cache = new House *[this->capacity];
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        this->cache[i]= new House(*(container.cache[i]));
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

        this->cache = new House *[this->capacity];
        //Deep copy
        for (int i = 0; i < this->nrOfElements ; ++i)
        {
            this->cache[i]= new House(*(container.cache[i]));
        }
    }
    return *this;
}

void Container::expandCacheArray(void)
{
    House ** tmp = new House *[this->capacity];
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        tmp[i]= new House(*(this->cache[i]));
    }
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        delete this->cache[i];
    }
    delete[] this->cache;

    this->capacity+= 3;

    this->cache = new House *[this->capacity];

    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        this->cache[i]= new House(*(tmp[i]));
    }
	for (int i = 0; i < this->nrOfElements ; ++i)
    {
        delete tmp[i];
    }
    delete[] tmp;
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