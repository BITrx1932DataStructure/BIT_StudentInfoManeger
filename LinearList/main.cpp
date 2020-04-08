#include<iostream>
#include"studentInfoManager.h"

int main()
{
	StudentInfoManager stu;
	int opt = 0;
	stu.init();
	while (!stu.exit())
	{
		stu.printMenu();
		opt = stu.getOpt();
		switch (opt)
		{
		case 1:

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			stu.optErro();
			break;

		}
	}
	return 0;
}
