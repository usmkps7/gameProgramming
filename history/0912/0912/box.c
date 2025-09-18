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
    unsigned char a = 0xA6;
    unsigned char b[7];

    for (i = 1; i < 7; i++)
        b[i] = 0xA0 + i;

    // 위쪽
    printf("%c%c", a, b[3]);
    for (i = 0; i < width; i++)
        printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");

    // 중간 부분
    for (i = 0; i < height - 2; i++)
    {
        printf("%c%c", a, b[2]);
        for (j = 0; j < width; j++)
            printf("  "); // 내부 공간
        printf("%c%c", a, b[2]);
        printf("\n");
    }

    // 아래쪽
    printf("%c%c", a, b[6]);
    for (i = 0; i < width; i++)
        printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}