/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "CellPhone.h"
#include<sstream>

using namespace std;
CellPhone::CellPhone()
{
	this->model="Default phone";
	this->InStock=1;
	this->price=3000;
}
CellPhone::CellPhone(string model, int stock, int price)
{
	this->model=model;
	this->InStock=stock;
	this->price=price;
}

CellPhone::~CellPhone()
{
	//nothing todo here
	//CellPhoneHandler Class manages new and delete for this class objects
	;
}
void CellPhone::setModel(std::string model)
{
	this->model=model;
}
void CellPhone::setStock(int currentStock)
{
	this->InStock=currentStock;
}
void CellPhone::setPrice(int price)
{
	
	this->price=price;
}
std::string CellPhone::getModel(void)const
{
	return this->model;
	
}
int CellPhone::getStock(void)const
{
	return this->InStock;
}
int CellPhone::getPrice(void)const
{
	return this->price;
}
string CellPhone::toString()const
{
	std::stringstream ss;
	ss << "model name: "<< this->getModel() <<" there's" << this->getStock() << "left in stock" << "They costs"<< this->getPrice() << " each"<<endl;
	return ss.str();
}