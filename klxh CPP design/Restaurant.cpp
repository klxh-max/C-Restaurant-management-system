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
	cout << setw(10) << "�������:" << number << setw(10) << "\t�����ţ�" << getczh()<<setw(10) << "\t����ѣ�" << bxf <<"Ԫ"<<endl;
	cout << setw(10) << "��Ʒ���" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ�ۿ�" << setw(10) << "��Ʒ����" << endl;
}