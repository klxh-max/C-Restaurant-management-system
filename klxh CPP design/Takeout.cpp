#include "Takeout.h"
#include "Order.h"


void Takeout::setnumber(int a) {
	number = a * 10 + 2;
}

int Takeout::getnumber() { return number;}

double Takeout::getconsumption() { return consumption; }

//void Takeout::cconsumption() {
//	double a, c;
//	int b;//���ۣ��������ۿ�
//	cin >> a >> b >> c;
//	consumption = consumption+a * b * c;//�൥���Ӽ���
//}

void Takeout::setfx(int a, string b, string c) {
	scsj = a;
	scdd = b;
	phone = c;
}

void Takeout::display() {
	cout << setw(10) << "�������:"<<number<<setw(10)<<"\t�ֻ��ţ�"<<phone<<endl;
	cout << setw(10) << "�Ͳ�ʱ�䣺" << scsj << setw(10) << "����\t�Ͳ͵ص㣺" << scdd << setw(10)<<"\t�����ѣ�����󱾾�Ӫ������Χ�������Ѿ�Ϊ1Ԫ��"<<endl;
	cout << setw(10) << "��Ʒ���" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ����" << setw(10)<<"��Ʒ�ۿ�"<<setw(10) << "��Ʒ����" << endl;
}

string Takeout::getPhone() { return phone; }

int Takeout::getScsj() { return scsj; }

string Takeout::getScdd() { return scdd; }

void Takeout::setPhone(string a) { phone = a; }