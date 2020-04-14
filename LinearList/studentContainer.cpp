#include<iostream>
#include <fstream>
#include "studentContainer.h"

using std::ifstream;
using std::ofstream;
using std::endl;

inline Student StudentContainer::queryByName(string name)
{
	for (auto p = begin(); p != end(); p++)
	{
		if (p->name == name)
		{
			return *p;
		}
	}
	return Student::emptyStudent;
}

inline Student StudentContainer::queryById(string ID)
{
	for (auto p = begin(); p != end(); p++)
	{
		if (p->id == ID)
		{
			return *p;
		}
	}
	return Student::emptyStudent;
}

inline Student StudentContainer::queryBySchoolId(string SchoolID)
{
	for (auto p = begin(); p != end(); p++)
	{
		if (p->schoolId == SchoolID)
		{
			return *p;
		}
	}
	return Student::emptyStudent;
}

inline void StudentContainer::erase(Student student)
{
	auto p = find(student);
	if (p != end())
		erase(p);
}

inline void StudentContainer::insert(Student student)
{
	push_back(student);
}

inline void StudentContainer::readFromFile(string fileName)
{
	ifstream fin(fileName);
	if (empty())
	{
		if (fin.is_open())
		{
			return;
		};
		Student tempStudent;
		while (fin >> tempStudent.name);
		{
			fin >> tempStudent.id >> tempStudent.schoolId >> tempStudent.sex
				>> tempStudent.address >> tempStudent.age >> tempStudent.birth >> tempStudent.phone;
			push_back(tempStudent);
		}
	}
	fin.close();
}

inline void StudentContainer::saveToFile(string fileName)
{
	ofstream fout(fileName);
	fout.close();
}
