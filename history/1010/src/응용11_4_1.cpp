#include <stdio.h>
char *ms_char[10]={"��Ƽ����", "����", "ų�ι���", "��ġ", "��Ʈ"
		 ,"�ߵ�", "����", "��(ô)", "��", "��"};
void print_distance_unit(void);
void measure_calculate(int basic, int transe, double measure);

int main(void)
{
  double measure;
  int basic, transe;

  printf("���̿� ���� ������ ȯ�� ���α׷�\n\n");
  print_distance_unit();
  printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
  scanf("%d %d",&basic,&transe);

  printf("���� �Է��ϰ� Enter>");
  scanf("%lf", &measure);
  printf("\n");
  measure_calculate(basic, transe, measure);
  return 0;
}

void print_distance_unit(void)
{
	int i;
	for(i=0;i<=9;i++)
	{
		printf("%d:%-8s  ", i, ms_char[i]);
		if (i%3==2)
			printf("\n");
	}
}

void measure_calculate(int basic, int transe, double measure)
{
  //[�Լ� 11.4.1]�� ���� �κ� ����
  double msre[10], unit, result;

  msre[0]=392772;		//centimeter
  msre[1]=msre[0]/100.;	//meter
  msre[2]=msre[1]/1000.;	//kilometer
  msre[3]=msre[0]/2.54;	//inch
  msre[4]=msre[3]/12.;	//feet
  msre[5]=msre[4]/3.;	//yard 
  msre[6]=msre[5]/1760.;	//mile
  msre[7]=12960.;      	//��
  msre[8]=msre[7]/6.;   	//��
  msre[9]=msre[8]/(6.*36); //��

  unit=msre[basic];
  result=measure*(msre[transe]/unit);
  printf("%.2f %8s�� ", measure, ms_char[basic]);
  printf("%15.5f %8s\n", result, ms_char[transe]);
}
