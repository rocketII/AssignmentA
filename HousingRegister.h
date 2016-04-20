//
// Created by root on 2016-04-08.
//

#ifndef ASSIGNMENTA_CONTAINER_H
#define ASSIGNMENTA_CONTAINER_H

#include "House.h"

class HousingRegister
{
private:
    House ** cache;
public:
    int getNrOfElements() const;

private:
    int nrOfElements;
    int capacity;
    void expandCacheArray(void);

public:

    /*
Klassen Housing beskriver bostad.
 Egenskaper för bostad ska vara:
 unikt ID-nummer,
 adress, hyra, bostadstyp, boarea, antalet rum (t.ex. ”3”).
 */
    HousingRegister();
    HousingRegister(int capacity);
    HousingRegister(const HousingRegister &);
    HousingRegister & operator=(const HousingRegister &);
    virtual ~HousingRegister();

    //A
    void add(const string &IDnummer, const string &adress, const string& bostadstyp, int hyra, int boArea, int nrOfRoom);
    //B
    void toString_containerData(string array[])const;
    //C  print data below
    string getGiftsNotBought_GivenPriceRange(int below);
    //D show data based on room nr and  houseType
    string get_TotalCost_And_GiftsBoughtForPerson(string houseType, int roomNr)const;
    //E
    string rm_GiftProposal(string UID);
    //F
    void change_GiftData(string UID);
    //G
    void saveToFile(string SavePath);
    //H
    void loadToProgram(string loadPath);
    //Q does null
};


#endif //ASSIGNMENTA_CONTAINER_H
