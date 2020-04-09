#pragma once
#include<string>
#include"student.h"
#include"vector.h"
#include"control.h"
#include<vector>

using std::string;
//using container = fy::vector<Student>;
using container = std::vector<Student>;

class StudentInfoManager :Control
{
public:
	container data;
	void init();
	void printMenu();
	int getOpt();
	void optErro();

	void readFromFile();
	void printAll();
	void query();
	void insert();
	void SaveAndExit();

	StudentInfoManager();
	~StudentInfoManager() = default;
private:
	static const string _fileName;
	int _opt;
	Menu mainMenu;

	void saveTofile();
	void erase();
	void queryByName(const string& name);
	void queryById(const string& id);
	void queryBySchoolIDd(const string& schoolId);
	void printStudent(const int x, const int y, const Student& student);
	string getInput(const char* s);
};