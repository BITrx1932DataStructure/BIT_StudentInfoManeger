#pragma once
#include<string>
#include"student.h"
#include"vector.h"
#include"control.h"

using std::string;
using container = fy::vector<Student>;

class StudentInfoManager :container, Control
{
public:
	void init();
	void printMenu();
	int getOpt();
	void optErro();

	void readFromFile();
	void printAll();
	void query();
	void insert();
	bool exit();

	StudentInfoManager();
	~StudentInfoManager() = default;
private:
	bool _exitFlag;
	static const string _fileName;
	int _opt;
	Menu mainMenu;

	void saveTofile();
	void erase();
	void queryByName(const string& name);
	void queryById(const string& id);
	void queryBySchoolIDd(const string& schoolId);
	void print(const Student& student);

};