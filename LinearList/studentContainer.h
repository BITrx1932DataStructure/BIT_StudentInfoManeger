#pragma once

#include"vector.h"
#include"student.h"


using Container = fy::vector<Student>;

class StudentContainer :Container
{
	using Container::erase;
public:
	Student queryByName(string Name);
	Student queryById(string ID);
	Student queryBySchoolId(string SchoolID);
	void erase(Student student);;
	void insert(Student student);;
	void readFromFile(string fileName);;
	void saveToFile(string fileName);;

private:
};