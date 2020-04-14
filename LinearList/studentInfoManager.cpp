#include "studentInfoManager.h"
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;

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
	printf("输入文件名，默认为balabala.dat:");
	string fileName;
	cin >> fileName;
	base.readFromFile(fileName);
}

void StudentInfoManager::saveTofile()
{
}

void StudentInfoManager::printAll()
{

}

void StudentInfoManager::query()
{
	system("cls");
	int opt = getOpt();
	switch (opt)
	{
	case 0:
		readFromFile();
		break;
	}
}

void StudentInfoManager::Insert()
{
}

void StudentInfoManager::Erase()
{
}

void StudentInfoManager::SaveAndExit()
{
	saveTofile();
}

StudentInfoManager::StudentInfoManager()
{
}

void StudentInfoManager::queryByName()
{

}

void StudentInfoManager::queryById()
{
}

void StudentInfoManager::queryBySchoolIDd()
{

}

void StudentInfoManager::printStudent(const Student& student)
{
}


