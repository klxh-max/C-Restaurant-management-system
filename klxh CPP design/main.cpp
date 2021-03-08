#include <bits/stdc++.h>
using namespace std;

#include "Menu.h"
#include "Food.h"
#include "Interface.h"
#include "Admin.h"
#include "Madmin.h"
#include "Order.h"
#include "Restaurant.h"
#include "Takeout.h"

fstream File;
Madmin admin;
Interface interface;
Menu menu;
string date;
Restaurant restaurant1[1000];
Takeout takeout[1000];

int main() {

	int choice1,numberq=0,numberk[2000],pp=0;//�ڼ��ݶ���numberq���������ͣ���ɾ���Ķ�������
	File.open("D:\\project\\klxh design\\data\\menu.txt", ios::in);//�˵��ļ�����
	while (!File.eof()) {
		string a;
		double b, c;
		File >> a >> b >> c;
		menu.Add(a, b, c);
	}
	File.close();
	
	File.open("D:\\project\\klxh design\\data\\admin.txt", ios::in);
	while (!File.eof())
	{
		int i = 1;
		string a, b;
		File >> a >> b;
		admin.addAdmin(a, b);
	}
	File.close();
	while (true)
	{
		choice1 = interface.showMainmap();
		while (choice1 == 1)
		{
			string ID, pas;
			cout << "�����������˺�����\n����xiaohui 12345\n";
			cin >> ID >> pas;
			int op;
			op = admin.Verify(ID, pas);
			while (op) {
				int a, b, c,k,t;
				cout << "��ӭ�������Աϵͳ���������Ž��в���ѡ��\n1.��������\n2.��Ʒ����\n3.�����������\n4.�˳�����Աϵͳ\n";
				cin >> a;
				while (a == 1)
				{
					cout << "��ѡ��ʽ���ж����鿴\n1.�������\n2.�ֻ���\n3.�˳�\n";
					cin >> b;
					if (b == 1)
					{
						cout << "�����붩����ţ�����11\n";
						cin >> c;
						if (c % 2 == 0)
						{
							int flag = 1;
							for (int i = 1;i <= c / 10;i++)
							{
								if (takeout[i].getnumber() == c)
								{
									takeout[i].display();
									for (int j = 1;j <= takeout[i].hhnumber;j++)
									{
										int q = takeout[i].afood[j];
										cout << setw(10) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << takeout[i].bfood[j] << endl;
										k = i;
										t = j;
									}
									cout << "�ܼƻ��ѣ�" << takeout[i].getconsumption() + 1 << "Ԫ" << endl;
									
									flag = 0;
								}
							}
							if (flag == 1)
							{
								cout << "û�в鵽�˶�����\n";
								break;
							}
							else
							{
								int cz;
								cout << "��������ѡ�����\n1.ɾ���˶���\n2.�޸Ĵ˶���\n3.�˳�\n";
								cin >> cz;
								if (cz == 1)
								{
									for (int s = 1;s <= takeout[k].hhnumber;s++)
									{
										menu.food[takeout[k].afood[s]].setSale(-takeout[k].bfood[s]);
										takeout[k].bfood[s] = 0;
									}
									numberk[c / 10] = 0;
									takeout[k].setnumber(0);
									takeout[k].setPhone("���޴˵�");
									pp++;
									cout << "������ɾ��\n";
								}//ɾ������	
								else if (cz == 2)
								{
									int u, v,w,x;
									cout << "������Ҫ�޸ķ������Ǵ��Źǲ�Ʒ���Ϊ1����ʾ�ڵ����У������2�ݣ���Ҫ�޸�Ϊ3�ݣ�������1 3 3���������Ҫ�Ǵ��Ź��ˣ�������1 3 0��\n";
									cin >>w>> u >> v;
									x = takeout[k].bfood[u] - v;
									takeout[k].bfood[u] = v;
									menu.food[w].setSale(x);
									takeout[k].setConsumption(x * menu.food[w].getFoodprice() * menu.food[w].getDiscount());
									cout << "�������޸�\n";
								}//�޸Ķ���

							}
						}//ż��Ϊ����
						else
						{
							int flag = 1;
							for (int i = 1;i <= c / 10;i++)
							{
								if (restaurant1[i].getnumber() == c)
								{
									restaurant1[i].display();
									for (int j = 1;j <= restaurant1[i].hhnumber;j++)
									{
										int q = restaurant1[i].afood[j];
										cout << setw(10) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << restaurant1[i].bfood[j] << endl;
									}
									cout << "�ܼƻ��ѣ�" << restaurant1[i].getconsumption() + restaurant1[numberq].getbxf() << "Ԫ" << endl;
									flag = 0;
									k = i;
								}
							}
							if (flag == 1)
							{
								cout << "û�в鵽�˶�����\n";
								break;
							}
							else
							{
								int cz;
								cout << "��������ѡ�����\n1.ɾ���˶���\n2.�޸Ĵ˶���\n3.�˳�\n";
								cin >> cz;
								if (cz == 1)
								{
									for (int s = 1;s <= takeout[k].hhnumber;s++)
									{
										menu.food[takeout[k].afood[s]].setSale(-takeout[k].bfood[s]);
										takeout[k].bfood[s] = 0;
									}
									numberk[c / 10] = 0;
									restaurant1[k].setnumber(0);
									pp++;
									cout << "������ɾ��\n";
								}//ɾ������
								else if (cz == 2)
								{
									int u, v, w, x;
									cout << "������Ҫ�޸ķ������Ǵ��Źǲ�Ʒ���Ϊ1����ʾ�ڵ����У������2�ݣ���Ҫ�޸�Ϊ3�ݣ�������1 3 3���������Ҫ�Ǵ��Ź��ˣ�������1 3 0��\n";
									cin >> w >> u >> v;
									x =  v-restaurant1[k].bfood[u] ;//�仯�ķ���
									restaurant1[k].bfood[u] = v;//�޸ķ���
									menu.food[w].setSale(x);//�޸�ÿ�ֲ��ܷ���
									restaurant1[k].setConsumption(x * menu.food[w].getFoodprice() * menu.food[w].getDiscount());
									cout << "�������޸�\n";
								}//�޸Ķ���
								
							}
						}//����Ϊ�ڵ�
					}
					else if (b == 2)
					{
						string f;
						cout << "�������ֻ��ţ�����18967543562\n";
						cin >> f;
						int flag = 1;
						for (int i = 1;i <= numberq;i++)
						{
							if (takeout[i].getPhone() == f)
							{
								takeout[i].display();
								for (int j = 1;j <= takeout[i].hhnumber;j++)
								{
									int q = takeout[i].afood[j];
									cout << setw(10) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << takeout[i].bfood[j] << endl;
								}
								cout << "�ܼƻ��ѣ�" << takeout[i].getconsumption() + 1 << "Ԫ" << endl;
								k = i;
								flag = 0;
							}
						}
						if (flag == 1)
						{
							cout << "û�в鵽�˶�����\n";
							break;
						}
						else
						{
							int cz;
							cout << "��������ѡ�����\n1.ɾ���˶���\n2.�޸Ĵ˶���\n3.�˳�\n";
							cin >> cz;
							if (cz == 1)
							{
								for (int s = 1;s <= takeout[k].hhnumber;s++)
								{
									menu.food[takeout[k].afood[s]].setSale(-takeout[k].bfood[s]);
									takeout[k].bfood[s] = 0;
								}
								numberk[k] = 0;
								takeout[k].setnumber(0);
								takeout[k].setPhone("���޴˵�");
								pp++;
								cout << "������ɾ��\n";
							}//ɾ������
							else if (cz == 2)
							{
								int u, v, w, x;
								cout << "������Ҫ�޸ķ������Ǵ��Źǲ�Ʒ���Ϊ1����ʾ�ڵ����У������2�ݣ���Ҫ�޸�Ϊ3�ݣ�������1 3 3���������Ҫ�Ǵ��Ź��ˣ�������1 3 0��\n";
								cin >> w >> u >> v;
								x = v - takeout[k].bfood[u];
								takeout[k].bfood[u] = v;
								menu.food[w].setSale(x);
								takeout[k].setConsumption(x * menu.food[w].getFoodprice() * menu.food[w].getDiscount());
								cout << "�������޸�\n";
							}//�޸Ķ���
							
						}
					}
					else if(b==3)
						break;
				}
				//����
				while (a == 2)
				{
					int cz1;
					string foodn;
					double foodp, dis;
					cout << "��������ѡ��������еĲ���\n1.��Ӳ�Ʒ\n2.�鿴��Ʒ��Ϣ\n3.�˳�\n";
					cin >> cz1;
					if (cz1 == 1)
					{
						cout << "��������Ҫ��ӵĲ�Ʒ���ơ���Ʒ���ۡ���Ʒ�ۿۣ����磬�Ǵ��Ź� 2000 0.88\n";
						cin >> foodn >> foodp >> dis;
						menu.Add(foodn, foodp, dis);
						cout << "�²�Ʒ��Ϣ��������\n";
						File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
						for (int i = 1;i < menu.getFnum();i++)
						{
							File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
						}
						int o = menu.getFnum();
						File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
						File.close();//����˵���Ϣ
					}
					while (cz1 == 2)
					{
						int cz2;
						menu.Display();
						cout << "��������ѡ��������еĲ���\n1.ɾ����Ʒ\n2.�޸�ĳ��Ʒ����\n3.�޸�ĳ��Ʒ�ۿ�\n4.�޸�ĳ��Ʒ����\n5.�˳�\n";
						cin >> cz2;
						if (cz2 == 1)
						{
							int bh;
							cout << "������Ҫɾ���Ĳ�Ʒ��ţ������Ǵ��ŹǱ��Ϊ5��������5\n";
							cin >> bh;
							menu.Delete(bh);
							cout << "��Ʒ��ɾ����\n";
							File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
							for (int i = 1;i < menu.getFnum();i++)
							{
								File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
							}
							int o = menu.getFnum();
							File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
							File.close();//����˵���Ϣ
						}
						else if (cz2 == 2)
						{
							int bh;
							double dj;
							cout << "��������Ҫ�޸ĵĲ�Ʒ����Լ������ĵ��ۣ�������Ҫ�޸��Ǵ��Źǵļ۸�Ϊ150Ԫ/�ݣ�������1 150\n";
							cin >> bh >> dj;
							menu.food[bh].setFoodprice(dj);
							cout << "���޸ģ�\n";
							File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
							for (int i = 1;i < menu.getFnum();i++)
							{
								File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
							}
							int o = menu.getFnum();
							File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
							File.close();//����˵���Ϣ
						}
						else if (cz2 == 3)
						{
							int bh;
							double zc;
							cout << "��������Ҫ�޸ĵĲ�Ʒ����Լ��������ۿۣ�������Ҫ�޸��Ǵ��Źǵ��ۿ�Ϊ0.12��������1 0.12\n";
							cin >> bh >> zc;
							menu.food[bh].setDiscount(zc);
							cout << "���޸ģ�\n";
							File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
							for (int i = 1;i < menu.getFnum();i++)
							{
								File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
							}
							int o = menu.getFnum();
							File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
							File.close();//����˵���Ϣ
						}
						else if (cz2 == 4)
						{
							int bh;
							string mc;
							cout << "��������Ҫ�޸ĵĲ�Ʒ����Լ����������ƣ�������Ҫ�޸��Ǵ��Źǵ�����Ϊ�Ǵ�С�Źǣ�������1 �Ǵ�С�Ź�\n";
							cin >> bh >> mc;
							menu.food[bh].setFoodname(mc);
							cout << "���޸ģ�\n";
							File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
							for (int i = 1;i < menu.getFnum();i++)
							{
								File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
							}
							int o = menu.getFnum();
							File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
							File.close();//����˵���Ϣ
						}
						else if (cz2 == 5)
							break;
					}
					if (cz1 == 3)
						break;
				}
				//��Ʒ
				if(a == 3)
				{
					string txt,aa,qq;
					char t(0);
					cout << "�����������ѯ�����ڣ�����2020-05-09\n";
					cin >> aa;
					txt= "D:\\project\\klxh design\\data\\" + aa + "Sell Condition.txt";
					File.open(txt, ios::_Nocreate);
					if (!File)
						cout << "��ѯʧ�ܣ��޸�����������\n";
					File.close();

					File.open(txt, ios::in);
					while (!File.eof())
					{
						File.get(t);
						qq += t;
					}
					cout << qq << endl;;
					
					File.close();
				}
				//�������
				if (a == 4)
					break;
			}
			break;
		}
		//����Աϵͳ

		if(choice1 == 2)
		{
			
			while (true)
			{
				numberq++;
				int a,b,c,d,flag=1,e;
				cout << "1.�ڵ�Ͳ�\n" << "2.��������\n3.�˳�ϵͳ\n��ѡ��Ͳͷ�ʽ,�����˳��˿�ϵͳ��\n";
				cin >> a;
				while(a == 1)
				{
					numberk[numberq] = 1;
					restaurant1[numberq].setczh(numberq);
					restaurant1[numberq].setnumber(numberq);
					if (flag == 1)
					{
						cout << "�����Ƿ�ѡ�����Ͳͣ���������1����������2����ͨ�����Ͳͣ��������Ϊ200Ԫ��\n";
						cin >> b;
						double bxf = 200;
						if (b == 1)
							restaurant1[numberq].setbxf(bxf);
					}
					menu.Display();
					cout << "��������Ҫ�Ĳ�Ʒ��š�������������Ҫ�����Ǵ��Źǣ�������1 3\n";
					cin >> c >> d;
					menu.food[c].setSale(d);
					restaurant1[numberq].hhnumber++;//ÿ�����ж��ٴβ���
					restaurant1[numberq].cconsumption(menu.food[c].getFoodprice(), d, menu.food[c].getDiscount());
					restaurant1[numberq].afood[restaurant1[numberq].hhnumber] = c;//ÿ����˳�����ÿ�β����Ĳ˵����
					restaurant1[numberq].bfood[restaurant1[numberq].hhnumber] = d;//ÿ����˳�����ÿ�β����Ĳ˵ķ���
					cout << "1.�����㵥\n2.�ύ����\n��ѡ��\n";
					cin >> e;
					if (e == 2)
					{
						restaurant1[numberq].display();
						for (int j = 1;j <= restaurant1[numberq].hhnumber;j++)
						{
							int q = restaurant1[numberq].afood[j];
							cout << setw(10) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << restaurant1[numberq].bfood[j] << endl;
						}
						cout << "�ܼƻ��ѣ�" << restaurant1[numberq].getconsumption() + restaurant1[numberq].getbxf() << "Ԫ" << endl;
						break;
					}
					//�ύ����
					else
						flag = 0;
				}
				//�ڵ�Ͳ�
				while(a==2)
				{
					numberk[numberq] = 2;
					int time1;
					srand(time(NULL));
					time1 = rand() % 25 +20;
					string a, b;
					int c,d;
					takeout[numberq].setnumber(numberq);
					if (flag == 1) {
						cout << "�밴˳�������Ͳ͵ص㡢�ֻ��ţ���������·��С��118�� 13988765456\n";
						cin >> a >> b;
						takeout[numberq].setfx(time1, a, b);
					}
					menu.Display();
					cout << "��������Ҫ�Ĳ�Ʒ��š�������������Ҫ�����Ǵ��Źǣ�������1 3\n";
					cin >> c>> d;
					menu.food[c].setSale(d);
					takeout[numberq].hhnumber++;
					takeout[numberq].cconsumption(menu.food[c].getFoodprice(), d, menu.food[c].getDiscount());
					takeout[numberq].afood[takeout[numberq].hhnumber] = c;
					takeout[numberq].bfood[takeout[numberq].hhnumber] = d;
					cout << "1.�����㵥\n2.�ύ����\n��ѡ��\n";
					cin >> e;
					if (e == 2)
					{
						takeout[numberq].display();
						for (int j = 1;j <= takeout[numberq].hhnumber;j++)
						{
							int q = takeout[numberq].afood[j];
							cout << setw(10) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << takeout[numberq].bfood[j] << endl;
						}
						cout << "�ܼƻ��ѣ�" << takeout[numberq].getconsumption() + 1<< "Ԫ"<<endl;
						break;
					}
					//�ύ����
					else
						flag = 0;
				}
				//�����Ͳ�

				if (a == 3)
					break;
				//�˳��˿�ϵͳ
			}
			
		}
		//�˿�ϵͳ

		if(choice1 == 3)
		{
			string a,txt1,txt2;
			double rs = 0, ts = 0;
			cout << "�������������ڣ�����2020-05-20\n";
			cin >> a;
			txt1 = "D:\\project\\klxh design\\data\\" + a + "order.txt";
			txt2 = "D:\\project\\klxh design\\data\\" + a + "Sell Condition.txt";
			File.open(txt1, ios::out, ios::_Noreplace);
			for (int i = 1;i < numberq;i++)
			{
				if (numberk[i] == 1)
				{
					File << setw(10) << "�������:" << restaurant1[i].getnumber() << setw(10) << "\t�����ţ�" << restaurant1[i].getczh() << setw(10) << "\t����ѣ�" << restaurant1[i].getbxf()<< "Ԫ" << endl;
					File << setw(10) << "��Ʒ���" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ�ۿ�" << setw(10) << "��Ʒ����" << endl;
					for (int j = 1;j <= restaurant1[i].hhnumber;j++)
					{
						int q = restaurant1[i].afood[j];
						File << setw(10)<<resetiosflags(ios::left) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << restaurant1[i].bfood[j] << endl;
					}
					File<< "�ܼƻ��ѣ�" << restaurant1[i].getconsumption() + restaurant1[i].getbxf() << "Ԫ" << endl;
					rs = rs + restaurant1[i].getconsumption() + restaurant1[i].getbxf();
				}
				else if(numberk[i]==2)
				{
					File << setw(10) << "�������:" << takeout[i].getnumber() << setw(10) << "\t�ֻ��ţ�" << takeout[i].getPhone()<< endl;
					File << setw(10) << "�Ͳ�ʱ�䣺" << takeout[i].getScsj()<< setw(10) << "����\t�Ͳ͵ص㣺" << takeout[i].getScdd()<< setw(10) << "\t�����ѣ�����󱾾�Ӫ������Χ�������Ѿ�Ϊ1Ԫ!" << endl;
					File << setw(10) << "��Ʒ���" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ����" << setw(10) << "��Ʒ�ۿ�" << setw(10) << "��Ʒ����" << endl;
					for (int j = 1;j <= takeout[i].hhnumber;j++)
					{
						int q = takeout[i].afood[j];
						File << setw(10) <<resetiosflags(ios::left) << q<< setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << takeout[i].bfood[j] << endl;
					}
					File<< "�ܼƻ��ѣ�" << takeout[i].getconsumption() + 1 << "Ԫ" << endl;
					ts = ts + takeout[i].getconsumption() + 1;
				}
			}
			File << "���ն�����������";
			File.close();//���涩����Ϣ

			//File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
			//for (int i= 1;i<menu.getFnum();i++)
			//{
				//File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
			//}
			//int o = menu.getFnum();
			//File  << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
			//File.close();//����˵���Ϣ

			File.open(txt2, ios::out, ios::_Noreplace);
			File << a << "�������\n";
			File << "���ƽӵ���\t" << numberq - 1 -pp<< endl;
			File << setw(10) << setiosflags(ios::left) << "��Ʒ����" << setw(10) << "��Ʒ�۸�" << setw(10) << "��Ʒ�ۿ�" << setw(10) << "���۷���" << endl;
			
			for (int i = 1;i <= menu.getFnum();i++)
			{
				File << setw(10)<< setiosflags(ios::left) << menu.food[i].getFoodName() << setw(10) << menu.food[i].getFoodprice() << setw(10) << menu.food[i].getDiscount() << menu.food[i].getSale()<<endl;
				
			}
			File<< "�������۶\t" << ts + rs <<"Ԫ"<< endl;
			File << "�ڵ����۶\t" << rs << "Ԫ\tռ�ȣ�\t" << setprecision(4) << rs / (ts + rs)*100<< "%\n";
			File << "�������۶\t" <<setprecision(100)<< ts << "Ԫ\tռ�ȣ�\t" << setprecision(4) << ts / (ts + rs) * 100 <<"%\n";
			File.close();
			//������������
			break;
		}
		//�˳�ϵͳ
	}
	return 0;
}