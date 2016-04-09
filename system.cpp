#include "system.h"


System::System(void)
{
	this->ptr=new string("maoh");
}


System::~System(void)
{
	delete this->ptr;
}
void System::menutxt(void)const
{
	
	cout<<"\n!!![Tryck Retur tangent(d.v.s. radbrytning)]!!!";
	getchar();
	//system("cls");
	system("clear");
	cout<<"//////////////////////////////////////////////////////////////////////////////////////";
	cout<<"\nPresent hanterare 2016";
	cout<<"\n Tips: efter varje inmatning tryck p\x86 retur-,linefeed- eller radbrytningstangenten.\n";
	cout<<"A: L\x84gga till ett nytt f\x94rslag p\x86 present\n"
<<"B: Flytta ett f\x94rslag p\x86 en present till att bli en inf\x94rskaffad present.\n"
<<"C: \x84ndra uppgifter p\x86 en present.\n" 
<<"D: Se alla presenter som inf\x94rskaffats.\n"
<<"E: Se de presenter som \x84r f\x94rslag och som ligger inom ett visst prisintervall.\n"
<<"F: Se f\x94rslag p\x86 presenter till en viss person givet namnet p\x86 personen.\n"
<<"G: F\x86 se alla presenter som \x84r f\x94rslag,\n"
<<"H: Kunna f\x86 det sammanlagda v\x84rdet av inf\x94rskaffade presenterna.\n" 
<<"I: S\x94k inf\x94rskaffade presenter till en viss person givet namnet p\x86 personen och\n   dessutom den totala kostnaden f\x94r klapparna till denna person.\n" 
<<"J: Ta bort en inf\x94rskaffad present.\n" 
<<"K: Ta bort ett f\x94rslag p\x86 en present.\n" 
<<"L: Se alla presenter.\n" 
<<"M: Exit.\n "<<endl;
}
void System::menu(void){
	bool flag = true;
    char choice;
	
	do
	{
		menutxt();
		cout<<"\nV\x84LJ EN BOKSTAV: "<<endl;
		cin >> choice;
		cin.ignore();
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
			flag = false;
			break;
		};
		fflush(stdin);
	} while (flag == true);
}
void System::add(void){
	cout <<"\nL\x84gga till ett nytt f\x94rslag p\x86 present\n";
	string what, recipient;
	int price;
	cout<<"Mottagare: ";
	getline(cin, recipient);
	cout<<"\n F\x94rslag p\x86 present: ";
	getline(cin, what);
	cout<<"\n Pris: ";
	cin>>price;
	this->instance.newGift(what, recipient, price);
}
void System::getGift_notBought(void)const{
	cout<<"Printing "<<endl;
	cout << this->instance.getGift_notBought();
}

void System::getAllBought_Gifts(void)const{
	cout<<"\n Alla k\x94pta presenter:\n ";
	cout << this->instance.getAllBought_Gifts();
}

void System::getGiftsProposals_forPerson(void)const{
	string name;
	cout<<"\n Mottagare: ";
	getline(cin, name);
	cout << this->instance.getGiftsProposals_forPerson(name);
}

void System::getTotalSpentMoney(void)const{
	cout<<"\n Du har k\x94pt presenter f\x94r: ";
	cout << this->instance.getTotalSpentMoney();
}

void System::getGiftsNotBought_GivenPriceRange(void){
	int start, end;
	cout<<"\n Prisintervall start: ";
	cin >>start;
	cout<<"\n Prisintervall stopp: ";
	cin>>end;
	cout << this->instance.getGiftsNotBought_GivenPriceRange(start, end);
}

void System::get_TotalCost_And_GiftsBoughtForPerson(void)const{
	string name;
	cout<<"\n Mottagere: ";
	getline(cin, name);
	cout << this->instance.get_TotalCost_And_GiftsBoughtForPerson(name);
}

void System::rm_GiftProposal(void){
	string what;
	cout<<"\n Ok\x94pt Present att ta bort(kopior inkl.): ";
	getline(cin, what);
	this->instance.rm_GiftProposal(what);
}

void System::rm_BoughtGift(void){
	string what;
	cout<<"\n K\x94pt present att ta bort(kopior inkl.): ";
	cin.ignore();
	getline(cin, what);
	this->instance.rm_BoughtGift(what);
}

void System::change_GiftBoughtStatus(void){
	string what;
	cout<<"\n Ange present(\x84ndra k\x94p status p\x86 kopior ocks\x86): ";
	getline(cin, what);
	this->instance.change_GiftBoughtStatus(what);
}

void System::change_GiftData(void){
	string recipient, what;
	char cache ='n';
	int price;
	bool mode;
	cout<<"\n\x84ndra data\nPresent: ";
	getline(cin, what);
	cout<<"\nMottagare: ";
	getline(cin, recipient);
	cout<<"\nPris: ";
	cin >> price;
	cout<<"\n K\x94pt?(y/n): ";
	cin >> cache;
	if( tolower(cache)== 'y')
	{
		mode=true;
	}
	if(tolower(cache)=='n')
	{
		mode=false;
	}
	else
	{
		cout<<"\n Ett annat v\x84rde angavs. Standard v\x84rde \'n\' anv\x84nds.";
		mode=false;
	}
	this->instance.change_GiftData(what, recipient, price, mode);

}

void System::toString_containerData(void)
{
	delete this->ptr;
	cout<<"\n Skriver till sk\x84rm all data.............";
	this->ptr = new string[this->instance.getNrOfElements()];
	this->instance.toString_containerData(ptr);
	for (int i = 0; i < this->instance.getNrOfElements(); i++)
	{
		cout << ptr[i];
	}
	
}