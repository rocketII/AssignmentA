/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   System.h
 * Author: root
 *
 * Created on den 5 februari 2016, 18:34
 */

#ifndef SYSTEM_H
#define SYSTEM_H
#include"CellPhoneHandler.h"
#include <iostream>

//manages the interactive menu.
class System
{
private:
    CellPhoneHandler API;
public:
    bool menu(void);
    //use try catch to make sure only legit whole numbers are entered.
    bool stockLegit(const int stock) const;
    //uses try catch to check that price is not negative
    bool priceLegit(const int price)const;
    //manage input to CellPhoneHandler.
    void inputA(void);
    void inputB(void);
    void inputC(void);
    void inputD(void);
    void inputE(void);
    void inputF(void);
    void inputG(void);
};



#endif /* SYSTEM_H */

