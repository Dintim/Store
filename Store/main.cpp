#include "StoreConsole.h"



void main()
{
	//Store s("xxx");	
	//s.addProduct(new HouseAppliances("TV", date_(28,4,2031), 200148.5, 167));
	//s.addProduct(new OfficeSupplies("Printer", date_(5, 12, 2018), 50000, "high"));
	//s.addProduct(new ConstructionMaterials("White paint", date_(25, 11, 2018), 7000, 1));
	////s.info();
	////s.listCriticalExpDate();
	//s.listExpiredDate();
	
	StoreConsole s;
	s.start();

	//date_ d(5,12,2024);
	//date_ lt(28, 11, 2018);
	//cout << daysToDateFromCurrDate(d);
	//////cout << daysBetweenDates(lt, d);

	system("pause");
}