#include "control.h"
#include<cstdlib>
#include<algorithm>
#include<conio.h>
#include<iostream>

using std::cout;
using std::endl;
using std::swap;

Control::Control() :consoleHandle(GetStdHandle(STD_OUTPUT_HANDLE))
{
}

void Control::hideCursor()
{
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(consoleHandle, &cursor);
	cursor.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &cursor);
}

void Control::setColor(int color)
{
	SetConsoleTextAttribute(consoleHandle, color);
}

void Control::clear()
{
	system("cls\n");
}

void Control::setSize(const int x, const int y)
{
	char s[100];
	sprintf_s(s, "mode con cols=%d lines=%d\n", y, x);
	system(s);
}

void Control::setPos(const Pos pos)
{
	setPos(pos.X, pos.Y);
}

void Control::setPos(const int x, const int y)
{
	COORD pos;
	pos.X = y;
	pos.Y = x;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void Control::print(const int x, const int y, const char* s, const int mode)
{
	Pos prePos = getPos();
	//TODO 输出按照指定对齐方式输出文本
	switch (mode)
	{
	case TEXT_LEFT:
		setPos(x, y);
		cout << s;
		//cout.flush();
		break;
	case TEXT_RIGHT:
		print(x, y - strlen(s), s);
	case TEXT_MID:
		print(x, y - strlen(s) / 2, s);
	}
	setPos(prePos);
}

Control::Pos Control::getPos()
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(consoleHandle, &bInfo);
	swap(bInfo.dwCursorPosition.X, bInfo.dwCursorPosition.Y);
	return bInfo.dwCursorPosition;
}

int Menu::getOpt()
{
	while (1)
	{
		show();
		int ch = _getch();
		if (ch == 13) return _opt;
		else if (ch == 224)
		{
			ch = _getch();
			if (ch == 72 && _opt >= 1)//UP
				_opt--;
			if (ch == 80 && _opt <= size() - 1 - 1)
				_opt++;
		}
	}
	return 0;
}

Menu::Menu() :_opt(0), _x(0), _y(0)
{
}

Menu::Menu(int x, int y) : _opt(0), _x(x), _y(y)
{
}

void Menu::show()
{
	int x(_x), y(_y);
	setColor(0xF0);
	clear();
	for (int i = 0; i < size(); i++)
	{
		if (i == _opt)
			printOpt(x + i, y, data[i].c_str());
		else printNormal(x + i, y, data[i].c_str());
	}

}

void Menu::add(const char* s)
{
	data.push_back(string(s));
}

void Menu::printNormal(const int x, const int y, const char* s)
{
	setColor(0xF0);
	print(x, y, s, TEXT_MID);
}

void Menu::printOpt(const int x, const int y, const char* s)
{
	setColor(0x70);
	print(x, y, s, TEXT_MID);
}

int Menu::size()
{
	return data.size();
}
