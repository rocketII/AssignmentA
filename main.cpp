#include "Container.h"
#include <iostream>
using namespace std;


int main(void)
{
    Container testing;
    testing.newGift("apple", "Super Mario", 1200);
    testing.newGift("DerpCart 64", "JohnWuigi", 1101);
    testing.newGift("bil", "Luigi", 101);
    testing.newGift("bilTema", "gina Larsson", 13001);
    testing.newGift("apple", "Super Mario", 1200);
    testing.newGift("DerpCart 64", "JohnWuigi", 1101);
    testing.newGift("bil", "Luigi", 101);
    testing.change_GiftData("DerpCart 64", "Jogy", 1,false);
    cout<<" n--------\n"<<testing.;
  	std::cout << "\nExiting" << endl;
	return 0;
}

