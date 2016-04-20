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
    test2.add("234567-64","BokMalarGatan 6 , 22342 Eslöv","Kåk",23000, 23, 2);
    //HousingRegister test2b=test2;

    //test menu
	//System start;
	//start.menu();
    return 0;
}

