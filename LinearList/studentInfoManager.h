#pragma once

#include<string>
#include"student.h"
#include"studentContainer.h"

class StudentInfoManager :StudentContainer
{
	using StudentContainer::insert;
	using StudentContainer::erase;
	using StudentContainer::readFromFile;
	using StudentContainer::saveToFile;
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

	bool checkFileName(string fileName);
	void erase();//删除学生
	void queryByName();//通过姓名查询
	void queryById();//通过身份证号查询
	void queryBySchoolIDd();//通过学号查询
	void printStudent(const Student& student);//输出学生信息
};