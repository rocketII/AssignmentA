#include "system.h"


System::System(void)
{
	this->ptr=new string[1];
}


System::~System(void)
{
	delete[] this->ptr;
}
void System::menutxt(void)const
{
	//\x94 = ö ,\x84 = ä \x86=å
	cout<<"\n!!![Tryck Retur tangent(d.v.s. radbrytning)]!!!";
	getchar();
	//system("cls");
	system("clear");
	cout<<"//////////////////////////////////////////////////////////////////////////////////////";
	cout<<"\nPresent hanterare 2016";
	cout<<"\n Tips: efter varje inmatning tryck p\x86 retur-,linefeed- eller radbrytningstangenten.\n";
	cout<<"A: Lägga till en ny bostad\n"
<<"B: Presentera alla bostäder.\n"
<<"C: Presentera bostäder med hyra som understiger angivet värde.\n"
<<"D: Presentera bostäder som uppfyller angivna kriterier när det gäller bostadstyp och antalet rum\n"
<<"E: Ta bort en bostad givet ID-numret.\n"
<<"F: Ändra uppgifter för en bostad givet ID-numret.\n"
<<"G: Spara alla bostäder på fil där filnamnet matas in av användaren.\n"
<<"H: Läsa alla bostäder från fil där filnamnet matas in av användaren.\n"
<<"Q: Exit.\n "<<endl;
}
void System::menu(void)
{
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
			this;
			break;
		case 'C':
			this;
			break;
		case 'D':
			this->show_BelowValue();
			break;
		case 'E':
			this->change_properties();
			break;
		case 'F':
			this->show_type_and_nrOfRooms();
			break;
		case 'G':
			this->show_All();
			break;
		case 'H':
			this->rm();
			break;
		case 'Q':
			this->save_On_File();
			break;
		};
		fflush(stdin);
	} while (flag == true);
}
void System::add(void)
{
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
void System::show_All(void)const
{
	cout<<"Printing "<<endl;
	cout << this->instance.getGift_notBought();
}

void System::show_BelowValue(void)const
{
	cout<<"\n Alla k\x94pta presenter:\n ";
	cout << this->instance.getAllBought_Gifts();
}

void System::show_type_and_nrOfRooms(void)const
{
	string name;
	cout<<"\n Mottagare: ";
	getline(cin, name);
	cout << this->instance.getGiftsProposals_forPerson(name);
}

void System::rm(void)const
{
	cout<<"\n Du har k\x94pt presenter f\x94r: ";
	cout << this->instance.getTotalSpentMoney();
}

void System::change_properties(void)
{
	int start, end;
	cout<<"\n Prisintervall start: ";
	cin >>start;
	cout<<"\n Prisintervall stopp: ";
	cin>>end;
	cout << this->instance.getGiftsNotBought_GivenPriceRange(start, end);
}

void System::save_On_File(void)const
{
	string savePath;
	cout << "\nPlats på hårddisk: ";
	getline(cin, savePath);

}

void System::load_From_File(void)
{
	string loadFilePath;
	cout<<"\nPlats på hårddisk: ";
	getline(cin, loadFilePath);

}




