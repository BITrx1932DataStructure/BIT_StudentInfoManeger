#include<iostream>
#include"studentInfoManager.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "加载中..." << endl;
	StudentInfoManager stu;
	int opt = 0;
	stu.init();
	bool whileFlag = 1;
	while (whileFlag)
	{
		system("cls");
		stu.printMenu();
		opt = stu.getOpt();
		cout << "opt=" << opt << endl;
		switch (opt)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			stu.insert();
			break;
		case 4:
			stu.SaveAndExit();
			whileFlag = 0;
			break;
		default:
			stu.optErro();
			break;
		}
	}
	return 0;
}
