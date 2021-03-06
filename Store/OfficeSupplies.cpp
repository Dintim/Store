#include "OfficeSupplies.h"




OfficeSupplies::OfficeSupplies(string name, date_ expDate, double price, string quality)
	:Product(name, expDate, price)
{
	this->quality = quality;
}

void OfficeSupplies::setQuality(string quality)
{
	this->quality = quality;
}

void OfficeSupplies::info() const
{
	Product::info();
	cout << "quality: " << quality << endl;
	cout << "price: " << getPrice() << endl;
}

bool OfficeSupplies::criticalDaysToExpiration() const
{
	if (daysToDateFromCurrDate(this->getExpDate()) <= 10) {
		//cout << "Expiration date is coming. " << daysToDateFromCurrDate(this->getExpDate()) << " days left" << endl;
		return true;
	}
	return false;	
}

void OfficeSupplies::readFromString(string & str)
{
	Product::readFromString(str);
	this->quality = str.substr(0, str.find(';'));
}

string OfficeSupplies::convertToString()
{
	string res = Product::convertToString();
	res += this->quality + ';';
	return res;
}
