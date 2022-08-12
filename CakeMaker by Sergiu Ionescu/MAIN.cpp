#include<iostream>
#include<string>
#include<fstream>
#include "CommandPanel.h"
using namespace std;

ifstream f("prajituri.txt");

int main()
{
	CommandPanel cp;
	string name;
	int opt;
	cout << "-----CakeMaker-----\n\n";
	cout << "1. Arata Meniu\n";
	cout << "2. Comandati o prajitura\n";
	cout << "3. Comandati mai multe prajituri\n";
	cout << "0. Iesire\n\n";
	do
	{
		cout << "Optiunea dumneavoastra este: "; cin >> opt;
		switch (opt)
		{
		case 0:
		{
			cout << "\nMultumesc pentru atentie!\n";
			f.close();
			exit(0);
		}
			break;
		case 1:
		{
			cp.showProducts();
			break;
		}
		case 2:
		{
			cp.selectProduct(name);
			break;
		}
		case 3:
		{
			int numberOfProducts;
			cout << "Ce prajitura doriti sa comandati?\n"; cin >> name;
			if (name == "amandina" || name == "briosa" || name == "ecler" || name == "savarina")

			{
				cout << "Cate prajituri doriti sa comandati?\n"; cin >> numberOfProducts;
				cp.selectProduct(name, numberOfProducts);
			}
			else
				cout << "Prajitura nu se afla in sistem!\n";
			break;
		}

		default:cout << "Optiune gresita!\n";
			break;
		}
	} while (1);
	system("pause");
	return 0;
}