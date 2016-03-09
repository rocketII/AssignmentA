
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
    //we could use typeId check
	if(this->bridge != nullptr)
	{
		///This time we only destroy those which we added not array capacity. Sorry OS for last time :s
		for(int i=0; i < this->howManyPhones(); i++)
		{
			delete this->bridge[i];
		}
		delete [] this->bridge;
	}
}

//creates an array of pointers to objects. 
//And there are two arrays not related which is the case with default copy construct.
CellPhoneHandler::CellPhoneHandler(const CellPhoneHandler &origin)
{
	
	this->sizeArray=origin.sizeArray;
	this->numberOfPhones=origin.numberOfPhones;
	this->bridge = new CellPhone*[origin.sizeArray];
	
	for(int i =0; this->howManyPhones(); i++)
	{
        //new return pointer
		this->bridge[i]=new CellPhone(*origin.bridge[i]);
	}
}

CellPhoneHandler& CellPhoneHandler::operator=(const CellPhoneHandler& origin)
{
	//orgin and this pointer cannot have the same address if the assigment event are to occour.
	if(this != &origin)
	{

		this->numberOfPhones = origin.numberOfPhones;
        //1
        this->sizeArray=origin.sizeArray + 5;

		CellPhone **tmpHolder= new CellPhone*[this->sizeArray];
        //2
        for (int i = 0; i < this->numberOfPhones; ++i)
        {
            tmpHolder[i] = origin.bridge[i];
        }
        //3
        delete [] this->bridge;
        //4
        this->bridge = tmpHolder;
	}
	return *this;
}
//An array with enough space for all the data are sent here and filled with each object data in CellPhone Class.
////////////////////////////////////////////////////////////////////////////////////
//a.k.a. fillitUp().
///////////////////////////////////////////////////////////////////////////////////
//makesure that the myStringPtr got memory allocated before sending here.
void CellPhoneHandler::AllTheDataStored2Array(string*& myStringPtr)
{
	//fill string array with strings from each obj.toString();
	for(int i = 0; i < this->numberOfPhones; i++)
	{
		myStringPtr[i] = this->bridge[i]->toString();
	}
}

int CellPhoneHandler::howManyPhones(void)const
{
	//current keep track of cellphones
	
	return this->numberOfPhones;
	
	//myString is an pointer to the first element in the array.
	
}
//we open up an file stream that can write to given file in that destination on localhost.
//we write to an binary file the so called "save file". Data are in structure so that we can easily import it later with this software.
bool CellPhoneHandler::ExportDb(string filePathWithFileName)
{
    /*
     * file structure
     * first two reads should contain arraySize followed by numberOfPhones
     * the the cellphone model stock and price
     */
	bool flag;
	
	int nrOfPhonesI=0;

	ofstream  exportMe(filePathWithFileName.c_str(), ios::in); // reminder: | ios::binary
	if(!exportMe.is_open())
	{
		
	}
	else
	{
        nrOfPhonesI=howManyPhones();
		exportMe << this->sizeArray << ' ';
        exportMe << nrOfPhonesI<<' ';

        this->myStringPtr= new string[this->howManyPhones()];
		for(int i = 0; i < nrOfPhonesI; i++)
		{
			exportMe << this->bridge[i]->getModel()<<'\n';
            exportMe << this->bridge[i]->getStock() <<' ';
            exportMe << this->bridge[i]->getPrice()<<' ';
			this->IOdbgOfstream(exportMe);
		}
        exportMe <<endl;
	}
    exportMe.clear();
	exportMe.close();
	
	flag = exportMe.fail();
	
	return flag;
}

bool CellPhoneHandler::ImportDb(string filePathWithFileName)
{
	bool flag = false;
	
	ifstream  importMe;
	
	importMe.open(filePathWithFileName.c_str(), ios::out);//reminder | ios::binary
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
	

	
		if(isdigit((int)importMe.peek()))
		{
			//read on line until whitespace.
			importMe >> this->sizeArray;
		
			this->IOdbgIfstream(importMe);
		}
        if(isdigit((int)importMe.peek()))
        {
            //read on line until whitespace.
            importMe >> this->numberOfPhones;

            this->IOdbgIfstream(importMe);
        }

        this->bridge= new CellPhone*[this->sizeArray];
	
		for(int i= 0; i < this->howManyPhones(); i++)
		{

			int tmp_Stock, tmp_Price;
            string tmp_model;

            getline(importMe, tmp_model, '\n');
            this->IOdbgIfstream(importMe);
			importMe >> tmp_Stock;

			this->IOdbgIfstream(importMe);

			importMe >> tmp_Price;
		
			this->IOdbgIfstream(importMe);
		
			//this->bridge[i]->setPrice(tmp_Price);
            this->addPhone(tmp_model,tmp_Stock, tmp_Price);
		}
	
		importMe.clear();
		
	}
	importMe.close();
	
	return flag;
}

bool CellPhoneHandler::removePhoneByModel(string model)
{
	/**********************Fix this*************************************
	 * Av någon anledning så minskar du fortfarande på medlemsvariabeln,
	 * som håller koll på arrayens kapacitet i removePhoneByModel.
	 * Det leder inte till några större problem men du bör inte göra det ändå.
	 * Om en telefon tas bort så har ju arrayen fortfarande samma kapacitet.
	 * fix: removed statement.
	 */
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
std::string CellPhoneHandler::showAllPhones(void) const
{


		stringstream dd;
		for(int i =0; i < this->howManyPhones(); i++)
		{
			//
			/*	How to solve this? Help!!
             * ../InlämningA/CellPhoneHandler.cpp:
             * In member function ‘void CellPhoneHandler::showAllPhones(std::string&) const’:
             * ../InlämningA/CellPhoneHandler.cpp:379:20: error:
             *  cannot convert ‘std::string {aka std::basic_string<char>}’ to
             *  ‘char’ in assignment myStringArray[i] = this->bridge[i]->toString();
             *
             *  Answer: When calling this function the pointer to  the array got sent here as an copy.
             */
			//sendArray[i] = this->bridge[i]->toString();
            dd << this->bridge[i]->toString();
		}
        return dd.str();
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

