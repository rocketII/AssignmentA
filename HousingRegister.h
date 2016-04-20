//
// Created by root on 2016-04-08.
//

#ifndef ASSIGNMENTA_CONTAINER_H
#define ASSIGNMENTA_CONTAINER_H

#include "House.h"

class HousingRegister
{
private:
    House ** cache;
public:
    int getNrOfElements() const;

private:
    int nrOfElements;
    int capacity;
    void expandCacheArray(void);

public:


    HousingRegister();
    HousingRegister(int capacity);
    HousingRegister(const HousingRegister &);
    HousingRegister & operator=(const HousingRegister &);
    virtual ~HousingRegister();

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
