#include <iostream>
#include "Snake.h"
#include "Sound.h"
#include "Menu.h"
using namespace std;
#pragma comment(lib, "winmm.lib")


int main() {
    setlocale(0, "");
    srand(time(0));
    int width;
    int height;
    int length = 1;
    int max_length;
    int dx = 1;
    int dy = 0;
    int X[15] = { 0 };
    int Y[15] = { 0 };
    int aX = 0;
    int aY = 0;
    CreateThread(0, 0, MusicThread, 0, 0, 0);
    menu();
    int k = _getch();
     if(k==32){
           
         clear();
          


        }
     difficult();
     int a = _getch();
     if (a == 49) {
         clear();
         width = 28;
         height = 28;
         max_length = 15;
         HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
         COORD start = { 0,0 };
         SetConsoleCursorPosition(h, start);
         location(height, width);
    }
     else  if (a == 50) {
         clear();
         width = 20;
         height = 20;
         max_length = 15;
         HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
         COORD start = { 0,0 };
         SetConsoleCursorPosition(h, start);
         location(height, width);
     }
     else  if (a == 51) {
         clear();
         width = 15;
         height = 15;
         max_length = 15;
         HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
         COORD start = { 0,0 };
         SetConsoleCursorPosition(h, start);
         location(height, width);
     }
     snake_head(X, Y, height, width);
     apple(aX, aY, height, width, X, Y, length);
     bool win = game(dx, dy, X, Y, height, width, aX, aY, max_length, length);
     SetConsoleCursorPosition(h, { 0, (short)height });
     if (win) {
         cout << "Победа! Змейка достигла максимальной длины!" << endl;
     }
     else {
         cout << "Игра окончена! Вы проиграли." << endl;
     }
     return 0;



}





