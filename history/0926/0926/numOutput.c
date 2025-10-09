#include <stdio.h>
#include <conio.h>
#include <math.h>

void serial_number(long number){
    int num;
    int i;
    int length = 0;
    
    length = (int)(log10(number)+1); //최대 자릿수
    
    for(i = length; i>=1; i--){
        num = number/(long) pow(10, i-1);
        printf("%d\n", num);
        number = number-num*(long) pow(10, i-1);
    }
    printf("\n");
}

void reverse_number(long number){
    while(number > 0){
        printf("%d\n", number % 10);
        number /= 10;
    }
}

int main(void){
    long number = 12345678;
    printf("입력 숫자: %ld\n\n", number);
    
    printf("높은 단위부터 출력\n");
    reverse_number(number);
    
    printf("낮은 단위부터 출력:\n");
    reverse_number(number);

    printf("press any key to continue");
    getch();
    return 0;
}