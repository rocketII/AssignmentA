
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
	this->myStringPtr=NULL;
	
	
	
}

CellPhoneHandler::CellPhoneHandler(int size)
{
	//create default array with pointers to default objects of CellPhoneClass
	this->sizeArray=size;
	this->bridge = new CellPhone*[this->sizeArray];
	this->myStringPtr=NULL;
	
	
	
}

CellPhoneHandler::~CellPhoneHandler()
{
	if(this->bridge != NULL)
	{
		///This time we only destroy those which we added not array capacity. Sorry OS for last time :s
		for(int i=0; i < this->howManyPhones(); i++)
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
	
	for(int i =0; this->howManyPhones(); i++)
	{ 
		this->bridge[i]=new CellPhone(*origin.bridge[i]);
		
	}
}

CellPhoneHandler& CellPhoneHandler::operator =(const CellPhoneHandler& origin)
{
	//orgin and this pointer cannot have the same address if the assigment event are to occour.
	if(this != &origin)
	{
		//deep copy.
		
		//make sure target and Source has the same size.
		this->sizeArray = origin.sizeArray;
		
		//for(int i=0; i < origin.howManyPhones(); i++)
		//{
			//empty target on object pointer by freeing memory on the heap.
		for(int i=0; i < this->howManyPhones(); i++)
		{
		delete this->bridge[i];
		}
		//Dealloc memory of array.
			
		delete [] this->bridge; //you can create freeMemory() to save work.
			
		//the target then creates an new array filled with object pointers!!!
			
	 	this->bridge= new CellPhone*[origin.sizeArray] ;              //makecopy()
			
		//ofc! We must fill the array with pointer objects that orgin has.
			
	 	for(int i =0; i < this->howManyPhones(); i++)
	 	{
	 		this->bridge[i]=new CellPhone(*origin.bridge[i]);
	 	}
			
		//}
	}
	return *this;
}
//An array with enoug space for all the data are sent here and filled with each object data in CellPhone Class.
////////////////////////////////////////////////////////////////////////////////////
//a.k.a. fillitUp().
///////////////////////////////////////////////////////////////////////////////////

string CellPhoneHandler::AllTheDataStored2Array(string* myStringPtr, const int nrOfPhones)
{
	if(myStringPtr == NULL)
	{
		myStringPtr = new string[nrOfPhones];
	}
	else
	{
		delete myStringPtr;
	}
	
	
	this->myStringPtrUsed=true;
	
	stringstream ss;
	
	for(int i = 0; i < nrOfPhones; i++)
	{
		
		myStringPtr[i] =(string) this->bridge[i]->toString();
	}
	
	for(int i = 0; i < nrOfPhones; i++)
	{
		
		ss << myStringPtr[i]; 
	}
	
	return ss.str();
	
	
}

int CellPhoneHandler::howManyPhones( void)const
{
	//current keep track of cellphones
	
	return this->numberOfPhones;
	
	//myString is an pointer to the first element in the array.
	
}
//we open up an file stream that can write to given file in that destination on localhost.
//we write to an binary file the so called "save file". Data are in structure so that we can easily import it later with this software.
bool CellPhoneHandler::ExportDb(string filepathWithFileName)
{
	bool flag = false;
	
	int nrOfPhones=0;
	
	ofstream  exportMe(filepathWithFileName.c_str(), ios::in | ios::binary);
	if(!exportMe.is_open())
	{
		
	}
	else
	{
		exportMe << this->sizeArray << endl;
		nrOfPhones=howManyPhones();
	
		for(int i = 0; i < nrOfPhones; i++)
		{
			exportMe << this->AllTheDataStored2Array(this->myStringPtr, this->numberOfPhones);
		
			this->IOdbgOfstream(exportMe);
		}
	}
	
	
	
	
	exportMe.close();
	
	flag = exportMe.fail();
	
	return flag;
}

bool CellPhoneHandler::ImportDb(string filepathWithFileName)
{
	bool flag = false;
	/*
	bool eof=false;
	
	bool fail=false;
	
	bool bad=false;
	
	bool good=false;
	*/
	char peekingAt;
	
	string tmp_string;
	
	ifstream  importMe;
	
	importMe.open(filepathWithFileName.c_str(), ios::out | ios::binary);
	if(!importMe.is_open())
	{
		;
	}
	else
	{
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
		
	}
	importMe.close();
	
	return flag;
}

bool CellPhoneHandler::removePhoneByModel(string model)
{
	//walkthrough the array with pointers to objects and look for matching model name
	///if it exist overite it with last place element data and delete last place in array then shrink the array
	bool flag = false;
	
	//for(int i=0; i < this->sizeArray; i++)
	for(int i=0; i < this->numberOfPhones; i++)
	{
		if(this->bridge[i]->getModel()==model)
		{
			this->bridge[i]->setModel(this->bridge[this->numberOfPhones-1]->getModel());
			
			this->bridge[i]->setPrice(this->bridge[this->numberOfPhones-1]->getPrice());
			
			this->bridge[i]->setStock(this->bridge[this->numberOfPhones-1]->getStock());
			
			//deallocate memory for the pointer object so there won't be a copy.
			
			delete this->bridge[this->numberOfPhones-1];
			
			//Shrink array on element
			
			this->sizeArray--;
			
			this->numberOfPhones--;
			
			flag=true;
		}
	}
	
	return flag;
}


bool CellPhoneHandler::addPhone(string model, int InStock, int price)
{
	bool flag = false;
	
	if( this->numberOfPhones < this->sizeArray)
	{
		this->bridge[this->numberOfPhones++] = new CellPhone(model, InStock, price);
		
		flag=true;
		
		//this->current++;
	}
	//expand array by create tmp and then assign CellPhone pointers. 
	//destroy old one and recreate with bigger size. 
	//And copy from tmp array.
	if(this->numberOfPhones > this->sizeArray-1)
	{
		CellPhone **tmp_bridge;
		
		tmp_bridge = new CellPhone*[this->sizeArray+5];
		
		//for(int i=0; i < this->sizeArray; i++)
		for(int i=0; i < this->numberOfPhones; i++)
		{
			tmp_bridge[i] = this->bridge[i];
		}
		
		//for(int i=0; i < this->sizeArray; i++)
		//only delete the known number. 
		for(int i=0; i < this->numberOfPhones; i++)
		{
			delete this->bridge[i];
		}
		delete [] bridge;
		
		this->bridge = new CellPhone*[sizeArray+5];
		//for(int i=0; i < this->sizeArray; i++)
		//only fetch the known number. 
		for(int i=0; i < this->numberOfPhones; i++)
		{
			this->bridge[i] = tmp_bridge[i];
		}
		
		this->sizeArray+=5;
		
		
	}
	
	return flag;
}

//loop through number of phones, all the matching phones with greater value we change them.
//I sure hope the user enter percentage as 0.10 or 1.10.
bool CellPhoneHandler::changePrice(int forPriceGreaterThan, float percentage)
{
	for(int i=0; i < this->numberOfPhones; i++ )
	{
		if(this->bridge[i]->getPrice() > forPriceGreaterThan )
		{
			// pris - pris*procent för rabatt. pris + pris*procent för ökning.
			//this->bridge[i]->setPrice(this->bridge[i]->getPrice() - (this->bridge[i]->getPrice() * percentage));
			if(percentage < 1)
			{
				this->bridge[i]->setPrice(this->bridge[i]->getPrice() - (this->bridge[i]->getPrice() * percentage));
			}
			else
			{
				this->bridge[i]->setPrice(this->bridge[i]->getPrice() * percentage);
			}
			
		}
		
	}
	
}



//Using phone obj tostring() and the user granted StringArray that should have the correct number of phones. We fill it and can later be used.
void CellPhoneHandler::showAllPhones(string &myStringArray)const
{
	for(int i =0; i < this->numberOfPhones; i++)
	{
		//
		/*	How to solve this? Help!! 
		 * ../InlämningA/CellPhoneHandler.cpp: 
		 * In member function ‘void CellPhoneHandler::showAllPhones(std::string&) const’:
		 * ../InlämningA/CellPhoneHandler.cpp:379:20: error:
		 *  cannot convert ‘std::string {aka std::basic_string<char>}’ to 
		 *  ‘char’ in assignment myStringArray[i] = this->bridge[i]->toString();
		 */
		myStringArray[i] = this->bridge[i]->toString();
	}
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
//debug only
void CellPhoneHandler::IOdbgIfstream(const ifstream &io) const
{
	bool eof= io.eof();
	
	bool fail= io.fail();
	
	bool bad= io.bad();
	
	bool good= io.good();
	
	bool flag = io.fail();
	;
}
//debug only
void CellPhoneHandler::IOdbgOfstream(const ofstream &io) const
{
	bool eof= io.eof();
	
	bool fail= io.fail();
	
	bool bad= io.bad();
	
	bool good= io.good();
	
	bool flag = io.fail();
	;
}
