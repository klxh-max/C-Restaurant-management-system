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
	int scsj;//������
public:
	int afood[1000],bfood[1000],hhnumber=0;//���ݶ�����Ű�˳�����˵ı�ţ��˵ķ���

	/*void cconsumption();*/
	void setnumber(int a);
	void setfx(int a, string b, string c);//�ռ�������Ϣ���Ͳ�ʱ�䡢�ص㡢�ֻ���
	void display();
	void setPhone(string a);

	int getnumber();
	double getconsumption();
	string getPhone();
	int getScsj();
	string getScdd();
};

#endif // !TAKEOUT



