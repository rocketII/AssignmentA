#pragma once
#include "HousingRegister.h"
#include<iostream>
#include<string>
using namespace std;
class System
{
private:
	string *ptr;
	HousingRegister instance;
	// menu
	void menutxt(void)const;
	//A
	void add(void);
    //B
    void show_All(void);
    //C
    void show_BelowValue(void);
    //D
    void show_type_and_nrOfRooms(void)const;
    //E
    void rm(void);
    //F
    void change_properties(void);
    //G
    void save_On_File(void);
    //H
    void load_From_File(void);
    //Q
    //quit

public:
	System(void);
	~System(void);

	void menu(void);
	
};

