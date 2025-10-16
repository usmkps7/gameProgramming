#include <stdio.h>
#include <conio.h>
#include <windows.h>

int menu_display(void);		  //�ָ޴� ǥ��;
int sub_menu_display01(void); //����޴�1 ǥ��
int sub_menu_display02(void); //����޴�2 ǥ��
void sub_main01(void);        //����޴� 1 ����
void sub_main02(void);        //����޴� 2 ����
void press_any_key(void);     //�ƹ�Ű�� ������ ���� �޴��� 

void display_recipe(void);    //������ ���
void volume_calculation(void);//����ȯ��
void weight_calculation(void);//����ȯ��
void print_unit(char *ms_char[], int n);
void volume_calculate(int basic, int transe, double measure, char *ms_char[]);
void weight_calculate(int basic, int transe, double measure, char *ms_char[]);

int main(void)
{
	int c;
	while((c=menu_display())!=3)
	{
		switch(c)
		{
			case 1 : sub_main01();
				break;
			case 2 : sub_main02();
				break;
			default : break;
		}
	}
	printf("\n");
	return 0;
}
int menu_display(void)
{
    int select;
    system("cls");
    printf("������ ������\n\n");
    printf("1. ������ \n");
    printf("2. ����ȯ�� \n");
    printf("3. ���α׷� ����\n\n");
    printf("�޴���ȣ �Է�>");
    select=getch()-48;
    return select;
}

void sub_main01(void)
{
    int c;
    while((c=sub_menu_display01())!=2)
    {
      switch(c)
      {
           case 1 : display_recipe();
  	 	     break;
           default : break;
     }
   }
}

int sub_menu_display01(void)
{
    int select;
    system("cls");
    printf("������\n\n");
    printf("1. ī����������\n");
    printf("2. ���� �޴��� �̵�\n\n");
    printf("�޴���ȣ �Է�>");
    select=getch()-48;
    return select;
}
void sub_main02(void)
{
    int c;
    while((c=sub_menu_display02())!= 3)
    {
      switch(c)
      {
           case 1 : volume_calculation();
  	 	     break;
           case 2 : weight_calculation();
  		     break;
           default : break;
     }
   }
}

int sub_menu_display02(void)
{
        int select;
        system("cls");
        printf("����ȯ��\n\n");
        printf("1. ����(volume) ȯ�� \n");
        printf("2. ����(weight) ȯ�� \n");
        printf("3. ���� �޴��� �̵�\n\n");
        printf("�޴���ȣ �Է�>");
        select=getch()-48;
        return select;
}

void press_any_key(void)
{
       printf("\n\n");
       printf("�ƹ�Ű�� ������ ���� �޴���...");
       getch();
}
void display_recipe(void)
{
  //[�Լ� 9.2.6]�� ���� �κ� ����
	FILE *fp1;
	char chr1[82];
	char *file1="carbonara.txt";
	fp1=fopen(file1, "r");
	system("cls");
	while(!feof(fp1))
	{
		fgets(chr1, 80, fp1);
		if (chr1[0]==10)
		{
			printf("\n�����ܰ�� �̵��Ϸ��� �ƹ�Ű�� �����ÿ�.");
			getch();
			system("cls");
		}
		else
			printf("%s", chr1);
	}
	printf("\n������ ��.\n");
	press_any_key();
	fclose(fp1);
}

void volume_calculation(void)
{
  //[�Լ� 9.2.1]�� ���� �κ� ����
  char *ms_char[6]={"�и�����", "teaspoon", "tablespoon", 
                     "cup", "����", "����"};
  double measure;
  int basic, transe;
  system("cls");	
  printf("���ǿ� ���� ������ ȯ�� ���α׷�\n\n");
  print_unit(ms_char, 6);
  printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
  scanf("%d %d",&basic,&transe);
  printf("���� �Է��ϰ� Enter>");
  scanf("%lf", &measure);
  printf("\n");
  volume_calculate(basic, transe, measure, ms_char);
  press_any_key();
}

void weight_calculation(void)
{
  //[�Լ� 9.2.2]�� ���� �κ� ����
  char *ms_char[4]={"�׷�", "����", "�Ŀ��", "ų�α׷�"};
  double measure;
  int basic, transe;
  system("cls");	
  printf("���Կ� ���� ������ ȯ�� ���α׷�\n\n");
  print_unit(ms_char, 4);
  printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
  scanf("%d %d",&basic,&transe);

  printf("���� �Է��ϰ� Enter>");
  scanf("%lf", &measure);
  printf("\n");
  weight_calculate(basic, transe, measure, ms_char);
  press_any_key();

}

void print_unit(char *ms_char[], int n)
{
 	 //[�Լ� 9.2.5]�� ���� �κ� ����
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d:%-9s  ", i, ms_char[i]);
		if (i%3==2)
			printf("\n");
	}
}

void volume_calculate(int basic, int transe, double measure, char *ms_char[])
{
  //[�Լ� 9.2.3]�� ���� �κ� ����
  double msre[10], unit, result;
  msre[0]=3758.279;
  msre[1]=msre[0]/5.;
  msre[2]=msre[1]/3.;
  msre[3]=msre[2]/16.667;
  msre[4]=msre[3]/4.;
  msre[5]=msre[4]/3.758;
  unit=msre[basic];
  result=measure*(msre[transe]/unit);
  printf("%.3f %-10s : ", measure, ms_char[basic]);
  printf("%.3f %-10s", result, ms_char[transe]);
}
void weight_calculate(int basic, int transe, double measure, char *ms_char[])
{
  //[�Լ� 9.2.4]�� ���� �κ� ����
  double msre[4], unit, result;
  msre[0]=1000;
  msre[1]=msre[0]/28.3459;
  msre[2]=msre[1]/16.;
  msre[3]=msre[2]/2.205;
  unit=msre[basic];
  result=measure*(msre[transe]/unit);
  printf("%.2f %-8s:", measure, ms_char[basic]);
  printf("%.5f %-8s", result, ms_char[transe]);
}
