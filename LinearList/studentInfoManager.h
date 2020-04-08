#pragma once
#include<string>
#include"student.h"
#include"vector.h"

using std::string;

class StudentInfoManager :fy::vector<Student>
{
public:
	void printMenu();

	void readFromFile();
	void saveTofile();
	void printAll();
	void insert();
	void erase();
	void exit();

	StudentInfoManager() :exitFlag(0)
	{
	}
	~StudentInfoManager() = default;
private:
	int exitFlag;
	static const string fileName;

	void queryByName(const string& name);
	void queryById(const string& id);
	void queryBySchoolIDd(const string& schoolId);
	void print(const Student& student);

};