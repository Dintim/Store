#pragma once
#include "Product.h"
class HouseAppliances :
	public Product
{
	int powerUsage;
public:
	HouseAppliances(string name, date_ expDate, double price, int powerUsage);
	HouseAppliances() = default;
	void setPowerUsage(int powerUsage);
	int getPowerUsage()const { return powerUsage; }
	void info()const override;
	bool criticalDaysToExpiration()const override;
	void readFromString(string& str) override;
};

