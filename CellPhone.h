/*a
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CellPhone.h
 * Author: root
 *
 * Created on den 5 februari 2016, 18:25
 */

#ifndef CELLPHONE_H
#define CELLPHONE_H
#include <string>
using namespace std;
class CellPhone
{
private:
    string model;
    int InStock;
    int price;
    
public:
    //make default variable assigment to each variable
    CellPhone();
    //programmer custom default variable assigment to each variable
    CellPhone(string model, int InStock, int price);
    ~CellPhone();//NOT NECESSERY BUT STAYS BECAUSE OF SYMBOLIC VALUE.
    //set methods acces one private variable and modify content by caller.
    void setModel(string model);
    void setStock(int currentStock);
    void setPrice(int price);
    //get methods should never modify only return values they manage. 
    string getModel(void) const;
    int getStock(void) const;
    int getPrice(void) const;
    //toString() summerize all the get methods into one string which get returned to caller.
    string toString() const;
    
    
};


#endif /* CELLPHONE_H */

