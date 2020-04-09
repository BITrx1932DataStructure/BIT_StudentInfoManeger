#include "studentInfoManager.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

const string StudentInfoManager::_fileName("stuData.dat");

void StudentInfoManager::init()
{
	setSize(50, 50);
#ifndef _DEBUG
	hideCursor();
#endif //fy2
	system("color F0");
	mainMenu.add("从文件加载");
	mainMenu.add("所有学生信息");
	mainMenu.add("查询学生信息");
	mainMenu.add("添加学生信息");
	mainMenu.add("保存并退出系统");
}

void StudentInfoManager::printMenu()
{
	mainMenu.show();
}

int StudentInfoManager::getOpt()
{
	return mainMenu.getOpt();
}

void StudentInfoManager::optErro()
{
	cout << "！输入错误！" << endl;
}

void StudentInfoManager::readFromFile()
{
}

void StudentInfoManager::saveTofile()
{
}

void StudentInfoManager::printAll()
{

}

void StudentInfoManager::query()
{
}

void StudentInfoManager::insert()
{
	clear();
	Menu menu(10, 25);
	menu.add("编辑姓名");
	menu.add("编辑性别");
	menu.add("编辑身份证号");
	menu.add("编辑学号");
	menu.add("编辑家庭住址");
	menu.add("编辑电话号码");
	menu.add("确定");
	menu.add("取消");
	Student studentTemp;
	string temp;
	int opt;
	int whileFlag = 1;
	while (whileFlag)
	{
		printStudent(0, 0, studentTemp);
		opt = menu.getOpt();
		switch (opt)
		{
		case 0:
			studentTemp.name = getInput("姓名");
			break;
		case 1:
			temp = getInput("性别");
			if (temp == "男" || temp == "nan" || temp == "1")
				studentTemp.sex = "男";
			else if (temp == "女" || temp == "nv" || temp == "0")
				studentTemp.sex = "女";
			else
				studentTemp.sex = "未知";
			break;
		case 2:
			studentTemp.id = getInput("身份证号");
			break;
		case 3:
			studentTemp.schoolId = getInput("学号");
			break;
		case 4:
			studentTemp.address = getInput("家庭住址");
			break;
		case 5:
			studentTemp.phone = getInput("电话号码");
			break;
		case 6:
			cout << "向容器中添加学生";
			whileFlag = 0;
			break;
		case 7:
			break;
		}
	}
}

void StudentInfoManager::erase()
{
}

void StudentInfoManager::SaveAndExit()
{
	saveTofile();
}

StudentInfoManager::StudentInfoManager() :mainMenu(0, 25), _opt(0)
{
}

void StudentInfoManager::queryByName(const string& name)
{

}

void StudentInfoManager::queryById(const string& id)
{
}

void StudentInfoManager::queryBySchoolIDd(const string& schoolId)
{
}

void StudentInfoManager::printStudent(const int x, const int y, const Student& student)
{
	print(x, y, "姓名"), print(x, y + 10, student.name.c_str());
	print(x + 1, y, "性别"), print(x + 1, y + 10, student.sex.c_str());
	print(x + 2, y, "学号"), print(x + 2, y + 10, student.schoolId.c_str());
	print(x + 3, y, "身份证号"), print(x + 3, y + 10, student.id.c_str());
	print(x + 4, y, "家庭住址"), print(x + 4, y + 10, student.address.c_str());
	print(x + 5, y, "电话号码"), print(x + 5, y + 10, student.phone.c_str());
}

string StudentInfoManager::getInput(const char* s)
{
	clear();
	print(0, 25, "请输入：", TEXT_MID);
	print(3, 25, s, TEXT_MID);
	print(5, 20, "-->", TEXT_RIGHT);
	print(5, 30, "<--", TEXT_LEFT);
	setPos(5, 21);
	static string temp;
	cin >> temp;
	return temp;
}
