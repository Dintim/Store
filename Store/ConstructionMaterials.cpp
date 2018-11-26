#include "ConstructionMaterials.h"




ConstructionMaterials::ConstructionMaterials(string name, date_ expDate, double price, bool ecoMark)
	:Product(name, expDate, price)
{
	this->ecoMark = ecoMark;
}

void ConstructionMaterials::setEcoMark(bool ecoMark)
{
	this->ecoMark = ecoMark;
}

void ConstructionMaterials::info() const
{
	Product::info();
	cout << "is it eco-friendly: " << boolalpha << ecoMark << endl;
	cout << "price: " << getPrice() << endl;
}

bool ConstructionMaterials::criticalDaysToExpiration() const
{
	if (daysToDateFromCurrDate(this->getExpDate()) <= 30) {
		//cout << "Expiration date is coming. " << daysToDateFromCurrDate(this->getExpDate()) << " days left" << endl;
		return true;
	}
	return false;
}
