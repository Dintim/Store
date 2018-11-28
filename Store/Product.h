#pragma once
#include "date_.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product abstract
{
	static int prodCode;
	int id;
	string name;
	date_ expDate;
	double price;
public:
	Product(string name, date_ expDate, double price);
	Product() = default;
	void setName(string name);
	void setExpDate(date_ expDate);
	void setPrice(double price);
	string getName()const { return name; }
	date_ getExpDate()const { return expDate; }
	double getPrice()const { return price; }
	int getId()const { return id; }
	string getProductType()const { return string(typeid(*this).name()).substr(6); }

	virtual void info()const;
	virtual bool criticalDaysToExpiration()const=0;
	bool expiredDate()const;
	virtual void readFromString(string& str);
};

