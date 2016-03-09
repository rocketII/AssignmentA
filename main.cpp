/*
 * Licens according to GPL.
 */

/* 
 * File:   main.cpp
 * Author: RODERIK BAUHN 
 * DVACD
 * DV1497
 *
 * Created on den 5 februari 2016, 18:03
 */

#include "System.h"
#include "TestCellPhoneHandler.h"
using namespace std;

/*
 * PURPOSE OF SOFTWARE, SELLS AND MANAGEMENT OF CELLULARPHONES
 * THE FOLLOWING SHOULD BE INCLUDED: ADDING PHONES, PRESENTING INVENTORY
 * , REMOVE PHONES, CHANGE PRICE ( CHANGE PRICE TO ALL PHONES MATCHING RULE OF 4000:- OR MORE),
 * SAVE PHONES TO FILE, READ PHONES FROM FILE.
 * 
 * PHONE SPECS CURRENTLY SUPPORTED: MODEL SERIES NAME, STOCKS, SALES PRICE, 
 * 
 * DESIGN:
 * I/O NOT INCL IN CLASS MEMBERS
 */
int main(void)
{
	std::cout << "I haz phail"<<'\n';
    testMyClass();
    /*
	// IF WINDOWS _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//VALGRIND FOR UNIX SYSTEMS
	System mySystem;
	bool results = false;
        while(!results)
	{
		results = mySystem.menu();
	}
     */
	std::cout << "Exiting" << endl;
	return 0;
}

