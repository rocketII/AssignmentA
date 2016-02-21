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
    CellPhone **bridge = nullptr_t;	
    int sizeArray=5, current=0;
    string *myStringPtr;
    bool myStringPtrUsed=false;
public:
    
    //creates cellphone obkject linked with an dynamic array containing pointers.
    
    //Constructor also initiate default array which can be expandeble.
    
    CellPhoneHandler();
    
    CellPhoneHandler(int size);
    
    //destructor, deallocate memory
    
    ~CellPhoneHandler();
    
    //copy constructor do
    
    CellPhoneHandler(const CellPhoneHandler &origin);
    
    //operator overloading = helps us do deepCopy.
    
    CellPhoneHandler& operator=(CellPhoneHandler &origin);
    
    //recieves string array. The array are then filled with the function toString from cellphoneObjects.
    
    string AllTheDataStored2Array(string* myStringPtr, int nrOfPhones, bool myStringPtrUsed)const;
    
    //used with fillItUp()
    
    int howManyPhones( void)const;
    
    //Takes all data and save to text file
    
    bool ExportDb(string filepathWithFileName)const;
    
    //Takes all data from text file and put in a class array containing data
    
    bool ImportDb(string filepathWithFileName);
    
    bool removePhoneByModel(string model);
    
    bool addPhone(string model, int InStock, int price);
    
    bool changePrice(int forPriceGreaterThan, float percentage);
    
    string showAllPhones()const;
    
    string showAllPhonesInStockLessthanUints(int units)const;
    
    void IOdbgIfstream(const ifstream &io)const;
    
    void IOdbgOfstream(const ofstream &io) const;
    
    
};


#endif /* CELLPHONEHANDLER_H */

