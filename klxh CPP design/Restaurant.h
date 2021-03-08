#pragma once
#ifndef RESTAURANT
#define RESTAURANT

#include <bits/stdc++.h>
using namespace std;

#include "Order.h"
#include "Takeout.h"

class Restaurant:public Order
{
private:
	int czh;
	double bxf;//餐桌号、包厢费、点了几款菜
public:
	int afood[1000], bfood[1000],hhnumber = 0;//根据订单编号按顺序存入菜的编号，菜的份数

	void setnumber(int a);
	void display();
	void setczh(int a);
	void setbxf(double a);

	int getnumber();
	double getconsumption();
	int getczh();
	double getbxf();
};

#endif // !1



