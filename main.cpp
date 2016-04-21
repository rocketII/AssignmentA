#include "system.h"
//#include <crtdbg.h>//windows none std
//#include "House.h" tested
//#include "HousingRegister.h" tested
#include <iostream>
using namespace std;


int main(void)
{
	//if windows uncomment bellow
    //_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    /*test House klass
	//House test("234567-64","BokMalarGatan 6 , 22342 Eslöv","Kåk",23000, 23, 2);
    //cout<<test.toString();
    //House done

    //test HousingRegister

    //HousingRegister test2(1);
    //
    //test2.add("3345-6764","Mölndal 6, 22342 Malmö","Kåk",23000, 23, 5);
    //test2.add("2345-6964","BokMalarGatan6 , 22342 Eslöv","Kök",1300, 23, 3);
    //test2.add("5346-9964","VinslövGatan 6 , 22342 lövby","Käk",300, 23, 2);
    //

    //HousingRegister test2b=test2;
    //HousingRegister test2c;
    //test2c.add("234567-64","BokMalarGötan 6 , 22342 Eslöv","Kåk",23000, 23, 2);
    //test2c = test2;
    //string* ptr = new string[2];
    //test2.toString_containerData(ptr);
    //cout << test2.getData_belowGivenRent(1500);
    //cout << test2.getData_belowGivenRent(500);
    //cout << test2.getData_belowGivenRent(50000);
    //cout << test2.get_Data_basedOn_TypeAndRoom("Kåk",3);
    //cout << test2.rm_GiftProposal("2345699-64");
    //test2.saveToFile("/root/fogDog.txt");
    //test2.loadToProgram("/root/fogDog.txt");
    //test menu
     */

	System start;
	start.menu();
    return 0;
}

