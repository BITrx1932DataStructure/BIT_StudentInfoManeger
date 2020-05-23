#include"studentInfoManager.h"
#include"control.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	StudentInfoManager stu;
	stu.init();//初始化
	bool whileFlag = 1;//控制while循环
	while (whileFlag)
	{
		clearCmd();
		stu.printMenu();//输出主菜单
		int opt;
		cin >> opt;//输入选项
		getchar();
		switch (opt)
		{
		case 1:
			stu.readFromFile();
			break;
		case 2:
			stu.query();
			break;
		case 3:
			stu.insert();
			break;
		case 4:
			stu.saveToFile();
			break;
		case 5:
			stu.saveAndExit();
			whileFlag = 0;
			break;
		}
	}
	return 0;
}


