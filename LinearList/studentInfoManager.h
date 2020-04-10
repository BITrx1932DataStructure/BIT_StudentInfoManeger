#pragma once
#include<string>
#include"student.h"
#include"StudentInfoManagerBase.h"

class StudentInfoManager :StudentInfoManagerBase
{
public:
	void init();//初始化
	void printMenu();//输出主菜单
	int getOpt();//输入选项
	void optErro();//选项错误时执行该函数

	void readFromFile();//从文件读取
	void printAll();//输出所有学生
	void query();//查询（先查绚，再选择修改或删除或什么也不做）
	void insert();//增加学生
	void SaveAndExit();//保存并退出

	StudentInfoManager();
	~StudentInfoManager() = default;
private:

	void saveTofile();//保存到文件
	void erase();//删除学生
	void queryByName(const string& name);//通过姓名查询
	void queryById(const string& id);//通过身份证号查询
	void queryBySchoolIDd(const string& schoolId);//通过学号查询
	void printStudent(const int x, const int y, const Student& student);//输出学生信息
};