#pragma once
#include<iostream>
#include "CakeRecipe.h"
#include "CakeMaker.h"
#include "CarouselOfCakes.h"
using namespace std;

class CommandTaker
{
	CakeRecipe carouselRecipe;
	CakeMaker cakemaker;
	CarouselOfCakes carousel;
	bool checkCarouselOfCakes();
	void refillCarousel();
public:
	CommandTaker() {};
	Cake takeCommand(CakeRecipe recipe);
	Cake* takeCommand(CakeRecipe recipe, int nrOfCakes);
	list<Cake*> takeCommand(CakeRecipe* recipe, int nrOfCakes);
	Cake takeCommand(string nameOfCake);
	void getCakesFromCarousel();
	
};

Cake CommandTaker::takeCommand(CakeRecipe recipe)
{
	Cake prajitura = carousel.getCake(recipe.getName());
	if (prajitura.getName() != "")
		return prajitura;
	prajitura = cakemaker.takeCommand(recipe);
	return prajitura;
}

Cake* CommandTaker::takeCommand(CakeRecipe recipe, int nrOfCakes)
{
	Cake prajitura[13];
	int i = 0;
	while (nrOfCakes)
	{
		cout << "Prajitura " << recipe.getName() << " cu numarul " << i + 1 << endl;
		prajitura[i] = cakemaker.takeCommand(recipe);
		nrOfCakes--;
		i++;
	}
	return prajitura;
}

Cake CommandTaker::takeCommand(string nameOfCake)
{
	CakeRecipe pr = CakeRecipe(nameOfCake, 3);
	Cake prajitura = carousel.getCake(pr.getName());
	prajitura = cakemaker.takeCommand(pr);
	return prajitura;
}

bool CommandTaker::checkCarouselOfCakes()
{
	if (carousel.getCurrentCapacity() < 3)
		return 0;
	else return 1;
}

void CommandTaker::refillCarousel()
{
	/*bool ok;
	Cake prajitura = Cake(carouselRecipe.getName());
	int capacitate = carousel.getCurrentCapacity();
	while (capacitate < carousel.getMaxCapacity())
	{
		ok = carousel.addCake(prajitura);
		capacitate++;
	}
	return ok;*/
	list<Cake*>prajituri;
	ifstream f("prajituri.txt");
	string name;
	int time;
	while (!f.eof())
	{
		f >> name >> time;
		Cake* prajitura = new Cake(name);
		prajituri.push_back(prajitura);
	}
	Cake* c = nullptr;
	do
	{
		for (auto i = prajituri.begin(); i != prajituri.end(); i++)
		{
			c = *i;
			carousel.addCake(c);
		}
	} while (carousel.addCake(c));

}

void CommandTaker::getCakesFromCarousel()
{
	carousel.getCakesFromCarousel();
}
