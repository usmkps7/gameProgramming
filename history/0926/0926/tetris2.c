#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int x = 1, y = 1;        // 좌표 초기화
int inx = 0, iny = 0;    // 이동 방향

void gotoxy(int x, int y){
    COORD pos = {x - 1, y - 1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print_shape(int m[][3]){
    int i, j;
    for(i=0; i<3; i++){
        gotoxy(x, y+i);
        for(j=0; j<3; j++)
            if(m[i][j] == 1)
                printf("■");
            else
                printf("□");
    }
}

void print_direction(void){
    gotoxy(25, 1);
    printf("화살표: 이동, 스페이스: 회전");
}

void rotation_right(int m[][3]){
    int i, j;
    int temp[3][3];
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            temp[j][2-i] = m[i][j];
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            m[i][j] = temp[i][j];
}

void move_shape(int m[][3]){
    x += inx;
    y += iny;
    if (y > 23) y = 23;
    if (y < 2)  y = 2;
    if (x > 75) x = 75;
    if (x < 1)  x = 1;

    system("cls");
    print_shape(m);
    print_direction();
    Sleep(100);
}

void move_control(int m[][3]){
    char key;
    do{
        if(kbhit()){
            key = getch();
            switch(key){
                case 32:  // 스페이스
                    rotation_right(m);
                    break;
                case 72:  // 위
                    inx = 0; iny = -1;
                    break;
                case 75:  // 왼쪽
                    inx = -1; iny = 0;
                    break;
                case 77:  // 오른쪽
                    inx = 1; iny = 0;
                    break;
                case 80:  // 아래
                    inx = 0; iny = 1;
                    break;
            }
        }
        move_shape(m);
    }while (key != 27); // ESC 누르면 종료
}

int main(void){
    SetConsoleOutputCP(65001); // UTF-8 설정

    int shape1[3][3] = {
        {0, 1, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    move_control(shape1);
    return 0;
}
