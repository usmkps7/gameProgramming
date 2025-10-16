#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void draw_rectangle(int c, int r);
void display_abacus(int m[]);
void div_number(int mc[], long number);
void gotoxy(int x, int y);

int main(void)
{
  long number=0;
  int mc[9];
  printf("�Էµ� ���ڸ� ���Ǹ������ ���\n");
  printf("0�� �Է��ϸ� ����\n");
  div_number(mc, number);
  gotoxy(1, 5);
  draw_rectangle(14, 8);
  display_abacus(mc);
  do
  {
	gotoxy(1, 16);
	printf("���� ��:%ld\n", number);
	gotoxy(1, 17);
	printf("�ִ� 9�ڸ� ������ �Է��ϰ� Enter>         ");
	gotoxy(34, 17);
	scanf("%ld", &number);
	if (number==0)
		break;
	div_number(mc, number);
	display_abacus(mc);
  }while(1<=number);
	gotoxy(1,17);
  return 0;
}

void div_number(int mc[], long number)
{
  //[�Լ� 11.1.1]�� ���� �κ� ����
  int i;
  for(i=0;i<=8;i++)
  {
      mc[i]= (int) (number/pow(10, 8-i));
      number= number-(long) pow(10, 8-i)*mc[i];
  }
}
void display_abacus(int m[])
{
  //[�Լ� 11.1.2]�� ���� �κ� ����
	int i, j;
	unsigned char a1=0xa6, a2=0xa1;
	gotoxy(3, 4);
	for(i=0;i<=8;i++)
		printf("%2d ", m[i]);
	gotoxy(3, 6);
	for(i=0;i<=8;i++)
		if (m[i]/5)
			printf("%c%c ",a1, 0xa2);
		else
			printf("%c%c ", a2, 0xdf);
	gotoxy(3, 7);
	for(i=0;i<=8;i++)
		if (m[i]<5)
			printf("%c%c ",a1, 0xa2);
		else
			printf("%c%c ", a2, 0xdf);
	for(i=0;i<=8;i++) 
		m[i]%=5;
	gotoxy(3, 8);
	for(i=1;i<=13;i++) 
		printf("%c%c",a1, a2);
	for(i=1;i<=5;i++) 
	{
		gotoxy(3, 8+i);
		for(j=0;j<=8;j++)
		if (m[j]>=i)
			printf("%c%c ", a2, 0xdf);
		else if (m[j]==0) {
			printf("%c%c ", a1, 0xa2);
			m[j]=5;
		}
		else {
			printf("%c%c ", a1, 0xa2);
			m[j]=5;
		}
	}
}
void draw_rectangle(int c, int r)
{
  //[�Լ� 3.5.2]�� ���� �κ� ����
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[7]; 
    for(i=1;i<7;i++)
   	b[i]=0xa0+i;

    printf("%c%c",a, b[3]);
    for(i=0;i<c;i++)
  	printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r;i++)
    {
	printf("%c%c", a, b[2]);
	for(j=0;j<c;j++)
		printf("  ");
	printf("%c%c",a, b[2]);
	printf("\n");
    }
    printf("%c%c", a, b[6]);
    for(i=0;i<c;i++)
	printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
