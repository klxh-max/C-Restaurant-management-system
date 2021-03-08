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

	int choice1,numberq=0,numberk[2000],pp=0;//第几份订单numberq，订单类型，被删除的订单数量
	File.open("D:\\project\\klxh design\\data\\menu.txt", ios::in);//菜单文件读入
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
			cout << "请输入您的账号密码\n例如xiaohui 12345\n";
			cin >> ID >> pas;
			int op;
			op = admin.Verify(ID, pas);
			while (op) {
				int a, b, c,k,t;
				cout << "欢迎进入管理员系统！请根据序号进行操作选择\n1.订单管理\n2.菜品管理\n3.销售详情管理\n4.退出管理员系统\n";
				cin >> a;
				while (a == 1)
				{
					cout << "请选择方式进行订单查看\n1.订单编号\n2.手机号\n3.退出\n";
					cin >> b;
					if (b == 1)
					{
						cout << "请输入订单编号，例如11\n";
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
									cout << "总计花费：" << takeout[i].getconsumption() + 1 << "元" << endl;
									
									flag = 0;
								}
							}
							if (flag == 1)
							{
								cout << "没有查到此订单！\n";
								break;
							}
							else
							{
								int cz;
								cout << "请根据序号选择操作\n1.删除此订单\n2.修改此订单\n3.退出\n";
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
									takeout[k].setPhone("查无此单");
									pp++;
									cout << "订单已删除\n";
								}//删除订单	
								else if (cz == 2)
								{
									int u, v,w,x;
									cout << "例如你要修改份数，糖醋排骨菜品编号为1，显示在第三行，你点了2份，你要修改为3份，则输入1 3 3；如果不想要糖醋排骨了，则输入1 3 0！\n";
									cin >>w>> u >> v;
									x = takeout[k].bfood[u] - v;
									takeout[k].bfood[u] = v;
									menu.food[w].setSale(x);
									takeout[k].setConsumption(x * menu.food[w].getFoodprice() * menu.food[w].getDiscount());
									cout << "订单已修改\n";
								}//修改订单

							}
						}//偶数为外卖
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
									cout << "总计花费：" << restaurant1[i].getconsumption() + restaurant1[numberq].getbxf() << "元" << endl;
									flag = 0;
									k = i;
								}
							}
							if (flag == 1)
							{
								cout << "没有查到此订单！\n";
								break;
							}
							else
							{
								int cz;
								cout << "请根据序号选择操作\n1.删除此订单\n2.修改此订单\n3.退出\n";
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
									cout << "订单已删除\n";
								}//删除订单
								else if (cz == 2)
								{
									int u, v, w, x;
									cout << "例如你要修改份数，糖醋排骨菜品编号为1，显示在第三行，你点了2份，你要修改为3份，则输入1 3 3；如果不想要糖醋排骨了，则输入1 3 0！\n";
									cin >> w >> u >> v;
									x =  v-restaurant1[k].bfood[u] ;//变化的份数
									restaurant1[k].bfood[u] = v;//修改份数
									menu.food[w].setSale(x);//修改每种菜总份数
									restaurant1[k].setConsumption(x * menu.food[w].getFoodprice() * menu.food[w].getDiscount());
									cout << "订单已修改\n";
								}//修改订单
								
							}
						}//奇数为在店
					}
					else if (b == 2)
					{
						string f;
						cout << "请输入手机号，例如18967543562\n";
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
								cout << "总计花费：" << takeout[i].getconsumption() + 1 << "元" << endl;
								k = i;
								flag = 0;
							}
						}
						if (flag == 1)
						{
							cout << "没有查到此订单！\n";
							break;
						}
						else
						{
							int cz;
							cout << "请根据序号选择操作\n1.删除此订单\n2.修改此订单\n3.退出\n";
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
								takeout[k].setPhone("查无此单");
								pp++;
								cout << "订单已删除\n";
							}//删除订单
							else if (cz == 2)
							{
								int u, v, w, x;
								cout << "例如你要修改份数，糖醋排骨菜品编号为1，显示在第三行，你点了2份，你要修改为3份，则输入1 3 3；如果不想要糖醋排骨了，则输入1 3 0！\n";
								cin >> w >> u >> v;
								x = v - takeout[k].bfood[u];
								takeout[k].bfood[u] = v;
								menu.food[w].setSale(x);
								takeout[k].setConsumption(x * menu.food[w].getFoodprice() * menu.food[w].getDiscount());
								cout << "订单已修改\n";
							}//修改订单
							
						}
					}
					else if(b==3)
						break;
				}
				//订单
				while (a == 2)
				{
					int cz1;
					string foodn;
					double foodp, dis;
					cout << "请根据序号选择你想进行的操作\n1.添加菜品\n2.查看菜品信息\n3.退出\n";
					cin >> cz1;
					if (cz1 == 1)
					{
						cout << "请输入你要添加的菜品名称、菜品单价、菜品折扣，例如，糖醋排骨 2000 0.88\n";
						cin >> foodn >> foodp >> dis;
						menu.Add(foodn, foodp, dis);
						cout << "新菜品信息已添加完毕\n";
						File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
						for (int i = 1;i < menu.getFnum();i++)
						{
							File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
						}
						int o = menu.getFnum();
						File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
						File.close();//保存菜单信息
					}
					while (cz1 == 2)
					{
						int cz2;
						menu.Display();
						cout << "请根据序号选择你想进行的操作\n1.删除菜品\n2.修改某菜品单价\n3.修改某菜品折扣\n4.修改某菜品名称\n5.退出\n";
						cin >> cz2;
						if (cz2 == 1)
						{
							int bh;
							cout << "请输入要删除的菜品编号，例如糖醋排骨编号为5，则输入5\n";
							cin >> bh;
							menu.Delete(bh);
							cout << "菜品已删除！\n";
							File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
							for (int i = 1;i < menu.getFnum();i++)
							{
								File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
							}
							int o = menu.getFnum();
							File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
							File.close();//保存菜单信息
						}
						else if (cz2 == 2)
						{
							int bh;
							double dj;
							cout << "请输入你要修改的菜品编号以及期望的单价，例如你要修改糖醋排骨的价格为150元/份，则输入1 150\n";
							cin >> bh >> dj;
							menu.food[bh].setFoodprice(dj);
							cout << "已修改！\n";
							File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
							for (int i = 1;i < menu.getFnum();i++)
							{
								File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
							}
							int o = menu.getFnum();
							File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
							File.close();//保存菜单信息
						}
						else if (cz2 == 3)
						{
							int bh;
							double zc;
							cout << "请输入你要修改的菜品编号以及期望的折扣，例如你要修改糖醋排骨的折扣为0.12，则输入1 0.12\n";
							cin >> bh >> zc;
							menu.food[bh].setDiscount(zc);
							cout << "已修改！\n";
							File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
							for (int i = 1;i < menu.getFnum();i++)
							{
								File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
							}
							int o = menu.getFnum();
							File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
							File.close();//保存菜单信息
						}
						else if (cz2 == 4)
						{
							int bh;
							string mc;
							cout << "请输入你要修改的菜品编号以及期望的名称，例如你要修改糖醋排骨的名称为糖醋小排骨，则输入1 糖醋小排骨\n";
							cin >> bh >> mc;
							menu.food[bh].setFoodname(mc);
							cout << "已修改！\n";
							File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
							for (int i = 1;i < menu.getFnum();i++)
							{
								File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
							}
							int o = menu.getFnum();
							File << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
							File.close();//保存菜单信息
						}
						else if (cz2 == 5)
							break;
					}
					if (cz1 == 3)
						break;
				}
				//菜品
				if(a == 3)
				{
					string txt,aa,qq;
					char t(0);
					cout << "请输入你想查询的日期，例如2020-05-09\n";
					cin >> aa;
					txt= "D:\\project\\klxh design\\data\\" + aa + "Sell Condition.txt";
					File.open(txt, ios::_Nocreate);
					if (!File)
						cout << "查询失败，无该天销售详情\n";
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
				//销售情况
				if (a == 4)
					break;
			}
			break;
		}
		//管理员系统

		if(choice1 == 2)
		{
			
			while (true)
			{
				numberq++;
				int a,b,c,d,flag=1,e;
				cout << "1.在店就餐\n" << "2.外卖服务\n3.退出系统\n请选择就餐方式,或者退出顾客系统！\n";
				cin >> a;
				while(a == 1)
				{
					numberk[numberq] = 1;
					restaurant1[numberq].setczh(numberq);
					restaurant1[numberq].setnumber(numberq);
					if (flag == 1)
					{
						cout << "请问是否选择包厢就餐，是则输入1，否则输入2（普通餐桌就餐），包厢费为200元！\n";
						cin >> b;
						double bxf = 200;
						if (b == 1)
							restaurant1[numberq].setbxf(bxf);
					}
					menu.Display();
					cout << "请输入需要的菜品序号、份数，例如你要三份糖醋排骨，则输入1 3\n";
					cin >> c >> d;
					menu.food[c].setSale(d);
					restaurant1[numberq].hhnumber++;//每单进行多少次操作
					restaurant1[numberq].cconsumption(menu.food[c].getFoodprice(), d, menu.food[c].getDiscount());
					restaurant1[numberq].afood[restaurant1[numberq].hhnumber] = c;//每单按顺序存入每次操作的菜的序号
					restaurant1[numberq].bfood[restaurant1[numberq].hhnumber] = d;//每单按顺序存入每次操作的菜的份数
					cout << "1.继续点单\n2.提交订单\n请选择！\n";
					cin >> e;
					if (e == 2)
					{
						restaurant1[numberq].display();
						for (int j = 1;j <= restaurant1[numberq].hhnumber;j++)
						{
							int q = restaurant1[numberq].afood[j];
							cout << setw(10) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << restaurant1[numberq].bfood[j] << endl;
						}
						cout << "总计花费：" << restaurant1[numberq].getconsumption() + restaurant1[numberq].getbxf() << "元" << endl;
						break;
					}
					//提交订单
					else
						flag = 0;
				}
				//在店就餐
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
						cout << "请按顺序输入送餐地点、手机号，例如天堂路桂花小区118号 13988765456\n";
						cin >> a >> b;
						takeout[numberq].setfx(time1, a, b);
					}
					menu.Display();
					cout << "请输入需要的菜品序号、份数，例如你要三份糖醋排骨，则输入1 3\n";
					cin >> c>> d;
					menu.food[c].setSale(d);
					takeout[numberq].hhnumber++;
					takeout[numberq].cconsumption(menu.food[c].getFoodprice(), d, menu.food[c].getDiscount());
					takeout[numberq].afood[takeout[numberq].hhnumber] = c;
					takeout[numberq].bfood[takeout[numberq].hhnumber] = d;
					cout << "1.继续点单\n2.提交订单\n请选择！\n";
					cin >> e;
					if (e == 2)
					{
						takeout[numberq].display();
						for (int j = 1;j <= takeout[numberq].hhnumber;j++)
						{
							int q = takeout[numberq].afood[j];
							cout << setw(10) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << takeout[numberq].bfood[j] << endl;
						}
						cout << "总计花费：" << takeout[numberq].getconsumption() + 1<< "元"<<endl;
						break;
					}
					//提交订单
					else
						flag = 0;
				}
				//外卖就餐

				if (a == 3)
					break;
				//退出顾客系统
			}
			
		}
		//顾客系统

		if(choice1 == 3)
		{
			string a,txt1,txt2;
			double rs = 0, ts = 0;
			cout << "请输入今天的日期，例如2020-05-20\n";
			cin >> a;
			txt1 = "D:\\project\\klxh design\\data\\" + a + "order.txt";
			txt2 = "D:\\project\\klxh design\\data\\" + a + "Sell Condition.txt";
			File.open(txt1, ios::out, ios::_Noreplace);
			for (int i = 1;i < numberq;i++)
			{
				if (numberk[i] == 1)
				{
					File << setw(10) << "订单编号:" << restaurant1[i].getnumber() << setw(10) << "\t餐桌号：" << restaurant1[i].getczh() << setw(10) << "\t包厢费：" << restaurant1[i].getbxf()<< "元" << endl;
					File << setw(10) << "菜品编号" << setw(10) << "菜品名称" << setw(10) << "菜品单价" << setw(10) << "菜品折扣" << setw(10) << "菜品份数" << endl;
					for (int j = 1;j <= restaurant1[i].hhnumber;j++)
					{
						int q = restaurant1[i].afood[j];
						File << setw(10)<<resetiosflags(ios::left) << q << setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << restaurant1[i].bfood[j] << endl;
					}
					File<< "总计花费：" << restaurant1[i].getconsumption() + restaurant1[i].getbxf() << "元" << endl;
					rs = rs + restaurant1[i].getconsumption() + restaurant1[i].getbxf();
				}
				else if(numberk[i]==2)
				{
					File << setw(10) << "订单编号:" << takeout[i].getnumber() << setw(10) << "\t手机号：" << takeout[i].getPhone()<< endl;
					File << setw(10) << "送餐时间：" << takeout[i].getScsj()<< setw(10) << "分钟\t送餐地点：" << takeout[i].getScdd()<< setw(10) << "\t外卖费：本店大本经营，合理范围内外卖费均为1元!" << endl;
					File << setw(10) << "菜品编号" << setw(10) << "菜品名称" << setw(10) << "菜品单价" << setw(10) << "菜品折扣" << setw(10) << "菜品份数" << endl;
					for (int j = 1;j <= takeout[i].hhnumber;j++)
					{
						int q = takeout[i].afood[j];
						File << setw(10) <<resetiosflags(ios::left) << q<< setw(10) << menu.food[q].getFoodName() << setw(10) << menu.food[q].getFoodprice() << setw(10) << menu.food[q].getDiscount() << setw(10) << takeout[i].bfood[j] << endl;
					}
					File<< "总计花费：" << takeout[i].getconsumption() + 1 << "元" << endl;
					ts = ts + takeout[i].getconsumption() + 1;
				}
			}
			File << "今日订单详情如上";
			File.close();//保存订单信息

			//File.open("D:\\project\\klxh design\\data\\menu.txt", ios::out);
			//for (int i= 1;i<menu.getFnum();i++)
			//{
				//File << setiosflags(ios::left) << menu.food[i].getFoodName() << "\t" << menu.food[i].getFoodprice() << "\t" << menu.food[i].getDiscount() << endl;
			//}
			//int o = menu.getFnum();
			//File  << setiosflags(ios::left) << menu.food[o].getFoodName() << "\t" << menu.food[o].getFoodprice() << "\t" << menu.food[o].getDiscount();
			//File.close();//保存菜单信息

			File.open(txt2, ios::out, ios::_Noreplace);
			File << a << "销售情况\n";
			File << "共计接单：\t" << numberq - 1 -pp<< endl;
			File << setw(10) << setiosflags(ios::left) << "菜品名称" << setw(10) << "菜品价格" << setw(10) << "菜品折扣" << setw(10) << "销售份数" << endl;
			
			for (int i = 1;i <= menu.getFnum();i++)
			{
				File << setw(10)<< setiosflags(ios::left) << menu.food[i].getFoodName() << setw(10) << menu.food[i].getFoodprice() << setw(10) << menu.food[i].getDiscount() << menu.food[i].getSale()<<endl;
				
			}
			File<< "共计销售额：\t" << ts + rs <<"元"<< endl;
			File << "在店销售额：\t" << rs << "元\t占比：\t" << setprecision(4) << rs / (ts + rs)*100<< "%\n";
			File << "外卖销售额：\t" <<setprecision(100)<< ts << "元\t占比：\t" << setprecision(4) << ts / (ts + rs) * 100 <<"%\n";
			File.close();
			//保存销售详情
			break;
		}
		//退出系统
	}
	return 0;
}