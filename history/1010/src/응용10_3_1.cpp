#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void moving_character_signboard(char file_name[], int line_length);
void gotoxy(int x, int y);
void draw_rectangle(int c, int r);

int main(void)
{
	char file_name[20];
	int line_length;
	printf("�����̴� ���� ������\n\n");
	printf("�������� ����ִ� ���� �̸���\n");
	printf("�Է��ϰ� Enter>");
	scanf("%s", file_name);
	printf("�����ǿ� ǥ���� ���ڼ��� \n");
	printf("�Է��ϰ� Enter>");
	scanf("%d", &line_length);
	moving_character_signboard(file_name, line_length);
	return 0;
}

void moving_character_signboard(char file_name[], int line_length)
{
              //[�Լ� 10.3.1]�� ���� �κ� ����
	char *ptr, chr[121];
	int i, j, length, count=0, countx;
	FILE *fp;
	ptr=(char *)malloc(line_length);
	gotoxy(1, 9);
	draw_rectangle(line_length/2, 1);
	fp=fopen(file_name, "r");
	if (fp==NULL)
	{
		printf("file open error!");
		exit(1);
	}
	while(!feof(fp))
	{
		//�κ� 1�� ó��
		fgets(chr, 120, fp);
		length=strlen(chr);
		ptr[line_length]='\0';
		for(j=0;j<line_length;j++)          
		{
			count=0;
			for(i=0;i<line_length-j-1;i++)
				ptr[i]=' ';
			for(i=line_length-j-1;i<line_length;i++)
			{
				ptr[i]=chr[count];
				count++;
			}
			gotoxy(3, 10);
			Sleep(200);
			printf("%s", ptr);
		}
		//�κ� 2�� ó�� 
		count=1;
		for(j=line_length-2;j<length;j++)  
		{
			countx=0;		
			for(i=count;i<count+line_length;i++)
			{
				ptr[countx]=chr[i];
				countx++;
			}
			count++;
			if ((length-line_length)<=count)
				break;
			gotoxy(3, 10);
			Sleep(200);
			printf("%s", ptr);
		}
		//�κ� 3�� ó��
		for(j=0;j<line_length;j++)		
		{
			for(i=0;i<line_length-j-1;i++)
				ptr[i]=ptr[i+1];
			for(i=line_length-j-1;i<line_length;i++)
				ptr[i]=' ';
			gotoxy(3, 10);
			Sleep(200);
			printf("%s", ptr);
		}
	}
	gotoxy(1, 12);
	fclose(fp);
}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void draw_rectangle(int c, int r)
{
    //[�Լ� 3.5.2]�� ���Ǻκ� ����
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
