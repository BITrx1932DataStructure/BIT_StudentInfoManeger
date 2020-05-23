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
	cout << "加载中..." << endl;
	readFromFile("student.dat");
	cout << "成功加载" << size() << "个学生信息" << endl;
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
	int opt;
	clearCmd();
	printStudent(thisStudent);
	printAfterQueryMenu();
	cin >> opt;
	switch (opt)
	{
	case 1:
		break;
	case 2:
		edit();
		break;
	case 3:
		erase();
		break;
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
	cin >> student.name;
	getchar();
	cout << "身份证号：" << endl;
	getline(cin, student.id);
	cout << "学号：" << endl;
	getline(cin, student.schoolId);
	cout << "性别：" << endl;
	getline(cin, student.sex);
	cout << "地址：" << endl;
	getline(cin, student.address);
	cout << "年龄：" << endl;
	getline(cin, student.age);
	cout << "生日：" << endl;
	getline(cin, student.birth);
	cout << "电话号码：" << endl;
	getline(cin, student.phone);
	//TODO:输入其他数据项
	insert(student);
}

void StudentInfoManager::erase()
{
	cout << "即将删除学生：";
	//printStudent(thisStudent);
	cout << "Y/N?" << endl;
	char opt;
	cin >> opt;
	if (opt == 'Y')
		erase(thisStudent);
}

void StudentInfoManager::edit()
{
	int m, n = 1;
	while (n == 1)
	{
		cout << "请输入相应序号，选择要修改的内容" << endl;
		cout << "1.姓名" << endl;
		cout << "2.身份证号" << endl;
		cout << "3.学号" << endl;
		cout << "4.性别" << endl;
		cout << "5.地址" << endl;
		cout << "6.年龄" << endl;
		cout << "7.生日" << endl;
		cout << "8.电话号码" << endl;
		cout << "9.取消修改" << endl;
		cin >> m;
		switch (m)
		{
		case 1:
			cin >> thisStudent->name;
			break;
		case 2:
			cin >> thisStudent->id;
			break;
		case 3:
			cin >> thisStudent->schoolId;
			break;
		case 4:
			cin >> thisStudent->sex;
			break;
		case 5:
			cin >> thisStudent->address;
			break;
		case 6:
			cin >> thisStudent->age;
			break;
		case 7:
			cin >> thisStudent->birth;
			break;
		case 8:
			cin >> thisStudent->phone;
			break;
		case 9:
			break;
		}
		if (m != 9)
			cout << "修改成功" << endl;
		cout << "是否继续修改本学生数据？\n继续修改，请输入1；保存修改，请输入0" << endl;
		cin >> n;
	}
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
	cout << "    姓名：";
	cout << it->name << endl;
	cout << "身份证号：";
	cout << it->id << endl;
	cout << "    学号：";
	cout << it->schoolId << endl;
	cout << "    性别：";
	cout << it->sex << endl;
	cout << "    地址：";
	cout << it->address << endl;
	cout << "    年龄：";
	cout << it->age << endl;
	cout << "    生日：";
	cout << it->birth << endl;
	cout << "    电话号码：";
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


