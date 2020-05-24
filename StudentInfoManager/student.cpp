#include "student.h"

Date::Date() :year(1234), month(56), day(78)
{
}

Date::Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day)
{
}

Student::Student()
{
}

Student::~Student()
{

}

string Student::to_string() const
{
	return name + "\n" + id + "\n" + schoolId + "\n" + sex + "\n" + address + "\n" + age + "\n" + birth + "\n" + phone + '\n';
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
	in.get();
	return in;
}

ostream& operator<<(ostream& out, const Student& stu)
{
	using std::endl;
	out << stu.to_string();

	return out;
}

istream& operator>>(istream& in, Student& stu)
{

	getline(in, stu.name);
	getline(in, stu.id);
	getline(in, stu.schoolId);
	getline(in, stu.sex);
	getline(in, stu.address);
	getline(in, stu.age);
	getline(in, stu.birth);
	getline(in, stu.phone);

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