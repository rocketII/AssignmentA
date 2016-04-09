#include "Container.h"
#include "system.h"
#include <iostream>
<<<<<<< HEAD
//#include <crtdbg.h>//windows none std
=======
#include <crtdbg.h>
>>>>>>> origin/master
using namespace std;


int main(void)
{
<<<<<<< HEAD
	//only windows
    //_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    cout << "init";
	System start;
	start.menu();
    cout<<"exit";
=======
    // I use Linux... so... valgrind
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	System start;
	start.menu();

    // step 1
    Container testing(2);


    // step 2
    testing.newGift("domino", "L. Bauhn", 234);
    testing.newGift("Zenga", "B. Bauhn", 434);


	
    // step 3
    string *ptr = new string[testing.getNrOfElements()];
    testing.toString_containerData(ptr);
    for (int u = 0; u < testing.getNrOfElements() ; ++u) {
        cout << ptr[u];
    }
	delete[] ptr;
    cout<<"\n---\n";
	
    testing.newGift("Bongo", "W. Bauhn", 344);
    string *aptr = new string[testing.getNrOfElements()];
    testing.toString_containerData(aptr);
    for (int u = 0; u < testing.getNrOfElements() ; ++u) {
        cout << aptr[u];
    }
    cout<<"\n---\n";
    delete[] aptr;
    
	/*

    // step 4
    cout << testing.rm_GiftProposal("nintendo");
    string *bptr = new string[testing.getNrOfElements()];
    testing.toString_containerData(bptr);
    for (int u = 0; u < testing.getNrOfElements() ; ++u) {
        cout << bptr[u];
    }
    cout<<"\n---\n";
    delete[] bptr;

    // step 5
    cout << testing.rm_GiftProposal("Bongo");
    string *cptr = new string[testing.getNrOfElements()];
    testing.toString_containerData(cptr);
    for (int u = 0; u < testing.getNrOfElements() ; ++u) {
        cout << cptr[u];
    }
    cout<<"\n---\n";
    delete[] cptr;

    // step 6
    cout << testing.rm_GiftProposal("Zenga");
    cout << testing.rm_GiftProposal("domino");
    string *fptr = new string[testing.getNrOfElements()];
    testing.toString_containerData(fptr);
    for (int u = 0; u < testing.getNrOfElements() ; ++u) {
        cout << fptr[u];
    }
    cout<<"\n---\n";
    delete[] fptr;

    //step 7
    testing.newGift("Kefup", "P. Bauhn", 234);
    testing.newGift("Ketchup", "Q. Bauhn", 434);


    string *lptr = new string[testing.getNrOfElements()];
    testing.toString_containerData(lptr);
    for (int u = 0; u < testing.getNrOfElements() ; ++u) {
        cout << lptr[u];
    }
    cout<<"\n---\n";
    delete[] lptr;

    //step 8
    Container copyConstruct = testing;
    string *wptr = new string[copyConstruct.getNrOfElements()];
    copyConstruct.toString_containerData(wptr);
    for (int u = 0; u < copyConstruct.getNrOfElements() ; ++u) {
        cout << wptr[u];
    }
    cout<<"\n---\n";
    delete[] wptr;
    testing.rm_GiftProposal("Ketchup");
    Container opertatorAssignment;
    opertatorAssignment.newGift("Circus", "R. Bauhn", 230004);
    opertatorAssignment.newGift("PlainBoat", "U. Bauhn", 48004);
    opertatorAssignment.operator=(copyConstruct);
    string *yptr = new string[opertatorAssignment.getNrOfElements()];
    opertatorAssignment.toString_containerData(yptr);
    for (int u = 0; u < opertatorAssignment.getNrOfElements() ; ++u) {
        cout << yptr[u];
    }
    cout<<"\n---\n";
    delete[] yptr;
	*/
	getchar();
>>>>>>> origin/master
    return 0;
}

