#pragma once
#include<Windows.h>

#define TEXT_LEFT 0 
#define TEXT_MID 1
#define TEXT_right 2

class Control
{
	using Pos = COORD;
	/*
	typedef struct _COORD
	{
		SHORT X;
		SHORT Y;
	} COORD��
	*/
public:
	Control() :consoleHandle(GetStdHandle(STD_OUTPUT_HANDLE))
	{
	}

	void clear();//��տ���̨����
	void setSize(const int x, const int y);
	void setPos(const Pos pos);
	void setPos(const int x, const int y);//���ù��λ��
	void print(const int x, const int y, const char* s, const int mode = TEXT_LEFT);//��ָ������λ���������
	Pos getPos();//��ȡ���λ��
private:
	HANDLE consoleHandle;
};