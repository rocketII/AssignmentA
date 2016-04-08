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
    string what="empty";
    string recipient="N/A";
    int price=-1;
    bool bought=false;

public:

    Gift(const string &what, const string &recipient, int price) : what(what), recipient(recipient), price(price) { }

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
