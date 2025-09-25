#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

typedef struct trump
{
    int order;
    char shape[5];   // 카드 모양 (♠, ♦, ♥, ♣)
    char number[3];  // "2"~"10", "A", "J", "Q", "K"
} trump;

void make_card(trump m_card[])
{
    char shape[4][4] = {"♠", "♦", "♥", "♣"};

    for (int i = 0; i < 4; i++)
    {
        for (int j = i * 13; j < i * 13 + 13; j++)
        {
            m_card[j].order = i;
            strcpy(m_card[j].shape, shape[i]);

            int num = j % 13 + 1;

            // 숫자를 카드 문자로 변환 (switch문 유지)
            switch (num)
            {
            case 1:
                strcpy(m_card[j].number, "A");
                break;
            case 11:
                strcpy(m_card[j].number, "J");
                break;
            case 12:
                strcpy(m_card[j].number, "Q");
                break;
            case 13:
                strcpy(m_card[j].number, "K");
                break;
            default:
                sprintf(m_card[j].number, "%d", num); // 2~10
            }
        }
    }
}

void display_card(trump m_card[])
{
    for (int i = 0; i < 52; i++)
    {
        // shape + number 출력 (문자열 그대로)
        printf("%s%-2s ", m_card[i].shape, m_card[i].number);

        if (i % 13 == 12)
            printf("\n");
    }
}

void shuffle_card(trump m_card[]){
    int i, rnd;
    trump temp;
    srand(time(NULL));
    for(i=0;i<52;i++){
        rnd = rand() %52;
        temp = m_card[rnd];
        m_card[rnd] = m_card[i];
        m_card[i] = temp;
    }
}

int main(void)
{
    SetConsoleOutputCP(65001); // UTF-8 설정

    trump card[52];
    make_card(card);
    shuffle_card(card);
    display_card(card);

    return 0;
}
