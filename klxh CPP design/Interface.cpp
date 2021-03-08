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
	cout << "#\t\t     欢迎来到小慧的店";
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

	cout<<"1.管理员系统"<<endl<<"2.顾客系统"<<endl<<"3.退出系统\n";

	int choice;
	cout << "请输入要选择的选项序号\n";
	cin >> choice;
	return choice;
}