#include "Store.h"



Store::Store(string storeName)
{
	this->storeName = storeName;
}

void Store::setStoreName(string storeName)
{
	this->storeName = storeName;
}

void Store::addProduct(Product * prod)
{
	goods.push_back(unique_ptr<Product>(prod));
}

void Store::delProduct(Product * prod)
{
	bool f = false;
	for (size_t i = 0; i < goods.size(); i++)
	{
		if (goods[i].get() == prod) {
			f = true;
			goods.erase(begin(goods) + i);
		}
	}
	if (f == false)
		cout << "not avaliable\n";
}

void Store::info() const
{
	for (size_t i = 0; i < goods.size(); i++)
	{
		goods[i]->info();
		cout << "\n-------------------------------\n\n";
	}
}

void Store::listCriticalExpDate() const
{
	for (size_t i = 0; i < goods.size(); i++)
	{
		if (goods[i]->criticalDaysToExpiration()) {
			goods[i]->info();
			cout << "\n-------------------------------\n";
		}
	}
}

void Store::listExpiredDate() const
{
	for (size_t i = 0; i < goods.size(); i++)
	{
		if (goods[i]->expiredDate()) {
			goods[i]->info();
			cout << "\n-------------------------------\n";
		}
	}
}
