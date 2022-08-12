#pragma once
#include<iostream>
#include<fstream>
#include "CakeRecipe.h"
#include "CommandTaker.h"
using namespace std;

class CommandPanel
{
	list<CakeRecipe*>menu;
	CommandTaker commandTaker;
public:
	CommandPanel();
	void showProducts();
	void selectProduct(string name);
	void selectProduct(string name, int numberOfProducts);
	void showProductsInCarousel();
};


 CommandPanel::CommandPanel()
{
	ifstream f;
	string nume;
	int timp, ok = 0;
	f.open("prajituri.txt");
	if (!f)
		cout << "Eroare: Fisierul nu a fost gasit!\n";
	else
		while (f >> nume >> timp)
		{
			CakeRecipe* cr = new CakeRecipe(nume, timp);
			menu.push_back(cr);
		}
}

void CommandPanel::showProducts()
{
	cout << "\nIn meniul nostru, avem urmatoarele prajituri:\n\n";
	for (auto i = menu.begin(); i != menu.end(); i++)
		(*i)->afisare();
	cout << endl;
}

void CommandPanel::selectProduct(string name)
{
	bool ok = 0;
	cout << "Ce prajitura doriti sa comandati?\n"; cin >> name;
	for (auto i = menu.begin(); i != menu.end(); i++)
		if (name == (*i)->getName())
			ok = 1;
	if (ok == 0)
		cout << "Eroare: Prajitura ceruta de dvs. nu exista!\n";
	else
		commandTaker.takeCommand(name);

}

void CommandPanel::selectProduct(string name, int numberOfProducts)
{
	bool ok = 0;
	for (auto i = menu.begin(); i != menu.end(); i++)
		if (name == (*i)->getName())
			ok = 1;
	if (ok == 0)
		cout << "Eroare: Prajitura ceruta de dvs. nu exista!\n";
	else
		if (numberOfProducts > 0 && numberOfProducts < 13)
		{
			CakeRecipe prajitura = CakeRecipe(name, 3);
			commandTaker.takeCommand(prajitura, numberOfProducts);

		}
		else
			cout << "Eroare!\n";
}

void CommandPanel::showProductsInCarousel()
{
	commandTaker.getCakesFromCarousel();
}