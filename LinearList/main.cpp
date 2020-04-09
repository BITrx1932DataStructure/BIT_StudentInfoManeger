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
	while (!stu.exit())
	{
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
			break;
		case 4:
			break;
		default:
			stu.optErro();
			break;
		}
	}
	return 0;
}
