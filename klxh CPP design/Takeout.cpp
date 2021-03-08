#include "Takeout.h"
#include "Order.h"


void Takeout::setnumber(int a) {
	number = a * 10 + 2;
}

int Takeout::getnumber() { return number;}

double Takeout::getconsumption() { return consumption; }

//void Takeout::cconsumption() {
//	double a, c;
//	int b;//单价，份数，折扣
//	cin >> a >> b >> c;
//	consumption = consumption+a * b * c;//多单叠加计算
//}

void Takeout::setfx(int a, string b, string c) {
	scsj = a;
	scdd = b;
	phone = c;
}

void Takeout::display() {
	cout << setw(10) << "订单编号:"<<number<<setw(10)<<"\t手机号："<<phone<<endl;
	cout << setw(10) << "送餐时间：" << scsj << setw(10) << "分钟\t送餐地点：" << scdd << setw(10)<<"\t外卖费：本店大本经营，合理范围内外卖费均为1元！"<<endl;
	cout << setw(10) << "菜品编号" << setw(10) << "菜品名称" << setw(10) << "菜品单价" << setw(10)<<"菜品折扣"<<setw(10) << "菜品份数" << endl;
}

string Takeout::getPhone() { return phone; }

int Takeout::getScsj() { return scsj; }

string Takeout::getScdd() { return scdd; }

void Takeout::setPhone(string a) { phone = a; }