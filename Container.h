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
public:
    int getNrOfElements() const;

private:
    int nrOfElements;
    int capacity;
    void expandCacheArray(void);

public:


    Container();
    Container(int capacity);
    Container(const Container&);
    Container& operator=(const Container&);
    virtual ~Container();

    void newGift(string what, string recipient, int price);

    string getGift_notBought(void)const;

    string getAllBought_Gifts(void)const;

    string getGiftsProposals_forPerson(string)const;

    int getTotalSpentMoney(void)const;

    string getGiftsNotBought_GivenPriceRange(int start, int end);

    string get_TotalCost_And_GiftsBoughtForPerson(string)const;

    string rm_GiftProposal(string);

    void rm_BoughtGift(string);

    void change_GiftBoughtStatus(string);

    void change_GiftData(string, string, int, bool);

    void toString_containerData(string array[])const;





};


#endif //ASSIGNMENTA_CONTAINER_H
