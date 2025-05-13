#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime> // для srand и rand
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // создание хендла потока вывода
COORD c; // объект для хранения координат
CONSOLE_CURSOR_INFO cci = { sizeof(cci), false }; // параметры курсора




 void location(int height, int width) {
        SetConsoleCursorInfo(h, &cci);
        SetConsoleTextAttribute(h, 4); // цвет рамки

        char** ptr = new char* [height];
        for (int y = 0; y < height; y++) {
            ptr[y] = new char[width];
        }
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                char s;
                if (x == 0 && y == 0) ptr[y][x] = '#'; // верхний левый угол
                else if (x == 0 && y == height - 1) ptr[y][x] = '#'; // нижний левый угол
                else if (y == 0 && x == width - 1) ptr[y][x] = '#'; // верхний правый угол
                else if (y == height - 1 && x == width - 1)ptr[y][x] = '#'; // нижний правый угол
                else if (y == 0 || y == height - 1) ptr[y][x] = '#'; // верхняя/нижняя граница
                else if (x == 0 || x == width - 1) ptr[y][x] = '#'; // левая/правая граница
                else ptr[y][x] = ' '; // пустое поле
                cout << ptr[y][x];
            }
            cout << "\n";
        }
        for (int i = 0; i < height; ++i) {
            delete[] ptr[i]; // видаляємо кожен рядок
        }
        delete[] ptr; // видаляємо масив з вказівниками

    }


void snake_head(int array_X[], int array_Y[], int width, int height) {
    SetConsoleCursorInfo(h, &cci);
    array_X[0] = width / 2; // стартовая позиция змейки
    array_Y[0] = height / 2;
    c.X = array_X[0];
    c.Y = array_Y[0];
    SetConsoleCursorPosition(h, c);
    SetConsoleTextAttribute(h, 10); // зеленый цвет
    cout << "O";
}

void apple(int& X_apple, int& Y_apple, int width, int height, int array_X[], int array_Y[], int length) {
    SetConsoleCursorInfo(h, &cci);
    bool valid;
    do {
        valid = true;
        X_apple = rand() % (width - 2) + 1;
        Y_apple = rand() % (height - 2) + 1;
        for (int i = 0; i < length; i++) {
            if (X_apple == array_X[i] && Y_apple == array_Y[i]) {
                valid = false;
                break;
            }
        }
    } while (!valid);
    c.X = X_apple;
    c.Y = Y_apple;
    SetConsoleCursorPosition(h, c);
    SetConsoleTextAttribute(h, 12); // красный цвет
    cout << "O";
}

bool game(int& dx, int& dy, int array_X[], int array_Y[], int width, int height, int& X_apple, int& Y_apple, int max_length, int& length) {
    SetConsoleCursorInfo(h, &cci);
    bool flag = true;
    do {
        Sleep(100);
        if (_kbhit()) {
            int k = _getch();
            if (k == 0 || k == 224) k = _getch();
            switch (k) {
            case 80: // вниз
                if (dy != -1) { // предотвратить движение назад
                    dy = 1;
                    dx = 0;
                }
                break;
            case 72: // вверх
                if (dy != 1) {
                    dy = -1;
                    dx = 0;
                }
                break;
            case 75: // влево
                if (dx != 1) {
                    dy = 0;
                    dx = -1;
                }
                break;
            case 77: // вправо
                if (dx != -1) {
                    dy = 0;
                    dx = 1;
                }
                break;
            case 27: // ESC
                flag = false;
                break;
            }
        }

        int X = array_X[length - 1] + dx;
        int Y = array_Y[length - 1] + dy;
       

        // Проверка столкновения с границами
        if (X == 0 || X == width - 1 || Y == 0 || Y == height-1 ) {
            flag = false;
        }
        // Проверка столкновения с собой
        for (int i = 0; i < length - 1; i++) {
            if (X == array_X[i] && Y == array_Y[i]) {
                flag = false;
                break;
            }
        }

        if (!flag) break;

        if (X == X_apple && Y == Y_apple) {
            c.X = array_X[length - 1];
            c.Y = array_Y[length - 1];
            SetConsoleCursorPosition(h, c);
            SetConsoleTextAttribute(h, 10); // зеленый цвет
            cout << "*";

            length++;
            array_X[length - 1] = X;
            array_Y[length - 1] = Y;
            c.X = X;
            c.Y = Y;
            SetConsoleCursorPosition(h, c);
            SetConsoleTextAttribute(h, 10); // зеленый цвет
            cout << char(248);

            if (length >= max_length) {
                return true;
            }

            apple(X_apple, Y_apple, width, height, array_X, array_Y, length);
        }
        else {
            c.X = array_X[0];
            c.Y = array_Y[0];
            SetConsoleCursorPosition(h, c);
            cout << ' ';

            if (length > 1) {
                c.X = array_X[length - 1];
                c.Y = array_Y[length - 1];
                SetConsoleCursorPosition(h, c);
                SetConsoleTextAttribute(h, 10); // зеленый цвет
                cout << "*";
            }

            for (int i = 0; i < length - 1; i++) {
                array_X[i] = array_X[i + 1];
                array_Y[i] = array_Y[i + 1];
            }

            array_X[length - 1] = X;
            array_Y[length - 1] = Y;
            c.X = X;
            c.Y = Y;
            SetConsoleCursorPosition(h, c);
            SetConsoleTextAttribute(h, 10); // зеленый цвет
            cout << char(248);
        }
    } while (flag);
    return false;
}


