#pragma once

#include"vector.h"
#include"student.h"

using Container = fy::vector<Student>;

class StudentContainer :Container
{
public:
	using Container::iterator;
private:
	using Container::erase;
public:


	iterator queryByName(string Name);
	iterator queryById(string ID);
	iterator queryBySchoolId(string SchoolID);
	void erase(Student student);
	void insert(Student student);
	void readFromFile(string fileName);
	void saveToFile(string fileName);

private:
};