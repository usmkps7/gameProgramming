#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

int calc_frequency(int octave, int inx){
    double do_scale = 32.7032;
    double ratio = pow(2.0, 1.0/12.0), temp;
    int i;
    temp = do_scale*pow(2, octave-1);
    for(i=0; i<inx; i++){
        temp = (int)(temp+0.5);
        temp*=ratio;
    }
    return (int) temp;
}

void practice_piano(void){
    int index[] = {0, 2, 4, 5, 7, 9, 11, 12};
    int freq[8], code, i;
    for(i=0; i<8; i++)
        freq[i] = calc_frequency(4, index[i]);
    do{
        code= getch();
        if('i'<=code && code<='8'){
            code = 49;
            Beep(freq[code], 300);
        }
    }while ((code!=27));
}

int main(void){
    SetConsoleOutputCP(65001); // UTF-8 설정
    
    int index[] = {0, 2, 4, 5, 7, 9, 11, 12};
    int freq[8];
    int i;
    for(i=0; i<=7; i++)
            freq[i] = calc_frequency(4, index[i]);
    for(i=0; i<=7; i++)
            Beep(freq[i], 500);
    Sleep(1000);
    for(i=7; i>=0; i--)
            Beep(freq[i], 500);

    printf(
        "1부터 8까지 숫자 키를 누르며\n각 음의 소리가 출력 됩니다\n"
    );
    printf(
        "1:도 2:레 3:미 4:파 5:솔 6:라 7:사 8:도\n프로그램 종료는 Esc\n"
    );
    practice_piano();
        return 0;
}