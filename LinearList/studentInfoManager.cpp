#include "studentInfoManager.h"
#include<conio.h>
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
	system("title 学生信息管理系统 v1.0");
	readFromFile("student.dat");
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
	clearCmd();

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
	int whileFlag = 1;
	int opt;
	while (whileFlag)
	{
		clearCmd();
		printStudent(thisStudent);
		printAfterQueryMenu();
		cin >> opt;
		switch (opt)
		{
		case 1:
			whileFlag = 0;
			break;
		case 2:
			edit();
			break;
		case 3:
			erase();
			break;
		}
	}
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
	int whileFlag = 1;
	int opt;
	while (whileFlag)
	{
		clearCmd();
		printQueryMenu();
		cin >> opt;
		iterator it(nullptr);
		switch (opt)
		{
		case 1:
			it = queryByName();
			break;
		case 2:
			it = queryById();
			break;
		case 3:
			it = queryBySchoolId();
			break;
		case 4:
			whileFlag = 0;
			break;
		}
		if (whileFlag)
		{
			if (it == nullptr)
				studentNotExist();
			else
			{
				printStudent(it);
				thisStudent = it;
				afterQuery();
			}
		}
	}
}

void StudentInfoManager::insert()
{
	Student student;
	cout << "姓名：" << endl;
	getline(cin, student.name);
	//TODO:输入其他数据项
	insert(student);
}

void StudentInfoManager::erase()
{
	cout << "即将删除学生：";
	printStudent(thisStudent);
	cout << "Y/N?" << endl;
	char opt;
	cin >> opt;
	if (opt == 'Y')
		erase(thisStudent);
}

void StudentInfoManager::edit()
{
	//TODO:修改thisStudent指向的内容
}

void StudentInfoManager::saveAndExit()
{
	saveToFile();
}

StudentInfoManager::StudentInfoManager() :thisStudent(0)
{
}
StudentInfoManager::iterator StudentInfoManager::queryByName()
{
	cout << "请输入姓名:" << endl;
	string name;
	cin >> name;
	return queryByName(name);
}
StudentInfoManager::iterator StudentInfoManager::queryById()
{
	cout << "请输入身份证号:" << endl;
	string ID;
	cin >> ID;
	return queryById(ID);
}

StudentInfoManager::iterator StudentInfoManager::queryBySchoolId()
{
	cout << "请输入学号:" << endl;
	string SchoolID;
	cin >> SchoolID;
	return queryBySchoolId(SchoolID);
}

void StudentInfoManager::printStudent(StudentInfoManager::iterator it)
{
	cout << it->name << endl;
	cout << it->id << endl;
	cout << it->schoolId << endl;
	cout << it->sex << endl;
	cout << it->address << endl;
	cout << it->age << endl;
	cout << it->birth << endl;
	cout << it->phone << endl;
}

void StudentInfoManager::printQueryMenu()
{
	cout << "请选择查询方式" << endl;
	cout << "1.以姓名查询" << endl;
	cout << "2.以身份证号查询" << endl;
	cout << "3.以学号查询" << endl;
	cout << "4.返回主菜单" << endl;
}

void StudentInfoManager::printAfterQueryMenu()
{
	cout << "1.继续查询" << endl;
	cout << "2.修改信息" << endl;
	cout << "3.删除学生" << endl;
}


