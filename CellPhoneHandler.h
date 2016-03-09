/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * TO IMPLEMENT:
 *      cout << "A. Add new entry " << endl;
	cout << "B. remove existing entry " << endl;
	cout << "C. change price with %-rate for all phones with price rule " << endl;
	cout << "D. Show all entries " << endl;
	cout << "E. show model with less than x units " << endl;
	cout << "F. Export DB " << endl;
	cout << "G. Import DB " << endl;
 */

/* 
 * File:   CellPhoneHandler.h
 * Author: RODERIK BAUHN
 *
 * Created on den 5 februari 2016, 18:33
 */

#ifndef CELLPHONEHANDLER_H
#define CELLPHONEHANDLER_H
#include "CellPhone.h"

class CellPhoneHandler
{
private:
    //Shall point to an CellPhone array containing pointers to objects of the CellPhoneClass
    CellPhone **bridge = nullptr;
    int sizeArray=5, numberOfPhones=0;
    string *myStringPtr; //used with export and import with files

public:
    
    //creates cellphone object linked with an dynamic array containing pointers.
    
    //Constructor also initiate default array which can be expandeble.
    
    CellPhoneHandler();
    
    CellPhoneHandler(int size);
    
    //destructor, deallocate memory
    
    ~CellPhoneHandler();
    
    //copy constructor do
    
    CellPhoneHandler(const CellPhoneHandler &origin);
    
    //operator overloading = helps us do deepCopy. and the return enable chain copy(a=b=c);
    
    CellPhoneHandler& operator=(const CellPhoneHandler &origin);
    
    //recieves string array. The array are then filled with the function toString from cellphoneObjects.
	////////////////////////////////////////////////////////////////////////////////////
	//AllTheDataStored2Array a.k.a. fillitUp().////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
    void AllTheDataStored2Array(string*& myStringPtr);
    
    //used with AllTheDataStored2Array (fillItUp())
    
    int howManyPhones( void)const;
    
    //Takes all data and save to text file
    
    bool ExportDb(string filePathWithFileName);
    
    //Takes all data from text file and put in a class array containing data
    
    bool ImportDb(string filePathWithFileName);
    
    bool removePhoneByModel(string model);
    
    bool addPhone(string model, int InStock, int price);
    
    bool changePrice(int forPriceGreaterThan, float percentage);

    std::string showAllPhones()const;
    //void showAllPhones(string sendArray[])const;
    
    string showAllPhonesInStockLessthanUints(int units)const;
    
    void IOdbgIfstream(const ifstream &io)const;
    
    void IOdbgOfstream(const ofstream &io) const;
    
    
};


#endif /* CELLPHONEHANDLER_H */

