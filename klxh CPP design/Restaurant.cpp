#include "Restaurant.h"
#include "Takeout.h"
#include "Order.h"

double Restaurant::getbxf() { return bxf; }

int	Restaurant::getczh() { return czh; }

double Restaurant::getconsumption() { return consumption; }

int Restaurant::getnumber() { return number; }

void Restaurant::setbxf(double a) { bxf = a; }

void Restaurant::setczh(int a) { czh = a; }

void Restaurant::setnumber(int a) {
	number = a * 10 + 1;
}

void Restaurant::display() {
	cout << setw(10) << "订单编号:" << number << setw(10) << "\t餐桌号：" << getczh()<<setw(10) << "\t包厢费：" << bxf <<"元"<<endl;
	cout << setw(10) << "菜品编号" << setw(10) << "菜品名称" << setw(10) << "菜品单价" << setw(10) << "菜品折扣" << setw(10) << "菜品份数" << endl;
}