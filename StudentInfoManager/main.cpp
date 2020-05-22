#define _CRT_SECURE_NO_WARNINGS
#include"studentInfoManager.h"
#include"control.h"
#include<iostream>
#include<stdio.h>
#include<time.h>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	
	freopen("C:\\Users\\asus\\Desktop\\xueshengkongzhi.txt", "r",stdin);
	//freopen("C:\\Users\\asus\\Desktop\\shuchu.txt", "w", stdout);
	int Ti_me1 = clock();
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
	fclose(stdin);
	//fclose(stdout);
	int Ti_me2 = clock();
	cout << Ti_me2 - Ti_me1;
	return 0;
}


