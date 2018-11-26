#include "Store.h"
#include "date_.h"
#include "HouseAppliances.h"
#include "OfficeSupplies.h"
#include "ConstructionMaterials.h"


void main()
{
	/*Store s("xxx");
	date_ a(31, 12, 2023);
	s.addProduct(new HouseAppliances("TV", a, 200148.5, 167));
	s.info();*/

	date_ a(31, 12, 2018);
	date_ b(26, 11, 2018);
	cout << daysBetweenDates(b, a);

	system("pause");
}