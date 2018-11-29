#pragma once
#include "Product.h"
#include <fstream>
class Store
{
	string storeName;
	vector<unique_ptr<Product>> goods;
public:
	Store(string storeName);
	void setStoreName(string storeName);
	string getStoreName()const { return storeName; }	

	void addProduct(Product* prod);
	void delProduct(Product* prod);
	bool delProductById(int id);
	int countOfGoods()const { return goods.size(); }
	void info()const;
	void listCriticalExpDate()const;
	void listExpiredDate()const;
	Product& operator[](int index) { return *goods[index]; }
	Product& operator[](int index)const { return *goods[index]; }	
};

