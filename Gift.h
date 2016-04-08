//
// Created by root on 2016-04-08.
// This class is tested and working.
//

#ifndef ASSIGNMENTA_GIFT_H
#define ASSIGNMENTA_GIFT_H

#include <string>
using namespace std;
class Gift
{
private:
    string what;
    string recipient;
    int price;
    bool bought;

public:

	Gift(const string &what, const string &recipient, int price, bool bought) : what(what), recipient(recipient), price(price), bought(false) { }

    string getWhat(void)const;
    string getRecipient(void)const;
    int getPrice(void)const;
    bool getBought(void)const;
    void setWhat(string);
    void setRecipient(string);
    void setPrice(int);
    void setBought(bool);
    string toString(void)const;
};


#endif //ASSIGNMENTA_GIFT_H
