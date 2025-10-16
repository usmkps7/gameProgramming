#include <stdio.h>
#include <math.h>
#define PHI 3.141592
long total_days(int year, int month, int day);
void print_biorhythm(long total, int month);
char bio_status(int val, int mod);

int main(void)
{
  int byr, bmon, bday;
  int tyr, tmon, tday;
  long total=0;
  printf("Ư������ ���̿����� ���\n");
  printf("ù��° ��¥�� �ι�° ��¥�� �Է��ϰ� Enter �ϼ���.\n");
  printf("ù��° ��¥�� �ι�° ��¥���� �ռ��� �մϴ�. \n\n");
  printf("���� ������ �Է��ϼ��� (ex: 1983 5 21) \n");
  scanf("%d%d%d", &byr, &bmon, &bday);
  printf("���ð� ���� �⵵�� ���� �Է��ϼ���. (ex: 2004 11) \n");
  scanf("%d%d", &tyr, &tmon);
  tday=1;
  total=total_days(tyr, tmon, tday)-total_days(byr, bmon, bday);
  printf("�� ��¥ ������ ��¥���� %ld�� �Դϴ�. \n\n", total);
  printf("���̿����� ���:\n");
  printf("������(-), ������(+), �����(D)\n");
  print_biorhythm(total, tmon);
  return 0;
}
void print_biorhythm(long total, int month)
{
  //[�Լ� 11.2.2]�� ���Ǻκ� ����
  int dayindex;
  int physical, emotion, intellect;
  for(dayindex=1; dayindex<=30; dayindex++)
  {
     physical=total%23;
     emotion=total%28;
     intellect=total%33;
     printf("%d�� %2d��", month, dayindex);
     printf(" ��ü:%2d %c ", physical, bio_status(physical, 23));
     printf(" ����:%2d %c ", emotion, bio_status(emotion, 28));
     printf(" ����:%2d %c\n", intellect, bio_status(intellect, 33));
     total++;
  }
}
char bio_status(int v, int mod)
{
  //[�Լ� 11.2.1]�� ���Ǻκ� ����
   char result;
   double r;
   r=sin(v*3.141592/(mod/2.0));
   if (r < -0.2)
		  result='-';
   else if ((-0.2<=r) && (r<=0.2))
		  result='D';
   else
	 result='+';
   return result;
}
long total_days(int year, int month, int day)
{
  //[�Լ� 2.3.2]�� ���Ǻκ� ����
   int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   int i;
   long total=0L;
   total=(year-1)*365L+(year-1)/4-(year-1)/100+(year-1)/400;
   if(!(year%4) && year%100 || !(year%400))
  	  months[1]++;
   for(i=0; i<month-1; i++)
 	  total += months[i];
   total+=day;
   return total;
}
