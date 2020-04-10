#pragma once
#include"vector.h"
#include"student.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class StudentInfoManagerBase
{
	using Container = fy::vector<Student>;
public:

private:
	Container data;
};