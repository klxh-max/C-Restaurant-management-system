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
	double bxf;//�����š�����ѡ����˼����
public:
	int afood[1000], bfood[1000],hhnumber = 0;//���ݶ�����Ű�˳�����˵ı�ţ��˵ķ���

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



