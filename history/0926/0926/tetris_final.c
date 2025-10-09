#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define BOARD_W 12
#define BOARD_H 24

int x = 4, y = 0; // 현재 블록 위치
int inx = 0, iny = 1; // 이동 방향
int board[BOARD_H][BOARD_W] = {0}; // 게임판

// 전역 블록
int shape[3][3] = {
    {0,1,0},
    {0,1,0},
    {1,1,1}
};

// 콘솔 커서 이동
void gotoxy(int x, int y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 블록 회전
void rotation_right(int m[3][3]){
    int i, j;
    int temp[3][3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            temp[j][2-i] = m[i][j];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            m[i][j] = temp[i][j];
}

// 충돌 체크
int check_collision(int nx, int ny, int m[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(m[i][j]){
                int bx = nx + j;
                int by = ny + i;
                if(bx<0 || bx>=BOARD_W || by<0 || by>=BOARD_H) return 1;
                if(board[by][bx]) return 1;
            }
        }
    }
    return 0;
}

// 블록 고정
void merge_block(int nx, int ny, int m[3][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(m[i][j])
                board[ny+i][nx+j] = 1;
}

// 라인 제거
void remove_line(){
    for(int i=BOARD_H-1;i>=0;i--){
        int full = 1;
        for(int j=0;j<BOARD_W;j++)
            if(!board[i][j]) full = 0;
        if(full){
            for(int k=i;k>0;k--)
                for(int j=0;j<BOARD_W;j++)
                    board[k][j] = board[k-1][j];
            for(int j=0;j<BOARD_W;j++)
                board[0][j] = 0;
            i++; // 다시 체크
        }
    }
}

// 게임판 출력
void print_board(){
    system("cls");
    for(int i=0;i<BOARD_H;i++){
        for(int j=0;j<BOARD_W;j++){
            int is_block = board[i][j];
            // 현재 블록 표시
            int bx = j - x;
            int by = i - y;
            if(bx>=0 && bx<3 && by>=0 && by<3)
                if(shape[by][bx]) is_block = 1;
            printf(is_block?"■":"□");
        }
        printf("\n");
    }
    gotoxy(0,0);
    printf("화살표: 이동, 스페이스: 회전, ESC: 종료\n");
}

// 블록 이동
void move_block(){
    if(!check_collision(x+inx, y+iny, shape)){
        x += inx;
        y += iny;
    }else if(iny==1){ // 바닥이면 고정
        merge_block(x,y,shape);
        remove_line();
        // 새 블록 초기화
        x = 4; y = 0;
    }
}

// 키 입력 처리
void control(){
    if(kbhit()){
        char key = getch();
        switch(key){
            case 32: // 스페이스
                {
                    int temp[3][3];
                    for(int i=0;i<3;i++)
                        for(int j=0;j<3;j++)
                            temp[i][j] = shape[i][j];
                    rotation_right(temp);
                    if(!check_collision(x,y,temp))
                        rotation_right(shape);
                }
                break;
            case 72: // ↑(필요없음)
                break;
            case 75: // ←
                inx=-1; iny=0; move_block(); inx=0; iny=1;
                break;
            case 77: // →
                inx=1; iny=0; move_block(); inx=0; iny=1;
                break;
            case 80: // ↓
                inx=0; iny=1; move_block();
                break;
            case 27: // ESC
                exit(0);
        }
    }
}

int main(void){
    SetConsoleOutputCP(65001);

    while(1){
        control();
        move_block();
        print_board();
        Sleep(300);
    }

    return 0;
}
