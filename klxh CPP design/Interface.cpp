#include "Interface.h"

int Interface::showMainmap() {
	for (int i = 0;i < 60;i++)
		cout << "#";
	cout << endl;
	for (int i = 0;i < 60;i++) {
		if (i == 0 || i == 59)
			cout << "#";
		else
			cout << " ";
	}
	cout << endl;
	cout << "#\t\t     ��ӭ����С�۵ĵ�";
	for (int i = 0;i < 22;i++)
		cout << " ";
	cout << "#";
	cout << endl;
	for (int i = 0;i < 60;i++) {
		if (i == 0 || i == 59)
			cout << "#";
		else
			cout << " ";
	}
	cout << endl;
	for (int i = 0;i < 60;i++)
		cout << "#";
	cout << endl<<endl;

	cout<<"1.����Աϵͳ"<<endl<<"2.�˿�ϵͳ"<<endl<<"3.�˳�ϵͳ\n";

	int choice;
	cout << "������Ҫѡ���ѡ�����\n";
	cin >> choice;
	return choice;
}