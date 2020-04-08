#include "control.h"
#include<cstdlib>
#include<algorithm>
#include<conio.h>
#include<iostream>

using std::cout;
using std::endl;
using std::swap;

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
	setPos(x, y);
	cout << s;
	cout.flush();

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
		show(0, 0);
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

Menu::Menu() :_opt(0)
{
}

void Menu::show(int x, int y)
{
	setColor(0xF0);
	clear();
	for (int i = 0; i < size(); i++)
	{
		setPos(x + i, y);
		if (i == _opt)
			printOpt(data[i].c_str());
		else printNormal(data[i].c_str());
	}

}

void Menu::add(const char* s)
{
	data.push_back(string(s));
}

void Menu::printNormal(const char* s)
{
	setColor(0xF0);
	cout << s;
}

void Menu::printOpt(const char* s)
{
	setColor(0x70);
	cout << s;
}

int Menu::size()
{
	return data.size();
}
