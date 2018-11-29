#pragma once
#include "Store.h"
#include "HouseAppliances.h"
#include "OfficeSupplies.h"
#include "ConstructionMaterials.h"

class StoreConsole
{
	
public:
	Store st;
	StoreConsole();
	void start();
private:
	void startMenu();
	void mainMenu();
	void exitMenu();
	void loadMenu();
	void addProductMenu();
	void delProductMenu();
	void showInfoMenu();
	void unknownCommand();
	void writeToFile();
	void selectDepartmentMenu();
};

