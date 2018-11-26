#pragma once
#include "Product.h"
class ConstructionMaterials :
	public Product
{
	bool ecoMark;
public:
	ConstructionMaterials(string name, date_ expDate, double price, bool ecoMark);
	void setEcoMark(bool ecoMark);
	bool getEcoMark()const { return ecoMark; }
	void info()const override;
	bool criticalDaysToExpiration()const override;
};

