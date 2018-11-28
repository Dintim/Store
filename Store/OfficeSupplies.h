#pragma once
#include "Product.h"
class OfficeSupplies :
	public Product
{
	string quality;
public:
	OfficeSupplies(string name, date_ expDate, double price, string quality);
	OfficeSupplies() = default;
	void setQuality(string quality);
	string getQuality()const { return quality; }
	void info()const override;
	bool criticalDaysToExpiration()const override;
	void readFromString(string& str) override;
};

