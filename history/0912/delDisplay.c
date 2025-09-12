#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void) {
    int i, j;
    system("cls");
    i = 1;
    for(j = 1; j <= 9; j++){
        printf("%d*%d=%d\n", j, i, j*i);
        printf("아무 키나 누르세요");
        getch();
    }
    return 0;

}