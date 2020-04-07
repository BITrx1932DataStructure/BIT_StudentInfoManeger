#pragma once
#include<string>
#include"managerBase.h"
#include"student.h"

using std::string;

class studenInfoManager :ManagerBase<Student>
{
public:
	Student queryByName(string name);
	Student queryById(string id);
	Student queryBySchoolIDd(string schoolId);
};