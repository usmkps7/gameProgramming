#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void selection_sort(int r[], int n);

int main(void)
{
    int i, j, lotto[6];
    srand(time(NULL));
    for (i = 0; i <= 5; i++)
    {
        lotto[i] = rand() % 45 + 1;
        for (j = 0; j < i; j++)
        {
            if (lotto[i] == lotto[j])
            {
                i--; 
                break;
            }
        }
    }
    selection_sort(lotto, 6);
    printf("\n계속하려면 아무 키나 누르세요...");
    getch();

    return 0;
}

void selection_sort(int r[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (r[j] < r[min])
                min = j;
        // swap
        temp = r[min];
        r[min] = r[i];
        r[i] = temp;
    }

    // 결과 출력
    printf("이번 주 로또 번호:\n");
    for (i = 0; i < n; i++)
        printf("%2d ", r[i]);
    printf("\n");
}