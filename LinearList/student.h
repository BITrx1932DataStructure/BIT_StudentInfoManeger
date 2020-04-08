#pragma once

#include<string>
#include"basic.h"

using std::string;

class Student
{
	using type_name = string;
	using type_id = string;
	using type_sex = bool;
	using type_address = string;
	using type_age = unsigned int;
	using type_birth = Date;
	using type_phone = string;
	using type_schoolId = string;

public:
	type_name name;
	type_id id;
	type_id schoolID;
	type_sex sex;
	type_address address;
	type_age age;
	type_birth birth;
	type_phone phone;

	Student() = default;
	~Student() = default;

};