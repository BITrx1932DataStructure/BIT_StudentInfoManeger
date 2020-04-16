#include "student.h"

Date::Date():year(1234),month(56),day(78)
{
}

Date::Date(int _year, int _month, int _day) :year(_year), month(_month), day(_day)
{
}

Student::Student() :
	name("NONE"),
	id("NONE"),
	schoolId("NONE"),
	sex("NONE"),
	address("NONE"),
	age(0),
	birth(),
	phone("NONE")
{
}

Student::~Student()
{

}

const Student Student::emptyStudent = Student();

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.year << " ";
	out << date.month << " ";
	out << date.day;
	return out;
}

istream& operator>>(istream& in, Date& date)
{
	in >> date.year;
	in >> date.month;
	in >> date.day;
	return in;
}

ostream& operator<<(ostream& out, const Student& stu)
{
	out << stu.name << " ";
	out << stu.id << " ";
	out << stu.schoolId << " ";
	out << stu.sex << " ";
	out << stu.age << " ";
	out << stu.address << " ";
	out << stu.birth << " ";
	out << stu.phone;

	return out;
}

istream& operator>>(istream& in, Student& stu)
{
	in >> stu.name;
	in >> stu.id;
	in >> stu.schoolId;
	in >> stu.sex;
	in >> stu.age;
	in >> stu.address;
	in >> stu.birth;
	in >> stu.phone;

	return in;
}

Student::operator bool()
{
	return !(*this == emptyStudent);
}

bool Student::operator==(const Student& stu)
{
	return name == stu.name
		&& id == stu.id
		&& schoolId == stu.schoolId;
}