#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

void survey_input(void);
int survey_question_read(char question[][100], char space[]);
void gotoxy(int x, int y);

int main(void)
{
	survey_input();
	return 0;
}

void survey_input(void)
{
  //[�Լ� 10.5.1]�� ���� �κ� ����
	int i, answer[20], count;
	char yn, question[10][100], space[10];
	FILE *fpw;
	count=survey_question_read(question, space);
	fpw=fopen("������.txt", "a");
	do
	{
		system("cls");
		printf("�� ������ ���� ������ ���� �Է��ϰ�Enter�Ͻÿ�.\n");
		printf("������ ���� ���ڸ� ����մϴ�.\n\n");
		for(i=0;i<count;i++)
			printf("%d) %s\n", i+1, question[i]);
		for(i=0;i<count;i++)
		{
			fflush(stdin);
			gotoxy(space[i]+4, i*2+4);
			scanf("%d", &answer[i]);
			fprintf(fpw, "%d ", answer[i]);
		}
		fprintf(fpw, "\n");
		printf("\n");
		printf("�������簡 �������ϴ�. ����� 1, ����� 0�� �Է� ");
		yn=getch();
	}while(yn!='0');
	fclose(fpw);

}
int survey_question_read(char question[][100], char space[])
{
  //[�Լ� 10.5.2]�� ���� �κ� ����
	char chr[100];
	FILE *fpr;
	int count=0;
	fpr=fopen("��������.txt", "r");
	while(!feof(fpr))
	{
		fgets(chr, 90, fpr);
		space[count]=strlen(chr);
		strcpy(question[count], chr);
		count++;
	}
	fclose(fpr);
	return count;  //������ ������ ��ȯ
}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
