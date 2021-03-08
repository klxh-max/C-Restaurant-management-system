#pragma once
#ifndef TAKEOUT
#define TAKEOUT

#include <bits/stdc++.h>
using namespace std;

#include "Order.h"

class Takeout:public Order
{
private:
	string  scdd, phone;
	int scsj;//外卖费
public:
	int afood[1000],bfood[1000],hhnumber=0;//根据订单编号按顺序存入菜的编号，菜的份数

	/*void cconsumption();*/
	void setnumber(int a);
	void setfx(int a, string b, string c);//收集订单信息：送餐时间、地点、手机号
	void display();
	void setPhone(string a);

	int getnumber();
	double getconsumption();
	string getPhone();
	int getScsj();
	string getScdd();
};

#endif // !TAKEOUT



