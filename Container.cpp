//
// Created by root on 2016-04-08.
//

#include "Container.h"

Container::Container()
{
    this->capacity=1;
    this->cache = new Gift*[1];
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

string Container::getGiftsNotBought_GivenPriceRange(int i)
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

}

Container &Container::operator=(const Container &container)
{
    return *this;
}

void Container::expandCacheArray(void)
{
    ;
}
