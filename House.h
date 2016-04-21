//
// Created by root on 2016-04-08.
// This class is tested and working.

/*
Klassen Housing beskriver bostad.
 Egenskaper för bostad ska vara:
 unikt ID-nummer,
 adress, hyra, bostadstyp, boarea, antalet rum (t.ex. ”3”).
 */

//

#ifndef ASSIGNMENTA_GIFT_H
#define ASSIGNMENTA_GIFT_H

#include <string>
using namespace std;
class House
{
private:
    string IDnummer;
    string adress;
    string bostadstyp;
    int hyra;
    int boArea;
    int nrOfRoom;

public:


    House(const string &IDnummer, const string &adress, const string& bostadstyp, int hyra, int boArea, int nrOfRoom) : IDnummer(IDnummer),
                                                                                              adress(adress), bostadstyp(bostadstyp),
                                                                                              hyra(hyra),
                                                                                              boArea(boArea),
                                                                                              nrOfRoom(nrOfRoom) { }

    const string &getBostadstyp() const;

    void setBostadstyp(const string &bostadstyp);
    const string &getIDnummer() const ;

    void setIDnummer(const string &IDnummer) ;

    const string &getAdress() const ;

    void setAdress(const string &adress);

    int getHyra() const ;

    void setHyra(int hyra) ;

    int getBoArea() const ;

    void setBoArea(int boArea);

    int getNrOfRoom() const;

    void setNrOfRoom(int nrOfRoom);

    string toString(void)const;
};


#endif //ASSIGNMENTA_GIFT_H
