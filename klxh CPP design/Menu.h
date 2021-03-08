#pragma once
#ifndef MENU
#define MENU

#include <bits/stdc++.h>
#include "Food.h"
using namespace std;

class Menu
{
private:
	
	int fnum=0;
public:
	Food food[50];
	void Add(string a, double b, double c);
	void Delete(int a);
	void Display();
	void setFnum();
	int getFnum();
};

#endif // !MENU



