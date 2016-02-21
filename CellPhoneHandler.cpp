
#include "CellPhoneHandler.h"
#include <sstream>
#include <string>
#include <fstream>
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
using namespace std;

CellPhoneHandler::CellPhoneHandler()
{
	//create default array with pointers to default objects of CellPhoneClass
	this->bridge = new CellPhone*[5];
	
	
	
	
}

CellPhoneHandler::~CellPhoneHandler()
{
	if(this->bridge != NULL)
	{
		for(int i=0; i < this->sizeArray; i++)
		{
			delete this->bridge[i];
		}
		delete [] this->bridge;
		
	}
	if(this->myStringPtrUsed == true)
	{
		delete []  this->myStringPtr;
	}
}

//creates an array of pointers to objects. 
//And there are two arrays not related which is the case with default copy construct.
CellPhoneHandler::CellPhoneHandler(const CellPhoneHandler &origin)
{
	
	this->sizeArray=origin.sizeArray;
	
	this->bridge = new CellPhone*[origin.sizeArray];
	
	for(int i =0; this->sizeArray; i++)
	{ 
		this->bridge[i]=new CellPhone(*origin.bridge[i]);
		
	}
}

CellPhoneHandler& CellPhoneHandler::operator =(CellPhoneHandler& origin)
{
	//orgin and this pointer cannot have the same address if the assigment event are to occour.
	if(this != &origin)
	{
		//deep copy.
		
		//make sure target and Source has the same size.
		this->sizeArray = origin.sizeArray;
		
		for(int i=0; i < origin.sizeArray; i++)
		{
			//empty target on object pointer by freeing memory heap.
			for(int i=0; i < this->sizeArray; i++)
			{
				delete this->bridge[i];
			}
			//Dealloc memory of array.
			
			delete [] this->bridge; //you can create freeMemory() to save work.
			
			//the target then creates an new array filled with object pointers!!!
			
	 		this->bridge= new CellPhone*[origin.sizeArray] ;              //makecopy()
			
			//ofc! We must fill the array with pointer objects that orgin has.
			
	 		for(int i =0; this->sizeArray; i++)
	 		{
	 			this->bridge[i]=new CellPhone(*origin.bridge[i]);
	 		}
			
		}
	}
	return *this;
}
//An array with enoug space for all the data are sent here and filled with each object data in CellPhone Class.
string CellPhoneHandler::AllTheDataStored2Array(string* myStringPtr, int nrOfPhones, bool myStringPtrUsed ) const
{
	myStringPtr = new string[nrOfPhones];
	
	//keep track so destructor can delete without SEGMENTATION fault
	
	myStringPtrUsed=true;
	
	stringstream ss;
	
	for(int i = 0; i < this->sizeArray; i++)
	{
		
		myStringPtr[i] =(string) this->bridge[i]->toString();
	}
	
	for(int i = 0; i < this->sizeArray; i++)
	{
		
		ss << myStringPtr[i]; 
	}
	
	return ss.str();
	
	
}

int CellPhoneHandler::howManyPhones( void)const
{
	//current keep track of cellphones
	
	return this->current;
	
	//myString is an pointer to the first element in the array.
	
}
//we open up an file stream that can write to given file in that destination on localhost.
//we write to an binary file the so called "save file". Data are in structure so that we can easily import it later with this software.
bool CellPhoneHandler::ExportDb(string filepathWithFileName) const
{
	bool flag = false;
	
	int nrOfPhones=0;
	
	ofstream  exportMe(filepathWithFileName.c_str(), ios::in | ios::binary);
	
	exportMe << this->sizeArray << endl;
	
	nrOfPhones=howManyPhones();
	
	for(int i= 0; i < this->sizeArray; i++)
	{
		exportMe << this->AllTheDataStored2Array(this->myStringPtr, nrOfPhones, this->myStringPtrUsed);
		
		this->IOdbgOfstream(exportMe);
	}
	
	
	exportMe.close();
	
	flag = exportMe.fail();
	
	return flag;
}

bool CellPhoneHandler::ImportDb(string filepathWithFileName)
{
	bool flag = false;
	
	bool eof=false;
	
	bool fail=false;
	
	bool bad=false;
	
	bool good=false;
	
	char peekingAt;
	
	string tmp_string;
	
	ifstream  importMe;
	
	importMe.open(filepathWithFileName.c_str(), ios::out | ios::binary);
	
	this->IOdbgIfstream(importMe);
	//this->sizeArray= (int) getline(importMe,tmp_string, '\n');
	//beginning of file contain sizeArray otherwise things are out of order. the sizeArray is used to create array with object pointers.
	//then the object contents InStock followed by model followed by price. That makes one object
	
	peekingAt= importMe.peek();
	
	if(isdigit(peekingAt))
	{
		//read on line until whitespace.
		importMe >> this->sizeArray;
		
		this->IOdbgIfstream(importMe);
	} 
	this->bridge= new CellPhone*[this->sizeArray];
	
	for(int i= 0; i < this->sizeArray; i++)
	{
		int tmp_Stock, tmp_Price;
		
		string tmp_model;
		importMe >> tmp_Stock;
		
		this->IOdbgIfstream(importMe);
		
		this->bridge[i]->setStock(tmp_Stock);
		getline(importMe, tmp_model, '\n');
		
		this->IOdbgIfstream(importMe);
		
		this->bridge[i]->setModel(tmp_model);
		importMe >> tmp_Price;
		
		this->IOdbgIfstream(importMe);
		
		this->bridge[i]->setPrice(tmp_Price);
	}
	
	importMe.clear();
	
	importMe.close();
	
	return flag;
}

bool CellPhoneHandler::removePhoneByModel(string model)
{
	//walkthrough the array with pointers to objects and look for matching model name
	///if it exist overite it with last place element data and delete last place in array then shrink the array
	bool flag = false;
	
	for(int i=0; i < this->sizeArray; i++)
	{
		if(this->bridge[i]->getModel()==model)
		{
			this->bridge[i]->setModel(this->bridge[this->sizeArray-1]->getModel());
			
			this->bridge[i]->setPrice(this->bridge[this->sizeArray-1]->getPrice());
			
			this->bridge[i]->setStock(this->bridge[this->sizeArray-1]->getStock());
			
			//deallocate memory for the pointer object
			
			delete this->bridge[this->sizeArray-1];
			
			//Shrink array on element
			
			this->sizeArray--;
			
			this->current--;
			
			flag=true;
		}
	}
	
	return flag;
}

bool CellPhoneHandler::addPhone(string model, int InStock, int price)
{
	bool flag = false;
	
	if( this->current < this->sizeArray)
	{
		this->bridge[this->sizeArray++] = new CellPhone(model, InStock, price);
		
		flag=true;
		
		this->current++;
	}
	//expand array by create tmp and then assign CellPhone pointers. 
	//destroy old one and recreate with bigger size. 
	//And copy from tmp array.
	if(this->current > this->sizeArray-1)
	{
		CellPhone **tmp_bridge;
		
		tmp_bridge = new CellPhone*[this->sizeArray+5];
		
		for(int i=0; i < this->sizeArray; i++)
		{
			tmp_bridge[i] = this->bridge[i];
		}
		
		for(int i=0; i < this->sizeArray; i++)
		{
			delete this->bridge[i];
		}
		delete [] bridge;
		
		this->bridge = new CellPhone*[sizeArray+5];
		
		for(int i=0; i < this->sizeArray; i++)
		{
			this->bridge[i] = tmp_bridge[i];
		}
		
		this->sizeArray+=5;
		
		
	}
	
	return flag;
}
bool CellPhoneHandler::changePrice(int forPriceGreaterThan, float percentage)
{
	for(int i=0; i < this->sizeArray; i++ )
	{
		if(this->bridge[i]->getPrice() > forPriceGreaterThan )
		{
// pris - pris*procent för rabatt. pris + pris*procent för ökning.
			this->bridge[i]->setPrice(this->bridge[i]->getPrice - (this->bridge[i]->getPrice() * percentage));
		}
		
	}
	
}
string CellPhoneHandler::showAllPhones()const
{
	
	stringstream ss;
	for(int i = 0; i < this->sizeArray; i++)
	{
		ss <<this->bridge[i]->toString();
	}
	
	return ss.str();
}
string CellPhoneHandler::showAllPhonesInStockLessthanUints(int units)const
{
	stringstream ss;
	
	for(int i=0; i < this->sizeArray; i++ )
	{
		if(this->bridge[i]->getStock() < units )
		{
			ss << this->bridge[i]->getModel() << "has only" << this->bridge[i]->getStock() << "left!" << endl;
		
		}
		
	}
	
	return ss.str();
}
void CellPhoneHandler::IOdbgIfstream(const ifstream &io) const
{
	bool eof= io.eof();
	
	bool fail= io.fail();
	
	bool bad= io.bad();
	
	bool good= io.good();
	
	bool flag = io.fail();
	;
}
void CellPhoneHandler::IOdbgOfstream(const ofstream &io) const
{
	bool eof= io.eof();
	
	bool fail= io.fail();
	
	bool bad= io.bad();
	
	bool good= io.good();
	
	bool flag = io.fail();
	;
}
