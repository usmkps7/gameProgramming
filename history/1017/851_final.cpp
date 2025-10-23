#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// 함수 선언
void intro_game(void);
const char* choose_horse(void);
void horizontal_slide(int x, int y, const char *c2);
void draw_rectangle(int r, int c);
void display_text(int count, int r_count);
void game_control(int* r_c, int rnd, const char* horse);
void gotoxy(int x, int y);
void play_hit_sound(void);
void play_miss_sound(void);

int main(void)
{
    int count=0, rnd;
    int r_count=0;
    const char* target="□";
    const char* horse;  // 사용자 선택 아바타
    srand(time(NULL));

    intro_game();    
    horse = choose_horse();   // 아바타 선택

    do
    {
        system("cls");
        draw_rectangle(20, 20);
        rnd=rand()%35+4;
        gotoxy(rnd, 2);
        printf("%s", target);
        count++;
        display_text(count, r_count);
        game_control(&r_count, rnd, horse);  // 선택한 아바타 전달
    } while(count<5);

    // 게임 종료 화면
    system("cls");
    printf("\n\n\n");
    printf("     ???????????????????????????????????????\n");
    printf("     ?                                     ?\n");
    printf("     ?          게임 종료!                 ?\n");
    printf("     ?                                     ?\n");
    printf("     ?       최종 점수: %d / 5              ?\n", r_count);
    printf("     ?                                     ?\n");
    if(r_count == 5)
    {
        printf("     ?         ★ 퍼펙트! ★              ?\n");
        printf("     ?                                     ?\n");
        // 퍼펙트 효과음
        Beep(800, 150);
        Beep(1000, 150);
        Beep(1200, 150);
        Beep(1500, 300);
    }
    else
    {
        printf("     ?        수고하셨습니다!              ?\n");
        printf("     ?                                     ?\n");
    }
    printf("     ???????????????????????????????????????\n\n");
    getch();
    return 0;
}

// 게임 인트로 화면
void intro_game(void)
{
    int i;
    system("cls");
    printf("\n\n\n");
    printf("     ???????????????????????????????????????\n");
    printf("     ?                                     ?\n");
    printf("     ?              기마 궁수              ?\n");
    printf("     ?                                     ?\n");
    printf("     ?              ▲  →  □                ?\n");
    printf("     ?                                     ?\n");
    printf("     ?      Horse Archery Shooting         ?\n");
    printf("     ?                                     ?\n");
    printf("     ???????????????????????????????????????\n\n");
    printf("              게임을 시작합니다...\n\n");
    
    // 카운트다운
    for(i=5; i>0; i--)
    {
        printf("                     %d", i);
        Beep(500, 200);
        Sleep(800);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                     ");
    }
}

// 사용자 아바타 선택
const char* choose_horse(void)
{
    int choice = 0;
    const char* shapes[] = {"A", "^", "!", "▲"};
    int num_shapes = sizeof(shapes) / sizeof(shapes[0]);

    system("cls");
    printf("\n\n     Choose your arrow avatar!\n\n");
    for(int i=0; i<num_shapes; i++)
        printf("     %d. %s\n", i+1, shapes[i]);
    printf("\n     Enter number (1-%d): ", num_shapes);

    while(1)
    {
        choice = getch() - '0';  // 숫자 입력
        if(choice >=1 && choice <= num_shapes)
            break;
    }

    system("cls");
    printf("     You chose: %s\n", shapes[choice-1]);
    Sleep(1000);
    return shapes[choice-1];
}

// 아바타 수평 이동
void horizontal_slide(int x, int y, const char *c2)
{
    gotoxy(x, y);
    printf("%s", c2);
    Sleep(50);
    printf("\b ");
}

// 직사각형 그리기
void draw_rectangle(int r, int c)
{
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

// 게임 정보 표시
void display_text(int count, int r_count)
{
    gotoxy(46, 2);
    printf("스페이스키를 누르면\n");
    gotoxy(46, 3);
    printf("화살이 발사됩니다.\n");
    gotoxy(46, 5);
    printf("횟수 : %d", count);
    gotoxy(46, 6);
    printf("성공 : %d", r_count);
}

// 명중 효과음
void play_hit_sound(void)
{
    Beep(800, 100);
    Beep(1000, 100);
    Beep(1200, 150);
}

// 빗나감 효과음
void play_miss_sound(void)
{
    Beep(600, 100);
    Beep(400, 150);
}

// 게임 진행
void game_control(int* r_c, int rnd, const char* horse)
{
    int i=1, k=1, y;
    char chr;

    do
    {
        i+=k;
        if (i>39)
            k=-1;
        else if (i<3)
            k=+1;
        horizontal_slide(i+1, 21, horse);
    } while(!kbhit());

    chr = getch();
    y = 21;
    if(chr == 32)
    {
        while(y>2)
        {
            y-=1;
            gotoxy(i+1, y);
            printf("↑");
            Sleep(50);
            printf("\b  ");
        }
        if((rnd<=i) && (i<=(rnd+1)))
        {
            gotoxy(rnd, 2);
            printf("☆");
            gotoxy(46, 8);
            printf("맞았습니다. ");
            play_hit_sound();
            *r_c = *r_c + 1;
        }
        else
        {
            play_miss_sound();
        }
        gotoxy(1, 24);
        printf("아무키나 누르면 다음 진행...");
        getch();
    }
}

// 콘솔 커서 이동
void gotoxy(int x, int y)
{
    COORD Pos;
    Pos.X = x - 1;
    Pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
