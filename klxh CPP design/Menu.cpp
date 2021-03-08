#include "Menu.h"

void Menu::Add(string a,double b,double c) {
	fnum++;
	food[fnum] = Food(a, b, c);
	food[fnum].setFoodid(fnum);
}

void Menu::Delete(int a) {
	for (int i = a;i < fnum;i++)
	{
		food[i] = food[i + 1];
		int w = food[i + 1].getFoodid() - 1;
		food[i].setFoodid(w);
	}
	fnum--;
}//cout << "������Ҫɾ���Ĳ�Ʒ��ţ������Ǵ��ŹǱ��Ϊ5��������5\n";

void Menu::Display() {
	cout << setw(10) << setiosflags(ios::left) << "��Ʒ���"<<setw(10)<<"��Ʒ����" << setw(10) << "��Ʒ�۸�" << setw(10) << "��Ʒ�ۿ�"<<endl;
	for (int i = 1;i <= fnum;i++)
		cout << setw(10) << setiosflags(ios::left) << food[i].getFoodid()<<setw(10)<<food[i].getFoodName() << setw(10) << food[i].getFoodprice() << setw(10) << food[i].getDiscount() << endl;

}

int Menu::getFnum() {
	return fnum;
}

void Menu::setFnum() { fnum = 0; }