#include "studentInfoManager.h"
#include<conio.h>
//#include"studentContainer.h"
#include"control.h"
#include<iostream>
#include<cstdlib>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;

void StudentInfoManager::init()
{
	system("color F0");//设置为白底黑字
}

void StudentInfoManager::printMenu()
{
	cout << "*****************" << endl;
	cout << "1. 加载学生信息" << endl;
	cout << "2. 查询学生信息" << endl;
	cout << "3. 添加学生信息" << endl;
	cout << "4. 保存到文件" << endl;
	cout << "5. 退出系统" << endl;
	cout << "*****************" << endl;
}

/*
void StudentInfoManager::optErro()
{
	cout << "输入错误！" << endl;
}
*/

void StudentInfoManager::readFromFile()
{
	clear();

	cout << "从文件加载" << endl;
	cout << "输入文件名:\n-->";
	string fileName;
	getline(cin, fileName);
	if (fileName.empty())
		fileName = "student.dat";//默认文件名
	if (!checkFileName(fileName))
	{
		cout << "重新输入文件名:-->\n";
	}
	readFromFile(fileName);
}

void StudentInfoManager::afterQuery()
{
	cout << "1.继续查询" << endl;
	cout << "2.修改信息" << endl;
	cout << "3.删除学生" << endl;
	cout << "4.返回菜单" << endl;
	//TODO 完成afterQuery函数
}

void StudentInfoManager::studentNotExist()
{
	cout << "所查询的学生不存在\n敲击键盘退出.." << endl;
	_getch();
}

bool StudentInfoManager::checkFileName(string fileName)
{
	return true;
}

void StudentInfoManager::saveToFile()
{
	printf("输入文件名:\n-->");
	string fileName;
	getline(cin, fileName);
	if (fileName.empty())
		fileName = "student.dat";//默认文件名
	if (!checkFileName(fileName))
	{
		cout << "重新输入文件名:-->\n";
	}
	saveToFile(fileName);
}

void StudentInfoManager::printAll()
{

}

void StudentInfoManager::query()
{
	//clear();
	int opt;
	cout << "请选择查询方式" << endl;
	cout << "1.以姓名查询" << endl;
	cout << "2.以身份证号查询" << endl;
	cout << "3.以学号查询" << endl;
	cin >> opt;
	switch (opt)
	{
	case 1:
		queryByName();
		break;
	case 2:
		queryById();
		break;
	case 3:
		queryBySchoolId();
		break;
	}

}

void StudentInfoManager::insert()
{

}

void StudentInfoManager::erase()
{
}

void StudentInfoManager::saveAndExit()
{
	saveToFile();
}

StudentInfoManager::StudentInfoManager()
{
}
void StudentInfoManager::queryByName()
{
	string name;
	cin >> name;
	Student temp;
	temp = queryByName(name);
	if (temp.name == "default")
		studentNotExist();
	else
		printStudent(temp);
}
void StudentInfoManager::queryById()
{
	string ID;
	cin >> ID;
	Student temp;
	temp = queryById(ID);
	if (temp.id == "default")
		studentNotExist();
	else
		printStudent(temp);
}

void StudentInfoManager::queryBySchoolId()
{
	string SchoolID;
	cin >> SchoolID;
	Student temp;
	temp = queryBySchoolId(SchoolID);
	if (temp.schoolId == "default")
		studentNotExist();
	else
		printStudent(temp);
}

void StudentInfoManager::printStudent(const Student& student)
{
	cout << student.name << endl;
	cout << student.id << endl;
	cout << student.schoolId << endl;
	cout << student.sex << endl;
	cout << student.address << endl;
	cout << student.age << endl;
	cout << student.birth << endl;
	cout << student.phone << endl;
}


