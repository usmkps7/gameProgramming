#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define X_MAX 79 // 가로(열)방향의 최대값
#define Y_MAX 24 // 세로(행)방향의 최대값
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
int main(void)
{
    char key;
    int x = 10, y = 5;
    do
    {
        gotoxy(x, y);
        printf("A");
        key = getch();
        move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
    } while (key != 27);
    return 0;
}

void move_arrow_key(char key, int *x, int *y, int x_b, int y_b)
{
    switch (key)
    {
    case 72: // ↑
        (*y)--;
        if (*y < 1) *y = 1;
        break;
    case 75: // ←
        (*x)--;
        if (*x < 1) *x = 1;
        break;
    case 77: // →
        (*x)++;
        if (*x > x_b) *x = x_b;
        break;
    case 80: // ↓
        (*y)++;
        if (*y > y_b) *y = y_b;
        break;
    default:
        break;
    }
}

void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}