#include "Container.h"
#include <iostream>
using namespace std;


int main(void)
{
    Container testing;
    testing.newGift("apple", "Super Mario", 1200);
    testing.newGift("mayday", "US. Dep. justice", 200000);
	std::cout << "\nExiting" << endl;
	return 0;
}

