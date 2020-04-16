#pragma once

#include<string>
#include<iostream>

using std::ostream;
using std::istream;
using std::string;

class Date
{
public:
	int year;
	int month;
	int day;

	Date() = default;

	Date(int _year, int _month, int _day);

	~Date() = default;
	friend ostream& operator<<(ostream& out, const Date& date);
	friend istream& operator>>(istream& in, Date& date);
};

class Student
{
	using type_name = string;
	using type_id = string;
	using type_sex = string;
	using type_address = string;
	using type_age = unsigned int;
	using type_birth = Date;
	using type_phone = string;
	using type_schoolId = string;

public:
	const static Student emptyStudent;
	type_name name;
	type_id id;
	type_id schoolId;
	type_sex sex;
	type_address address;
	type_age age;
	type_birth birth;
	type_phone phone;

	Student();
	~Student();

	operator bool();
	bool operator==(const Student& stu);
};
