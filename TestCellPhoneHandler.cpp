/*
 * Vi gör tester enligt handlednings dokumentet
 */
#include"CellPhoneHandler.h"
//#include <cstdlib>
#include <iostream>

void testMyClass()
{
    std::cout << "..."<<'\n';
    CellPhoneHandler savedFile;
    std::cout<<savedFile.howManyPhones()<<endl;
    bool flag4SuccesRead;
    flag4SuccesRead=savedFile.ImportDb("/home/cellphoneData.txt");
    if(!flag4SuccesRead)
    {
        std::cout << "I haz phail"<<'\n';
    }
    else
    {
        std::cout<<"I haz pish!!";
        std::cout<<savedFile.howManyPhones()<<endl;
    }
    std::cout<<"init testing..."<<std::endl;
    std::cout<<"entering phase 1"<<std::endl;


    //1.
	CellPhoneHandler myTest(2);
    std::cout<<"entering phase 2"<<std::endl;


    //2.
	myTest.addPhone("sony PSP", 10000, 2000);
	myTest.addPhone("Microsoft phone x3001", 15000, 1000);



    //3.
	string *myStringPtrI;
	int nrOfPhones = myTest.howManyPhones();
    myStringPtrI = new string[nrOfPhones];
	myTest.AllTheDataStored2Array(myStringPtrI);
	for(int i =0; i < myTest.howManyPhones();i++)
	{
		std::cout << myStringPtrI[i];
	}
    std::cout<<"entering phase 4"<<std::endl;



    //4.
	myTest.addPhone("nintendo Uphone", 1000, 5000);
    nrOfPhones = myTest.howManyPhones();
    delete myStringPtrI;
    myStringPtrI = new string[nrOfPhones];
    myTest.AllTheDataStored2Array(myStringPtrI);
	for(int i =0; i < myTest.howManyPhones();i++)
	{
		cout << myStringPtrI[i];
	}
    std::cout<<endl;
    std::cout<<"entering phase 5"<<std::endl;
	//5
	bool howItGo = myTest.removePhoneByModel("Titenic experia");
	if(howItGo)
	{
		cout << "went well. :D"<<endl;
	}
	else
	{
		cout << "Sorry! we f**ked up :P"<<endl;
	}
    std::cout<<"entering phase 6"<<std::endl;


    //6
	myTest.removePhoneByModel("sony PSP");
	myTest.ExportDb("/home/cellphoneData.txt");
	//read file the lazy way.
	system("cat /home/cellphoneData.txt");
    std::cout<<"entering phase 7"<<std::endl;


    //7.
	myTest.removePhoneByModel("Microsoft phone x3001");
	myTest.removePhoneByModel("nintendo Uphone");
	cout<<"got "<< myTest.howManyPhones()<<" of phones"<<endl;
    std::cout<<"entering phase 8"<<std::endl;


    //8.
	myTest.addPhone("sony PSP light", 10000, 2000);
	myTest.addPhone("Microsoft phone x3001 trial", 15000, 1000);
	myTest.ExportDb("/home/cellphoneData.txt");
	//read file the lazy way.
	system("cat /home/cellphoneData.txt");
    std::cout <<'\n' <<"entering phase 9" << std::endl;


    //9.
	//copy construct test
	CellPhoneHandler myTestCopy = myTest;
	myTestCopy.ExportDb("/home/cellphoneData.txt");
	system("cat /home/cellphoneData.txt");
	//operator=()
	CellPhoneHandler myTestII;
	myTestII.addPhone("voodoPhone", 33, 23);
	cout <<"#phones:"<< myTestII.howManyPhones()<<endl;
	myTestII = myTest;
	cout <<"#phones: "<< myTestII.howManyPhones()<<endl;
	//kör valgrind på den här eller visual studios variant med macron i main.
    std::cout<<"test finished"<<endl;
	getchar();
}
/*
Nedan finner du ett första utkast på testningsförfarande för klassen CellPhoneHandler. Utför detta och
gör tillägg (även denna testfil (TestCellPhoneHandler.cpp innehållande main()) lämnas in).
1. Skapa ett objekt av typen CellPhoneHandler (låt startkapaciteten vara 2).
2. Lägg in 2 mobiltelefoner.
3. Skriv ut de strängar som erhålls i arrayen som medlemsfunktionen för CellPhoneHandler-objektet
fyller i
4. Lägg till ytterligare en mobiltelefon (vilket ska medföra att CellPhoneHandler-objektets array
expanderas). Skriv ut de strängar som erhålls i arrayen som medlemsfunktionen för CellPhoneHandler-
objektet fyller i.
5. Försök ta bort en mobiltelefon som inte finns inlagd och kontrollera att ingen borttagning gjordes
samt generera en utskrift av detta.
6. Ta bort en mobiltelefon som finns inlagd och kontrollera att borttagningen genomförts.
7. Tag bort de resterande 2 mobiltelefonerna från CellPhoneHandler-objektet och kontrollera att det
därefter inte innehåller några mobiltelefoner.
8. Lägg till 2 nya mobiltelefoner till CellPhoneHandler-objektet och kontrollera att dessa finns inlagda.
9. Testa på lämpligt sätt kopieringskonstruktor(copykonstruktor) och tilldelningsoperator.
Avsluta programmet och kontrollera slutligen att inga minnesläckor upptäckts!
	
	*/