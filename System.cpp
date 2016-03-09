/* 
 * File:   System.cpp
 * Author: RODERIK BAUHN
 *
 * Created on den 5 februari 2016, 18:36
 */
#include "System.h"
#include "CellPhoneHandler.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>


using namespace std;

bool System::menu(void)
{
	
	bool MenuFlag = false;
	char choice = 'A';
	cout <<"init" <<endl;
	
	do
	{
		system("clear");
		cout << "=============================== " << endl;
		cout << "CellPhone System Management DX" << endl;
		cout << "chose the following: " << endl;
		cout <<"Testing" << "A. Add new entry " << endl;
		cout <<"Sorry out of order!" << "B. remove existing entry " << endl;
		cout <<"Sorry out of order!" << "C. change price with %-rate for all phones with price greater than rule " << endl;
		cout <<"Sorry out of order!" << "D. Show all entries " << endl;
		cout << "Sorry out of order!" <<"E. show model with less than x units " << endl;
		cout << "Sorry out of order!" <<"F. Export DB " << endl;
		cout <<"Sorry out of order!" << "G. Import DB " << endl;
		cout << "H. Exit " << endl;
		cout << "=============================== " << endl;
		cout << "Take me to menu Item: " << endl;
		choice= getchar();
		//cin >> choice;
		cin.ignore();
		
		switch(choice)
		{
		case 'A':
			this->inputA();
			break;
		case 'B':
			this->inputB();
			break;
		case 'C':
			this->inputC();
			break;
		case 'D':
			this->inputD();
			break;
		case 'E':
			this->inputE();
			break;
		case 'F':
			this->inputF();
			break;
		case 'G':
			this->inputG();
			break;
		case 'H':
			MenuFlag = true;
			break;
		}
	}while(!MenuFlag);
	return MenuFlag;
}

//CURRENTLY OUT OF ORDER
//use try catch to make sure only legit whole numbers are entered.
bool System::stockLegit(const int stock) const
{
	bool flag = false;
	if(stock < 0)
	{
		throw runtime_error("Make sure you enter only positive integers");
		//används med try catch(){ e.what()}
	}
	else
	{
		flag =true;
	}
	return flag;
    
    
	
}


//uses try catch to check that price is not negative
bool System::priceLegit(const int price)const
{
	bool flag = false;
	if(price < 0)
	{
		throw runtime_error("Make sure you enter only positive integers"); //används med try catch(){ e.what()}
	}
	else
	{
		flag =true;
	}
	return flag;
	
}

//TESTING
//manage input to CellPhoneHandler.
void System::inputA(void)
{
	bool addSuccess=false;
	bool flag_Stock=false;
	bool flag_Price=false;
	int tmpStock= 0;
	int tmpPrice=0;
	std::string tmpModel= "ICANHAZEASTEREGG";
	do{
		cout << "OK! Enter modell name: " << endl;
		getline(cin, tmpModel);
		cin.ignore();
		cout << "And now how many do you have in stock?  " << endl;
		cin >> tmpStock;
		cin.ignore();
		cout << "last question! How much does one unit cost?  " << endl;
		cin >> tmpPrice;
		cin.ignore();
        try {
		flag_Stock=stockLegit(tmpStock);
		flag_Price=priceLegit(tmpPrice);
    
         } catch(exception &e)
        {
		cout << "Error: " << e.what() << endl;
        }
    }while(flag_Stock == false && flag_Price == false);
    addSuccess=this->API.addPhone(tmpModel, tmpStock, tmpPrice);
    if(addSuccess == true)
    {
	    cout << "New entry added" << endl;
    }
    else
    {
	    cout << "Oops! New entry failed, call 0725858376 for support" << endl;
    }
}
//CURRENTLY OUT OF ORDER
void System::inputB(void)
{
	string model;
	bool StatusFlag=false;
	cout << "So! which model do you want erased?" << endl;
	getline(cin, model);
	cin.ignore();
	StatusFlag=this->API.removePhoneByModel(model);
	if(StatusFlag == true)
	{
		cout << "Success in removing your requested item" << endl;
	}
	else
	{
		cout << "Oops! Failed to remove that item. It could not exist or call 0725858376 for support" << endl;
	}
}
//CURRENTLY OUT OF ORDER
void System::inputC(void)
{
	int price = 0;
	float percentage=0.0;
	//char mode;
	bool StatusFlag=false;
	cout << "So! Type the price which all phones greater than shall recive price change " << endl;
	cin >> price;
	cout << "And! what percentage are we applying on the phones? ex: 0.2 for subtract and 1.2 for increment" << endl;
	cin >> percentage;
	cin.ignore();
	StatusFlag=this->API.changePrice(price, percentage);
	if(StatusFlag == true)
	{
		cout << "Success in changing price" << endl;
	}
	else
	{
		cout << "Oops! Failed to change price. Did you input correct values? Or call 0725858376 for support" << endl;
	}
}
//CURRENTLY OUT OF ORDER
void System::inputD()
{
	cout << "contains..." << endl;
	cout << this->API.showAllPhones() << endl;
}
//CURRENTLY OUT OF ORDER
void System::inputE(void)
{
	int units;
	string printMePlz;
	cout << "Enter the stock number where we extract all phones fewer than given number, remember integer:" << endl;
	cin >> units;
	printMePlz=this->API.showAllPhonesInStockLessthanUints(units);
	cout << printMePlz << endl;
	
}
//CURRENTLY OUT OF ORDER
void System::inputF(void)
{
	bool StatusFlag=false;
	string pathToMyFile;
	cout << "Warning!!! We will overwrite data in file if any." <<endl;
	cout << " Make copy if you want.\n Going to save All the data to given destination(we type filepath c:\\windows\\myfile.txt or /home/myUser/myFile.txt)" << endl;
	getline(cin, pathToMyFile);
	cin.ignore();
	StatusFlag=this->API.ExportDb(pathToMyFile);
	if(StatusFlag == true)
	{
		cout << "Saved Successfully to" << pathToMyFile << endl;
	}
	else
	{
		cout << "Oops! Failed to save "<< pathToMyFile <<" Did you input correct values? Or call 0725858376 for support" << endl;
	}
	//export
	
}
//CURRENTLY OUT OF ORDER
void System::inputG(void)
{
	bool StatusFlag=false;
	string pathToMyFile;
	cout << "Going to import All the data from the given destination(we type filepath c:\\windows\\myfile.txt or /home/myUser/myFile.txt)" << endl;
	getline(cin, pathToMyFile);
	cin.ignore();
	StatusFlag=this->API.ExportDb(pathToMyFile);
	if(StatusFlag == true)
	{
		cout << "Imported data Successfully from" << pathToMyFile << endl;
	}
	else
	{
		cout << "Oops! Failed to Import from "<< pathToMyFile <<" Did you input correct values? Or call 0725858376 for support" << endl;
	}
	//import
	
	
}
