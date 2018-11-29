#include "HouseAppliances.h"




HouseAppliances::HouseAppliances(string name, date_ expDate, double price, int powerUsage)
	:Product(name, expDate, price)
{
	this->powerUsage = powerUsage;
}

void HouseAppliances::setPowerUsage(int powerUsage)
{
	this->powerUsage = powerUsage;
}

void HouseAppliances::info() const
{
	Product::info();
	cout << "power usage: " << powerUsage << endl;
	cout << "price: " << getPrice() << endl;
}

bool HouseAppliances::criticalDaysToExpiration() const
{
	if (daysToDateFromCurrDate(this->getExpDate()) <= 7) {
		//cout << "Expiration date is coming. " << daysToDateFromCurrDate(this->getExpDate()) << " days left" << endl;
		return true;
	}
	return false;
}

void HouseAppliances::readFromString(string & str)
{
	Product::readFromString(str);
	this->powerUsage = stoi(str.substr(0, str.find(';')));
}

string HouseAppliances::convertToString()
{
	string res = Product::convertToString();
	res += to_string(this->powerUsage) + ';';
	return res;
}
