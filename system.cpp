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
	cout<<"\nHus hanterare 2016";
	cout<<"\n Tips: efter varje inmatning tryck p\x86 retur-,linefeed- eller radbrytningstangenten.\n";
	cout<<"A: L\x84gga till en ny bostad\n"
<<"B: Presentera alla bost\x84der.\n"
<<"C: Presentera bost\x84der med hyra som understiger angivet v\x84rde.\n"
<<"D: Presentera bost\x84der som uppfyller angivna kriterier n\x84r det g\x84ller bostadstyp och antalet rum\n"
<<"E: Ta bort en bostad givet ID-numret.\n"
<<"F: \x84ndra uppgifter f\x94r en bostad givet ID-numret.\n"
<<"G: Spara alla bost\x84der p\x86 fil d\x84r filnamnet matas in av anv\x84ndaren.\n"
<<"H: L\x84sa alla bost\x84der fr\x86n fil d\x84r filnamnet matas in av anv\x84ndaren.\n"
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
			this->show_All();
			break;
		case 'C':
			this->show_BelowValue();
			break;
		case 'D':
			this->show_type_and_nrOfRooms();
			break;
		case 'E':
			this->rm();
			break;
		case 'F':
			this->change_properties();
			break;
		case 'G':
			this->save_On_File();
			break;
		case 'H':
			this->load_From_File();
			break;
		case 'Q':
			flag = false;
			break;
		};
		fflush(stdin);
	} while (flag);
}
void System::add(void)
{
    string id,address, type;
    int rent, ytaBo, antalrum;
    cout <<"Hyra: ";
    cin >> rent;
    cout <<"BoYta: ";
    cin >> ytaBo;
    cout <<"Antal rum: ";
    cin >> antalrum;
    cout <<"Unik ID: ";
    getline(cin,id);
    cin.ignore();
    cout <<"Adress: ";
    getline(cin,address);
    cin.ignore();
    cout <<"Typ: ";
    getline(cin,type);
    cin.ignore();

	this->instance.add(id,address, type, rent, ytaBo, antalrum);
}
void System::show_All(void)
{
    delete[] this->ptr;
    this->ptr = new string[this->instance.getNrOfElements()];
    this->instance.toString_Data(ptr);
    for (int i = 0; i < this->instance.getNrOfElements() ; ++i)
    {
        cout << this->ptr[i];
    }
}

void System::show_BelowValue(void)
{
    int Belowrent;
    cout <<"Rent: ";
    cin >> Belowrent;
	cout << this->instance.getData_belowGivenRent(Belowrent);
}

void System::show_type_and_nrOfRooms(void)const
{
    string type;
    int nrOfRooms;
    cout <<"Typ: ";
    getline(cin, type);
    cin.ignore();
    cout <<"Antal rum: ";
    cin >> nrOfRooms;
	cout<< this->instance.get_Data_basedOn_TypeAndRoom(type, nrOfRooms);
}

void System::rm(void)
{
    string UID;
    cout <<"Rent: ";
    getline(cin, UID);
    cin.ignore();
	cout<< this->instance.rm(UID);
}

void System::change_properties(void)
{
    string id,address, type;
    int rent, ytaBo, antalrum;
    cout <<"Hyra: ";
    cin >> rent;
    cout <<"BoYta: ";
    cin >> ytaBo;
    cout <<"Antal rum: ";
    cin >> antalrum;
    cout <<"Unik ID: ";
    getline(cin,id);
    cin.ignore();
    cout <<"Adress: ";
    getline(cin,address);
    cin.ignore();
    cout <<"Typ: ";
    getline(cin,type);
    cin.ignore();
    this->instance.change_GiftData(id, address, type, rent, ytaBo, antalrum);
}

void System::save_On_File(void)
{
	string savePath;
	cout << "\nPlats p\x86 h\x86rddisk: ";
	getline(cin, savePath);
    this->instance.saveToFile(savePath);

}

void System::load_From_File(void)
{
	string loadFilePath;
	cout<<"\nPlats p\x86 h\x86rddisk: ";
	getline(cin, loadFilePath);
    this->instance.loadToProgram(loadFilePath);
}




