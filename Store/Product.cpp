#include "Product.h"

int Product::prodCode = 0;
Product::Product(string name, date_ expDate, double price)
{
	this->id = ++prodCode;
	this->name = name;
	this->expDate = expDate;
	this->price = price;
}

void Product::setName(string name)
{
	this->name = name;
}

void Product::setExpDate(date_ expDate)
{
	this->expDate = expDate;
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::info() const
{
	cout << "id: " << id << "\nname: " << name << "\nexpiration date: " << expDate;
}

bool Product::expiredDate() const
{
	if (daysToDateFromCurrDate(this->expDate) < 0) {
		//info();
		return true;
	}
	return false;
}

//int Product::daysToExpiration() const
//{
//	return daysToDateFromCurrDate(this->expDate);
//}
