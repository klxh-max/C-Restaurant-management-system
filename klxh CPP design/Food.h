#pragma once
#ifndef FOOD
#define FOOD

#include <bits/stdc++.h>
using namespace std;


class Food
{
private:
	int foodid,salenum=0;//菜品编号，销售总量
	string foodName;
	double disCount, foodPrice;
public:
	Food();
	Food(string foodname, double foodprice, double discount);

	void setFoodname(string);
	void setFoodprice(double);
	void setDiscount(double);
	void setFoodid(int a);
	void setSale(int a);

	string getFoodName();
	double getFoodprice();
	double getDiscount();
	int getFoodid();
	int getSale();
	
};


#endif // !FOOD
