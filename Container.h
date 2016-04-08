//
// Created by root on 2016-04-08.
//

#ifndef ASSIGNMENTA_CONTAINER_H
#define ASSIGNMENTA_CONTAINER_H

#include "Gift.h"

class Container
{
private:
    Gift** cache;
    int nrOfElements;
    int capacity;
public:


    Container();
    Container(const Container&);
    Container& operator=(const Container&);
    virtual ~Container();
    void expandCacheArray(void);

    void newGift(string what, string recipient, int price);

    string getGift_notBought(void)const;

    string getAllBought_Gifts(void)const;

    string getGiftsProposals_forPerson(string)const;

    int getTotalSpentMoney(void)const;

    string getGiftsNotBought_GivenPriceRange(int);

    string get_TotalCost_And_GiftsBoughtForPerson(string)const;

    void rm_GiftProposal(string);

    void rm_BoughtGift(string);

    void change_GiftBoughtStatus(string);

    void change_GiftData(string, string, int, bool );

    string toString_containerData(string[])const;





};


#endif //ASSIGNMENTA_CONTAINER_H
