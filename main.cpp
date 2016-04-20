//#include "system.h"
//#include <crtdbg.h>//windows none std
//#include "House.h"
#include "HousingRegister.h"
#include <iostream>
using namespace std;


int main(void)
{
	//only windows
    //_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //test House klass
	//House test("234567-64","BokMalarGatan 6 , 22342 Eslöv","Kåk",23000, 23, 2);
    //cout<<test.toString();
    //House done

    //test HousingRegister
    HousingRegister test2(1);
    test2.add("234567-64","BokMalarGatan 6 , 22342 Eslöv","Kåk",23000, 23, 2);
    test2.add("234569-64","BokMalarGatan 6 , 22342 Eslöv","Kåk",1300, 23, 2);
    test2.add("234568-64","BokMalarGatan 6 , 22342 Eslöv","Kåk",300, 23, 2);
    //HousingRegister test2b=test2;
    //HousingRegister test2c;
    //test2c.add("234567-64","BokMalarGötan 6 , 22342 Eslöv","Kåk",23000, 23, 2);
    //test2c = test2;
    //string* ptr = new string[2];
    //test2.toString_containerData(ptr);
    //cout << test2.getData_belowGivenRent(1500);
    //cout << test2.getData_belowGivenRent(500);
    //cout << test2.getData_belowGivenRent(50000);
    //test menu
	//System start;
	//start.menu();
    return 0;
}

