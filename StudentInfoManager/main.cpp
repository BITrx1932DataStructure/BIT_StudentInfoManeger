#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<ctime>
#include<fstream>
#include"studentInfoManager.h"
#include"control.h"

using std::cin;
using std::cout;
using std::endl;


int main(int argc, char** argv)
{
	char input[100];
	char output[100];
	char log[100];
	sprintf(input, "in\\%s.in", argv[1]);
	sprintf(output, "out\\%s.out", argv[1]);
	sprintf(log, "log\\%s.log", argv[1]);
	freopen(input, "r", stdin);
	freopen(log, "w", stdout);
	std::ofstream fout(output, std::ios::app);

	auto s_time = clock();
	clock_t s_time_ = 0;
	clock_t t_time_ = 0;

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
			s_time_ = clock();
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
			t_time_ = clock();
			stu.saveAndExit();
			whileFlag = 0;
			break;
		}
	}

	fout << "size=" << stu.size() << endl;
	int t_time = clock();
	if (argc > 2) fout << argv[2] << endl;
	fout << "readFromFile:" << s_time_ - s_time << endl;
	fout << "operation:" << t_time_ - s_time_ << endl;
	fout << "saveTofile:" << t_time - t_time_ << endl;
	fout.close();

	cout << endl;
	return 0;
}


