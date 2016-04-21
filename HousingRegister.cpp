//
// Created by root on 2016-04-08.
//

#include "HousingRegister.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
//tested
HousingRegister::HousingRegister()
{
    this->nrOfElements=0;
    this->capacity=1;
    this->cache = new House*[this->capacity];
}
//tested
HousingRegister::HousingRegister(int capacity)
{
    this->nrOfElements=0;
    this->capacity=capacity;
    this->cache = new House*[this->capacity];
}
//tested
HousingRegister::HousingRegister(const HousingRegister &orgin)
{
    this->capacity= orgin.capacity;
    this->nrOfElements=orgin.nrOfElements;
    this->cache = new House *[this->capacity];
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        this->cache[i]= new House(*(orgin.cache[i]));
    }
}
//tested
HousingRegister & HousingRegister::operator=(const HousingRegister &orgin)
{
    if(this != &orgin)
    {

        for (int i = 0; i < this->nrOfElements ; ++i)
        {
            delete this->cache[i];
        }
        delete[] this->cache;

        this->capacity= orgin.capacity;
        this->nrOfElements=orgin.nrOfElements;

        this->cache = new House *[this->capacity];
        //Deep copy
        for (int i = 0; i < this->nrOfElements ; ++i)
        {
            this->cache[i]= new House(*(orgin.cache[i]));
        }
    }
    return *this;
}
//tested
HousingRegister::~HousingRegister()
{
    for (int i = 0; i < this->getNrOfElements() ; ++i)
    {
        delete this->cache[i];
    }
    delete[] this->cache;
}

//A
//tested
void HousingRegister::add(const string &IDnummer, const string &adress, const string& bostadstyp, int hyra, int boArea, int nrOfRoom)
{
    if(this->nrOfElements < this->capacity )
    {
        this->cache[this->nrOfElements]= new House(IDnummer, adress, bostadstyp, hyra, boArea,nrOfRoom);
        this->nrOfElements++;
    }
    else
    {
        this->expandCacheArray();
        this->cache[this->nrOfElements]= new House(IDnummer, adress, bostadstyp, hyra, boArea,nrOfRoom);
        this->nrOfElements++;
    }
}
//B
//tested
void HousingRegister::toString_Data(string array[])const
{
    for (int i = 0; i < this->getNrOfElements() ; ++i)
    {
        array[i] = this->cache[i]->toString();
    }
}
//C  print data below rent
//tested
string HousingRegister::getData_belowGivenRent(int belowrent)
{
    stringstream tri;

    tri<<"\n The Following matches are: ";
    tri<<"\n#########################@_*_@####################";

    for(int i =0 ; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getHyra() < belowrent)
        {

            tri << this->cache[i]->toString();
            tri<<"\n--------------------------------------------------";

        }


    }

    tri <<"\n#########################@_R_@####################";
    return tri.str() ;
}
//D show data based on room nr and  houseType
//tested
string HousingRegister::get_Data_basedOn_TypeAndRoom(string& houseType, int roomNr)const
{
    stringstream tt;
    tt<<"\n The Following matches are: ";
    tt<<"\n#########################@_*_@####################";

    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getBostadstyp() == houseType && this->cache[i]->getNrOfRoom() == roomNr)
        {
            tt << this->cache[i]->toString();
            tt<<"\n--------------------------------------------------";

        }


    }

    tt <<"\n#########################@_R_@####################";
    return tt.str() ;
}
//E
//tested
string HousingRegister::rm(string& UID)
{
    stringstream gg;
    gg << "No matching hit";
    for(int i =0 ; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getIDnummer() == UID)
        {
            gg.str("");

            delete this->cache[i];
            this->cache[i]= this->cache[this->nrOfElements-1];
            this->nrOfElements--;

        }


    }
    return gg.str();
}
//F
//tested
void HousingRegister::change_GiftData(const string& UID,const string& &adress, const string& bostadstyp, int hyra, int boArea, int nrOfRoom)
{
    for(int i = 0; i < this->getNrOfElements(); ++i)
    {
        if(this->cache[i]->getIDnummer() == UID)
        {
            this->cache[i]->setIDnummer(UID);
            this->cache[i]->setAdress(adress);
            this->cache[i]->setBostadstyp(bostadstyp);
            this->cache[i]->setHyra(hyra);
            this->cache[i]->setBoArea(boArea);
            this->cache[i]->setNrOfRoom(nrOfRoom);
        }

    }
}
//G
//tested
void HousingRegister::saveToFile(string& SavePath)
{
    string open= SavePath;
    ofstream openFile;
    openFile.open(open);
    if(openFile.is_open())
    {
        openFile<<this->getNrOfElements()<<'\n';
        for (int i = 0; i < this->getNrOfElements() ; ++i)
        {
            openFile << this->cache[i]->getBoArea()<<'\n'
            << this->cache[i]->getHyra()<<'\n'<<this->cache[i]->getNrOfRoom()<<'\n'
            << this->cache[i]->getAdress()<<'\n'<<this->cache[i]->getBostadstyp()<<'\n'
            <<this->cache[i]->getIDnummer()<<'\n';
        }
    }
    openFile<<EOF;
    openFile.close();
}
//H
//tested
void HousingRegister::loadToProgram(string& loadPath)
{
    string read= loadPath;
    ifstream readFile;
    readFile.open(read);
    string adress;
    string bostadsTyp;
    string UID;
    int boYta=0, hyra=0, antalRom=0, elements=0;
    readFile>>elements;
    for (int i=0; i < elements; i++ )
    {
        //getLine reads untill '\n'. in file theres one to much...
        readFile >> boYta;
        readFile>>hyra;
        readFile>>antalRom;
        getline(readFile, adress, '\n');
        getline(readFile, adress, '\n');
        getline(readFile, bostadsTyp,'\n');
        getline(readFile, UID,'\n');
        this->add(UID, adress, bostadsTyp, hyra, boYta, antalRom);
    }
    readFile.close();
}
//Q does null


//tested
int HousingRegister::getNrOfElements() const
{
    return this->nrOfElements;
}
//tested
void HousingRegister::expandCacheArray(void)
{
    House ** tmp = new House *[this->capacity];
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        tmp[i]= new House(*(this->cache[i]));
    }
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        delete this->cache[i];
    }
    delete[] this->cache;

    this->capacity+= 2;

    this->cache = new House *[this->capacity];

    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        this->cache[i]= new House(*(tmp[i]));
    }
    for (int i = 0; i < this->nrOfElements ; ++i)
    {
        delete tmp[i];
    }
    delete[] tmp;
}
