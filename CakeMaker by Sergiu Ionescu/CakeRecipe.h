#pragma once
#include<iostream>
using namespace std;

class CakeRecipe
{
	string name;
	int time;
public:
	CakeRecipe() {};
	CakeRecipe(string name, int time);
	string getName();
	int getTime();
	void afisare()
	{
		cout << "Denumire Produs: " << this->name << "\n";
	}
};

CakeRecipe::CakeRecipe(string name, int time)
{
	this->name = name;
	this->time = time;
}

string CakeRecipe::getName()
{
	return name;
}

int CakeRecipe::getTime()
{
	return time;
}