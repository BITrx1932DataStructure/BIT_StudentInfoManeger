//BASIC_H
//��Ŀ����Ҫʹ�õ������Ӱ˵���͹���
//�����ߣ�����
//����޸ģ�20200407
#pragma once

#include<ctime>

//�����࣬������
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