#include "StoreConsole.h"



StoreConsole::StoreConsole()
	:st("")
{
	startMenu();
}

void StoreConsole::start()
{
	mainMenu();
}

void StoreConsole::startMenu()
{
	string name;
	cout << "Enter store's name: ";	
	cin >> name;
	this->st.setStoreName(name);
}

void StoreConsole::mainMenu()
{
	int ch;
	while (true) {
		system("cls");
		cout << "Store's name: " << st.getStoreName() << endl;
		cout << "count of goods in store: " << st.countOfGoods() << endl;
		cout << "\n-----------------------------\n\n";
		cout << "1. download list of produts from file\n";
		cout << "2. add new product to store\n";
		cout << "3. delete product frome store\n";
		cout << "4. show list of products\n";
		cout << "0. exit\n";
		cout << "Choose item: ";
		cin >> ch;
		switch (ch)
		{
		case 0:
			exitMenu(); //записывать базу в файл или нет
			return;
		case 1:
			loadMenu();
			break;
		case 2:
			addProductMenu();
			break;
		case 3:
			delProductMenu();
			break;
		case 4:
			showInfoMenu();
			break;
		default:
			unknownCommand();
			break;
		}
	}
	cout << "End of work\n";

}

void StoreConsole::exitMenu()
{
	system("cls");
	int ch;	
	cout << "Exit OR write list of products into file and exit\nChoose 0 or 1: ";
	cin >> ch;
	if (ch == 0)
		cout << "You exit without writing list into file" << endl;
	if (ch == 1) {
		writeToFile();
		cout << "You write list into file(""2.txt"") and exit" << endl;
	}
}

void StoreConsole::loadMenu()
{
	ifstream file("1.txt");
	if (!file)
		throw exception("File does not exist!");

	string s;
	while (!file.eof()) {
		getline(file, s);
		string tmp = s.substr(0, s.find(';'));
		Product*prod = nullptr;
		if (tmp == "HouseAppliances")
			prod = new HouseAppliances;
		if (tmp == "OfficeSupplies")
			prod = new OfficeSupplies;
		if (tmp == "ConstructionMaterials")
			prod = new ConstructionMaterials;
		s = s.substr(s.find(';') + 1);
		prod->readFromString(s);
		st.addProduct(prod);
	}

	file.close();
	cout << "List of products from file is loaded\n";
	system("pause");
}

void StoreConsole::addProductMenu()
{
	int ch;
	while (true) {
		system("cls");		
		cout << "1. House appliance\n";
		cout << "2. Office supplies\n";
		cout << "3. Construction materials\n";
		cout << "0. go back\n";
		cout << "Choose store department: ";
		cin >> ch;
		if (ch > 3)
			unknownCommand();
		else
			break;
	}
	if (ch == 0)
		return;
	string name;		
	cout << "Enter product's name: ";
	cin >> name;
	size_t d, m, y;
	cout << "Enter product's expiration date: ";
	cin >> d >> m >> y;
	date_ expDate(d, m, y);
	double price;
	cout << "Enter product's price: ";
	cin >> price;

	Product*tmp = nullptr;
	switch (ch)
	{
	case 1: {
		int powerUsage;
		cout << "Enter power usage: ";
		cin >> powerUsage;
		tmp = new HouseAppliances(name, expDate, price, powerUsage);
	}
		break;
	case 2: {
		string quality;
		cout << "Enter product's quality: ";
		cin >> quality;
		tmp = new OfficeSupplies(name, expDate, price, quality);
	}
		break;
	case 3: {
		bool ecoMark;
		cout << "Enter product's eco-friendly mark. 1 or 0: ";
		cin >> ecoMark;
		tmp = new ConstructionMaterials(name, expDate, price, ecoMark);
	}
		break;
	}
	st.addProduct(tmp);
	cout << "Product added!\n";
	system("pause");	
}

void StoreConsole::delProductMenu()
{
	
	int ch;
	system("cls");
	while (true) {
		cout << "Enter id of product to delete from store: ";
		cin >> ch;
		if (!st.delProductById(ch))
			continue;
		cout << "Product deleted\n";
		system("pause");
		return;
	}
}

void StoreConsole::showInfoMenu()
{	
	int ch;
	while (true) {
		system("cls");		
		cout << "1. All products\n";
		cout << "2. Products from selected department\n";
		cout << "3. Products with critical expiration date\n";
		cout << "4. Products with expired date\n";
		cout << "0. go back\n";
		cout << "Choose print mode: ";
		cin >> ch;
		if (ch > 4) {
			unknownCommand();
			continue;
		}
		if (ch == 1) {
			st.info();
			system("pause");
			continue;
		}
		if (ch == 2) {
			selectDepartmentMenu();			
			system("pause");
			continue;
		}
		if (ch == 3) {
			st.listCriticalExpDate();
			system("pause");
			continue;
		}
		if (ch == 4) {
			st.listExpiredDate();
			system("pause");
			continue;
		}
		else
			break;
	}	
	if (ch == 0)
		return;		
}

void StoreConsole::unknownCommand()
{
	cout << "Unknown command\n";
	system("pause");
}

void StoreConsole::writeToFile()
{
	ofstream out("2.txt");
	string s;
	for (size_t i = 0; i < st.countOfGoods(); i++)
	{
		s = st[i].convertToString();
		out << s;
		if (i!=st.countOfGoods()-1)
			out << endl;
	}

	out.close();
}

void StoreConsole::selectDepartmentMenu()
{	
	int ch;
	while (true) {
		system("cls");
		cout << "1. House appliances\n";
		cout << "2. Office supplies\n";
		cout << "3. Construction materials\n";
		cout << "0. go back\n";
		cout << "Enter code of department: ";
		cin >> ch;
		if (ch > 3) {
			unknownCommand();
			continue;
		}
		string depName;
		if (ch == 1) {
			depName = "HouseAppliances";
			st.listByDepartment(depName);
			system("pause");
			continue;
		}
		if (ch == 2) {
			depName = "OfficeSupplies";
			st.listByDepartment(depName);
			system("pause");
			continue;
		}
		if (ch == 3) {
			depName = "ConstructionMaterials";
			st.listByDepartment(depName);
			system("pause");
			continue;
		}
		else
			break;
	}
	if (ch == 0)
		return;
	
}


