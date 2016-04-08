#include "system.h"


System::System(void)
{
}


System::~System(void)
{
}

void System::menu(void){
	bool flag = false;
    char choice;
	cout<<"A: Add B: change_GiftBoughtStatus C: change gift data D: All bought gift E: Show bought gift in price range F: GiftProposal for person G: Show not bought giifts H: Spent money I:show cost and gifts for person J:rm bought gift K: rm gift proposal L: to string M: Exit "<<endl;
	do
	{
		cout<<"choice"<<endl;
		cin >> choice;
		switch(toupper(choice))
		{
		case 'A':
			this->add();
			break;
		case 'B':
			this->change_GiftBoughtStatus();
			break;
		case 'C':
			this->change_GiftData();
			break;
		case 'D':
			this->getAllBought_Gifts();
			break;
		case 'E':
			this->getGiftsNotBought_GivenPriceRange();
			break;
		case 'F':
			this->getGiftsProposals_forPerson();
			break;
		case 'G':
			this->getGift_notBought();
			break;
		case 'H':
			this->getTotalSpentMoney();
			break;
		case 'I':
			this->get_TotalCost_And_GiftsBoughtForPerson();
			break;
		case 'j':
			this->rm_BoughtGift();
			break;
		case 'K':
			this->rm_GiftProposal();
			break;
		case 'L':
			this->toString_containerData();
			break;
		case 'M':
			flag = true;
			break;
		};
	} while (flag);
}
void System::add(void){
	string what, recipient;
	int price;
	getline(cin, recipient);
	getline(cin, what);
	cin>>price;
	this->instance.newGift(what, recipient, price);
}
void System::getGift_notBought(void)const{
	cout << this->instance.getGift_notBought();
}

void System::getAllBought_Gifts(void)const{
	cout << this->instance.getAllBought_Gifts();
}

void System::getGiftsProposals_forPerson(void)const{
	string name;
	getline(cin, name);
	cout << this->instance.getGiftsProposals_forPerson(name);
}

void System::getTotalSpentMoney(void)const{
	cout << this->instance.getTotalSpentMoney();
}

void System::getGiftsNotBought_GivenPriceRange(void){
	int start, end;
	cout<<" ";
	cin >>start;
	cout<<" ";
	cin>>end;
	cout << this->instance.getGiftsNotBought_GivenPriceRange(start, end);
}

void System::get_TotalCost_And_GiftsBoughtForPerson(void)const{
	string name;
	getline(cin, name);
	cout << this->instance.get_TotalCost_And_GiftsBoughtForPerson(name);
}

void System::rm_GiftProposal(void){
	string what;
	getline(cin, what);
	this->instance.rm_GiftProposal(what);
}

void System::rm_BoughtGift(void){
	string what;
	getline(cin, what);
	this->instance.rm_BoughtGift(what);
}

void System::change_GiftBoughtStatus(void){
	string what;
	getline(cin, what);
	this->instance.change_GiftBoughtStatus(what);
}

void System::change_GiftData(void){
	string recipient, what;
	int price;
	bool mode;
	getline(cin, what);
	getline(cin, recipient);
	cin >> price;
	cin >> mode;
	this->instance.change_GiftData(what, recipient, price, mode);
}

void System::toString_containerData(void)const
{
	string *ptr = new string[this->instance.getNrOfElements()];
	this->instance.toString_containerData(ptr);
	for (int i = 0; i < this->instance.getNrOfElements(); i++)
	{
		cout << ptr[i];
	}
	delete ptr;
}