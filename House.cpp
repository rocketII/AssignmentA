//
// Created by root on 2016-04-08.
// Tested and working
//

#include "House.h"
#include <sstream>

const string &House::getBostadstyp() const
{
    return bostadstyp;
}

void House::setBostadstyp(const string &bostadstyp)
{
    House::bostadstyp = bostadstyp;
}
const string& House::getIDnummer() const
{
    return IDnummer;
}

void House::setIDnummer(const string &IDnummer)
{
    House::IDnummer = IDnummer;
}

const string& House::getAdress() const
{
    return adress;
}

void House::setAdress(const string &adress)
{
    House::adress = adress;
}

int House::getHyra() const
{
    return hyra;
}

void House::setHyra(int hyra)
{
    House::hyra = hyra;
}

int House::getBoArea() const
{
    return boArea;
}

void House::setBoArea(int boArea)
{
    House::boArea = boArea;
}

int House::getNrOfRoom() const
{
    return nrOfRoom;
}

void House::setNrOfRoom(int nrOfRoom)
{
    House::nrOfRoom = nrOfRoom;
}

string House::toString() const
{
    stringstream rr;
    rr <<"\nTyp: "<< this->getBostadstyp() <<"\nHyra: "<< this->getHyra() << "\nAntal Rum: "<<this->getNrOfRoom()<<"\nBoYta: " << this->getBoArea()
    << "\nAdress: "<<this->getAdress()<<"\nUID: "<<this->getIDnummer();
    return rr.str() ;
}

/*
Klassen Housing beskriver bostad.
 Egenskaper för bostad ska vara:
 unikt ID-nummer,
 adress,*/



