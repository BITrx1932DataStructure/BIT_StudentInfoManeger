#include "studentInfoManager.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

const string StudentInfoManager::_fileName("stuData.dat");

void StudentInfoManager::init()
{
	system("color F0");//设置为白底黑字
}

void StudentInfoManager::printMenu()
{

}

int StudentInfoManager::getOpt()
{
	int opt;
	cin >> opt;
	return opt;
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

void StudentInfoManager::SaveAndExit()
{
	saveTofile();
}

StudentInfoManager::StudentInfoManager()
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

}

