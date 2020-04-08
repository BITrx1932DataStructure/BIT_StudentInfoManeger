#include "studentInfoManager.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

const string StudentInfoManager::_fileName("stuData.dat");

void StudentInfoManager::init()
{
	printf("init");
	setSize(100, 200);
}

void StudentInfoManager::printMenu()
{
	clear();
	cout << "1. 从文件加载" << endl;
	cout << "2. 所有学生信息" << endl;
	cout << "3. 查询学生信息" << endl;
	cout << "4. 添加学生信息" << endl;
	cout << "5. 保存并退出系统" << endl;
	cout << "输入序号--";
}

int StudentInfoManager::getOpt()
{
	cin >> _opt;
	return _opt;
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
