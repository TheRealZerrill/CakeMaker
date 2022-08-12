#pragma once
#include<iostream>
#include<list>
#include "Cake.h"
#include "CommandTaker.h"
using namespace std;

class CarouselOfCakes
{
	list<Cake*>storage;
	unsigned int maxCapacity = 12, lowLimit = 3;
public:
	CarouselOfCakes() {};
	bool addCake(Cake* cake);
	Cake getCake(string name);
	int getCurrentCapacity();
	int getMaxCapacity();
	int getLowLimit();
	void getCakesFromCarousel();

};

bool CarouselOfCakes::addCake(Cake* cake)
{
	for (int i = 0; i < getMaxCapacity(); i++)
	{
		storage.push_back(cake);
		return 1;
	}
	return 0;
}

Cake CarouselOfCakes::getCake(string name)
{
	//for (int i = 0; i < getMaxCapacity(); i++)
	//{
	//	if(storage.size()!=0)
	//		for (auto j = storage.begin(); j != storage.end(); j++)
	//		{
	//			if ((*j)->getName() == name)
	//			{
	//				Cake* prajitura2 = (*j);
	//				storage.remove(*j);
	//				return *prajitura2;
	//			}
	//		}
	//}
	//return Cake(name);
	for (auto i = storage.begin(); i != storage.end(); i++)
	{
		if ((*i)->getName() == name)
		{
			Cake* prajitura = *i;
			storage.remove(*i);
			cout << "Prajitura va fi servita imediat...\n";
			return *prajitura;
		}
	}
	cout << "Prajitura nu exista in carusel!\n";
	return Cake("");
}

int CarouselOfCakes::getCurrentCapacity()
{
	return storage.size();
}

int CarouselOfCakes::getMaxCapacity()
{
	const int maxCapacity = 12;
	return maxCapacity;
}

int CarouselOfCakes::getLowLimit()
{
	const int lowCapacity = 3;
	return lowCapacity;
}



void CarouselOfCakes::getCakesFromCarousel()
{

	int cantitate_curenta = storage.size(), i = 0;
	if(cantitate_curenta==0)
		cout << "\nNu sunt prajituri in carousel!\n";
	else
	{
		while (i < cantitate_curenta)
			for (auto j = storage.begin(); j != storage.end(); j++)
			{
				cout << (*j)->getName() << "\n";
				i++;
			}
	}

	cout << endl;
}

