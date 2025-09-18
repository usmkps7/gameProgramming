#include <stdio.h>

void draw_rectangle(int width, int height);

int main(void)
{
    int w, h;
    printf("직사각형 그리기\n\n");
    printf("가로(폭) 입력> ");
    scanf("%d", &w);
    printf("세로(높이) 입력> ");
    scanf("%d", &h);

    draw_rectangle(w, h);

    return 0;
}

void draw_rectangle(int width, int height)
{
    int i, j;

    // 위쪽
    for (i = 0; i < width; i++)
        printf("*");
    printf("\n");

    // 중간 (빈 공간)
    for (i = 0; i < height - 2; i++)
    {
        printf("*"); // 왼쪽
        for (j = 0; j < width - 2; j++)
            printf(" ");
        if (width > 1)
            printf("*"); // 오른쪽
        printf("\n");
    }

    // 아래쪽
    if (height > 1)
    {
        for (i = 0; i < width; i++)
            printf("*");
        printf("\n");
    }
}
