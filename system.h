#pragma once
#include "Container.h"
#include<iostream>
#include<string>
using namespace std;
class System
{
private:
	Container instance;
	void add(void);

    void getGift_notBought(void)const;

    void getAllBought_Gifts(void)const;

    void getGiftsProposals_forPerson(void)const;

    void getTotalSpentMoney(void)const;

    void getGiftsNotBought_GivenPriceRange(void);

    void get_TotalCost_And_GiftsBoughtForPerson(void)const;

    void rm_GiftProposal(void);

    void rm_BoughtGift(void);

    void change_GiftBoughtStatus(void);

    void change_GiftData(void);

    void toString_containerData(void)const;
public:
	System(void);
	~System(void);

	void menu(void);
	
};
