#pragma once
#include"vector.h"
#include"student.h"
#include<iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using Container = fy::vector<Student>;
using namespace std;
class StudentInfoManagerBase :Container
{
public:
	Student QueryByName(string Name)
	{
		iterator p;
		for (p = a.begin; p != a.end; p++)
		{
			if (p->name == Name)
			{
				cout << "Namefounded\n";
				printStudent(*p);
			}
		}
	};
	Student QueryById(string ID)
	{
		iterator p;
		for (p = a.begin; p != a.end; p++)
		{
			if (p->id == ID)
			{
				cout << "IDfounded\n";
				printStudent(*p);
			}
		}
	};
	Student QueryBySchoolId(string SchoolID)
	{
		iterator p;
		for (p = a.begin; p != a.end; p++)
		{
			if (p->schoolId == SchoolID)
			{
				cout << "SchoolIDfounded\n";
				printStudent(*p);
			}
		}
	};
	void Erase(Student student)
	{
		iterator p;
		if (p = a.find(student))
			erase(p);
		else cout << "error";

	};
	void Insert(Student student)
	{
		a.push_back(student);
	};
	void readFromFile(string fileName)
	{
		/*using type_name = string;
		using type_id = string;
		using type_sex = string;
		using type_address = string;
		using type_age = unsigned int;
		using type_birth = Date;
		using type_phone = string;
		using type_schoolId = string;
		type_name name;
		type_id id;
		type_id schoolId;
		type_sex sex;
		type_address address;
		type_age age;
		type_birth birth;
		type_phone phone;*/
		if (a.empty)
		{
			file.open("filename.txt", ios::in | ios::out);
			if (file.bad())
			{
				cout << "failed open\n";
				return;
			};
			int stunum = 0;
			while (!file.eof())
			{
				Student* b = new Student;
				//for (int i = 0;i < 8;i++)

				file >> b->name >> b->id >> b->schoolId >> b->sex
					>> b->address >> b->age >> b->birth >> b->phone;
				a.push_back(*b);


				stunum++;
			}


			/*stringstream ss(filename);
			while (ss >> x)
			{
				string substr;
				L.InsertL(x);
				L.length++;
			}*/
		}
	};
	void saveToFile(string fileName)
	{

		file.close();
	};

private:
	vector<Student> a;
	fstream file;


};