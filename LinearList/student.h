#pragma once

#include<string>

using std::string;

class Date
{
public:
	int year;
	int month;
	int day;

	Date() = default;

	Date(int _year, int _month, int _day) :year(_year), month(_month), day(_day)
	{
	}

	~Date() = default;
	friend ostream& operator<<(ostream& out, const Date& date);
	friend istream& operator>>(istream& in, Date& date);
};

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.year << "-" << date.month << "-" << date.day;
}

istream& operator>>(istream& in, Date& date)
{
	in >> date.year >> date.month >> date.day;
}

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
	type_name name;
	type_id id;
	type_id schoolId;
	type_sex sex;
	type_address address;
	type_age age;
	type_birth birth;
	type_phone phone;

	Student() = default;
	~Student() = default;

};