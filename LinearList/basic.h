//BASIC_H
//项目中需要使用的杂七杂八的类和功能
//创建者：冯易
//最后修改：20200407
#pragma once

#include<ctime>

//日期类，年月日
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
};