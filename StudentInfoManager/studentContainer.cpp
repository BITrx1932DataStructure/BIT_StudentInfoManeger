#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include<conio.h>
#include "studentContainer.h"

using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;

StudentContainer::iterator StudentContainer::queryByName(string name)
{
	for (auto p = begin(); p != end(); p++)
		if (p->name == name)
			return p;
	return nullptr;
}

StudentContainer::iterator StudentContainer::queryById(string ID)
{
	for (auto p = begin(); p != end(); p++)
		if (p->id == ID)
			return p;
	return nullptr;
}

StudentContainer::iterator StudentContainer::queryBySchoolId(string SchoolID)
{
	for (auto p = begin(); p != end(); p++)
		if (p->schoolId == SchoolID)
			return p;
	return nullptr;
}

void StudentContainer::erase(Student student)
{
	auto p = find(student);
	if (p != end())
		erase(p);
}

void StudentContainer::insert(Student student)
{
	push_back(student);
}

void StudentContainer::readFromFile(string fileName)
{
	ifstream fin(fileName);
	if (!fin.is_open())
	{
		cout << "文件打开错误" << endl;
		getchar();
		return;
	};
	Student tempStudent;
	while (fin >> tempStudent)
		push_back(tempStudent);
	fin.close();
}

void StudentContainer::saveToFile(string fileName)
{
	char* buf = new char[10000000];
	char* p = buf;
	FILE* fout = fopen(fileName.c_str(), "w");
	string temp;
	for (int i = 0; i < size(); i++)
	{
		temp = operator[](i).to_string();
		strcpy(p, temp.c_str());
		p += temp.length();
		if (i % 50000 == 0)
		{
			fwrite(buf, sizeof(char), p - buf, fout);
			p = buf;
		}
	}
	fwrite(buf, sizeof(char), p - buf, fout);
	delete[] buf;
}
