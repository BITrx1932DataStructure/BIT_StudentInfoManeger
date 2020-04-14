#pragma once
#include<string>
#include"student.h"
#include"studentContainer.h"

class StudentInfoManager :StudentContainer
{
public:
	void init();//初始化
	void printMenu();//输出主菜单
	int getOpt();//输入选项
	void optErro();//选项错误时执行该函数

	void readFromFile();//从文件读取
	void printAll();//输出所有学生
	void query();//查询（先查绚，再选择修改或删除或什么也不做）
	void Insert();//增加学生
	void SaveAndExit();//保存并退出

	StudentInfoManager();
	~StudentInfoManager() = default;
private:
	StudentContainer base;

	void saveTofile();//保存到文件
	void Erase();//删除学生
	void queryByName();//通过姓名查询
	void queryById();//通过身份证号查询
	void queryBySchoolIDd();//通过学号查询
	void printStudent(const Student& student);//输出学生信息
};