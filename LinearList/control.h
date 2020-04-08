#pragma once
#include<Windows.h>
//#include"vector.h"
#include<vector>
#include<string>

#define TEXT_LEFT 0 
#define TEXT_MID 1
#define TEXT_RIGHT 2

using std::string;
using std::vector;

class Control
{
	using Pos = COORD;
	/*
	typedef struct _COORD
	{
		SHORT X;
		SHORT Y;
	} COORD；
	*/
public:
	Control();

	void hideCursor();
	void setColor(int color);
	void clear();//清空控制台内容
	void setSize(const int x, const int y);
	void setPos(const Pos pos);
	void setPos(const int x, const int y);//设置光标位置
	void print(const int x, const int y, const char* s, const int mode = TEXT_LEFT);//在指定坐标位置输出内容
	Pos getPos();//获取光标位置
private:
	HANDLE consoleHandle;

};

class Menu :Control
{
public:
	int getOpt();
	Menu();
	Menu(int x, int y);
	void show();
	void add(const char* s);
	//void setPos();

private:
	void printNormal(const int x, const int y, const char* s);
	void printOpt(const int x, const int y, const char* s);
	vector<string> data;
	int _opt;
	int _x, _y;

	int size();
};