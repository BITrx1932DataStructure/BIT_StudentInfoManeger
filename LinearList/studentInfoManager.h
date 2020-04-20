#pragma once

#include<string>
#include"student.h"
#include"studentContainer.h"

class StudentInfoManager :StudentContainer
{
public:
	using StudentContainer::iterator;
	using StudentContainer::size;
private:
	using StudentContainer::insert;
	using StudentContainer::erase;
	using StudentContainer::readFromFile;
	using StudentContainer::saveToFile;
	using StudentContainer::queryByName;
	using StudentContainer::queryById;
	using StudentContainer::queryBySchoolId;
public:

	//初始化
	void init();

	//输出主菜单
	void printMenu();

	//选项错误时执行该函数
	//void optErro();

	//从文件读取
	void readFromFile();

	//输出所有学生
	void printAll();

	//查询（先查绚，再选择修改或删除或什么也不做）
	void query();

	//增加学生
	void insert();

	//保存到文件
	void saveToFile();

	//保存并退出
	void saveAndExit();

	StudentInfoManager();
	~StudentInfoManager() = default;
private:

	void afterQuery();
	void studentNotExist();
	bool checkFileName(string fileName);
	void erase();//删除学生
	void edit();//修改学生
	iterator queryByName();//通过姓名查询
	iterator queryById();//通过身份证号查询
	iterator queryBySchoolId();//通过学号查询
	void printStudent(iterator it);//输出学生信息
	void printQueryMenu();
	void printAfterQueryMenu();

	iterator thisStudent;
};