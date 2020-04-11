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
	mainMenu.add("1. 从文件加载");
	mainMenu.add("2. 所有学生信息");
	mainMenu.add("3. 查询学生信息");
	mainMenu.add("4. 添加学生信息");
	mainMenu.add("5. 保存并退出系统");
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
}

void StudentInfoManager::erase()
{
}

bool StudentInfoManager::exit()
{
	return _exitFlag;
}

StudentInfoManager::StudentInfoManager() :mainMenu(0, 25), _exitFlag(false), _opt(0)
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

void StudentInfoManager::print(const Student& student)
{
}
