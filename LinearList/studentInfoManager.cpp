#include "studentInfoManager.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

const string StudentInfoManager::_fileName("stuData.dat");

void StudentInfoManager::init()
{
	setSize(100, 200);
	system("color F0");
	mainMenu.add("1. ���ļ�����");
	mainMenu.add("2. ����ѧ����Ϣ");
	mainMenu.add("3. ��ѯѧ����Ϣ");
	mainMenu.add("4. ���ѧ����Ϣ");
	mainMenu.add("5. ���沢�˳�ϵͳ");
}

void StudentInfoManager::printMenu()
{
	mainMenu.show(0, 0);
	return;
	clear();
	cout << "1. ���ļ�����" << endl;
	cout << "2. ����ѧ����Ϣ" << endl;
	cout << "3. ��ѯѧ����Ϣ" << endl;
	cout << "4. ���ѧ����Ϣ" << endl;
	cout << "5. ���沢�˳�ϵͳ" << endl;
	cout << "�������--";
}

int StudentInfoManager::getOpt()
{
	return mainMenu.getOpt();
}

void StudentInfoManager::optErro()
{
	cout << "���������" << endl;
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
