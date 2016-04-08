//
// Created by root on 2016-04-08.
//

#include "Container.h"

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
    return " ";
}

string Container::getGiftsProposals_forPerson(string) const
{
    return " ";
}

int Container::getTotalSpentMoney(void) const
{
    return 0;
}

string Container::getGiftsNotBought_GivenPriceRange(int i, int end)
{
    return " ";
}

string Container::get_TotalCost_And_GiftsBoughtForPerson(string string1) const {
    return " ";
}

void Container::rm_GiftProposal(string string1)
{

}

void Container::rm_BoughtGift(string string1)
{

}

void Container::change_GiftBoughtStatus(string string1)
{

}

void Container::change_GiftData(string string1, string string2, int i, bool b)
{

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
