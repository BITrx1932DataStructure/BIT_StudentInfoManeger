#include "control.h"
#include<cstdlib>
#include<algorithm>

using std::swap;

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
	setPos(prePos);
}

Control::Pos Control::getPos()
{
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(consoleHandle, &bInfo);
	swap(bInfo.dwCursorPosition.X, bInfo.dwCursorPosition.Y);
	return bInfo.dwCursorPosition;
}

