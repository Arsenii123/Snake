#include <iostream>
#include <windows.h>
using namespace std;
int X =55;
int Y=10;
int new_X=55;
int new_Y=10;
void menu() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 100; // 1-100
	SetConsoleCursorInfo(h, &cursor);
	COORD c;
	c.X = X;
	c.Y = Y;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 10); // зеленый цвет
	cout << "SNAKE";
	c.X = X-8;
	c.Y = Y+3;
	SetConsoleCursorPosition(h, c);
	cout << "(press enter to start)";
	new_Y = new_Y + 3;
	new_X = new_X - 8;
}
void difficult() {
	COORD c;
	c.X = X;
	c.Y = Y;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 10); // зеленый цвет
	cout << "EASY";
	c.X = X-2;
	c.Y = Y+2;
	SetConsoleCursorPosition(h, c);
	cout << "(press 1)";
	c.X = X-1;
	c.Y = Y+5;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 6); // зеленый цвет
	cout << "NORMAL";
	c.X = X - 2;
	c.Y = Y + 7;
	SetConsoleCursorPosition(h, c);
	cout << "(press 2)";
	c.X = X ;
	c.Y = Y + 10;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 12); // зеленый цвет
	cout << "HARD";
	c.X = X-2 ;
	c.Y = Y + 12;
	SetConsoleCursorPosition(h, c);
	cout << "(press 3)";
	new_X = new_X - 7;
	new_Y = new_Y+36;
}

void clear() {
	COORD oldpos;
	oldpos.X = X;
	oldpos.Y = Y;
	for (int y = 0; y < new_Y; y++) {
		for (int x = 0;  x < new_X; x++) {
			SetConsoleCursorPosition(h, oldpos);
			SetConsoleTextAttribute(h, 0); // зеленый цвет
			cout << " ";
			oldpos.X++;
		}
		oldpos.Y++;
	}
}



