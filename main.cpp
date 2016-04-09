#include "Container.h"
#include "system.h"
//#include <crtdbg.h>//windows none std
using namespace std;


int main(void)
{
	//only windows
    //_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	System start;
	start.menu();
    return 0;
}

