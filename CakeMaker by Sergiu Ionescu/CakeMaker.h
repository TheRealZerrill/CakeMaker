#pragma once
#include<iostream>
#include<chrono>
#include<thread>
#include<windows.h>
#include "CakeRecipe.h"
#include "Cake.h"
using namespace std;

class CakeMaker
{
public:
	CakeMaker() {};
	Cake takeCommand(CakeRecipe recipe);
};

Cake CakeMaker::takeCommand(CakeRecipe recipe)
{
	string rrecipe = recipe.getName();
	int time = recipe.getTime();
	Cake prajitura = Cake(rrecipe);
	cout << "Prajitura este in curs de preparare...\n";
	Sleep(time*1000);
	cout << "Prajitura va este servita. Pofta buna.\n\n";
	return prajitura;
}