#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_check01(int c, int r);
void game_control(void);
//추가
void draw_target(int tx, int ty);
void play_hit_sound(void);
void play_miss_sound(void);
int check_hit(int x, int y, int tx, int ty);


int main(void)
{
	game_control();
	return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check01(int c, int r)
{
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[12]; 
    for(i=1;i<12;i++)
	b[i]=0xa0+i;
    printf("%c%c",a, b[3]);
    for(i=0;i<c-1;i++)
	 printf("%c%c", a, b[8]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r-1;i++)
    {
	printf("%c%c", a, b[7]);
	for(j=0;j<c-1;j++)
	    printf("%c%c", a, b[11]);
	printf("%c%c",a, b[9]);
	printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c-1;i++)
	printf("%c%c", a, b[10]);
    printf("%c%c", a, b[5]);
    printf("\n");
}

void game_control(void)
{
    int x=1, y=1;
    char key;
    do
    {
	gotoxy(1,1);
	draw_check01(18, 18);
	gotoxy(x, y);
	printf("○");
	gotoxy(1, 21);
	printf("방향키를 누르시오.");
	key=getch();
	if (key==27)
		exit(0);
	else if (key>=72)
		move_arrow_key(key, &x, &y, 37, 19); //수정부분
   }while(1);
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //위쪽(상) 방향의 화살표 키 입력
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y좌표의 최소값
		break;
	case 75:  //왼쪽(좌) 방향의 화살표 키 입력
		*x1=*x1-2;             //좌측방향으로 2씩 감소
		if (*x1<1)	*x1=1; //x좌표의 최소값
		break;
	case 77:  //오른쪽(우) 방향의 화살표 키 입력
		*x1=*x1+2;               //우측방향으로 2씩 증가
		if (*x1>x_b)  *x1=x_b; //x좌표의 최대값(경계)
		break;
	case 80:  //아래쪽(하) 방향의 화살표 키 입력
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y좌표의 최대값(경계)
		break;
	default:
		return;
	}
}

//추가

void draw_target(int tx, int ty)
{
    gotoxy(tx, ty);
    printf("◎");
}

void play_hit_sound(void)
{
    // 맞았을 때: 높은 음의 성공 사운드
    Beep(1000, 100);  // 1000Hz, 100ms
    Beep(1500, 100);  // 1500Hz, 100ms
    Beep(2000, 200);  // 2000Hz, 200ms
}

void play_miss_sound(void)
{
    // 못 맞췄을 때: 낮은 음의 실패 사운드
    Beep(300, 200);   // 300Hz, 200ms
    Beep(200, 300);   // 200Hz, 300ms
}

int check_hit(int x, int y, int tx, int ty)
{
    // 화살표가 과녁에 맞았는지 확인 (정확히 같은 위치)
    return (x == tx && y == ty);
}
