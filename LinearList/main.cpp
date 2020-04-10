#include<iostream>
#include"studentInfoManager.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	StudentInfoManager stu;
	int opt = 0;
	stu.init();
	bool whileFlag = 1;//控制while循环
	while (whileFlag)
	{
		system("cls");//清空控制台
		stu.printMenu();
		opt = stu.getOpt();
		switch (opt)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:

			break;
		case 4:

			break;
		default:

			break;
		}
	}
	return 0;
}
