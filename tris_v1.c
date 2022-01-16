#include <stdio.h>

// 1) Abbiamo spostato la stampa dela scacchiera in una funzione
// 2) Inizio della ri-scrittura della funzione SetPlayer()
 
void StampaScacchiera(int arr[]);
void SetPlayer();

int main()
{

    int winner = 0, count = 0;
    int data[9], index, sign, player, flag, i, k, j;

    // inizializzo la scacchiera
    for (i = 0; i < 9; i++)
        data[i] = ' ';

    while (count < 9)
    {
        flag = 0;
        StampaScacchiera(data);

        printf("Move for player%d(1-9):", player);
        scanf("%d", &index);
        if (index < 1 || index > 9)
        {
            printf("Allowed index is 1 to 9!!\n");
            continue;
        }
        if (data[index - 1] == 'X' || data[index - 1] == 'Y')
        {
            printf("Position Already occupied!!\n");
            continue;
        }
        data[index - 1] = sign;
        count++;

        for (i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
                flag = 0;

            if (data[i] == sign)
                flag++;

            if (flag == 3)
            {
                winner = 1;
                goto win;
            }
        }

        flag = 0;
        for (i = 0; i < 3; i++)
        {
            for (k = i; k <= i + 6; k = k + 3)
            {
                if (data[k] == sign)
                    flag++;
            }
            if (flag == 3)
            {
                winner = 1;
                goto win;
            }
            flag = 0;
        }
        if ((data[0] == sign && data[4] == sign && data[8] == sign) ||
            (data[2] == sign && data[4] == sign && data[6] == sign))
        {
            winner = 1;
            goto win;
        }
    }

win:
    StampaScacchiera(data);
    if (winner)
    {
        printf("Player %d is the winner. Congrats!!\n", player);
    }
    else
    {
        printf("Match draw.. Best of luck for both\n");
    }
    return 0;
}

void StampaScacchiera(int arr[])
{
    printf("\n\n");
    printf("\t\t\t  %c | %c  | %c  \n", arr[0], arr[1], arr[2]);
    printf("\t\t\t----+----+----\n");
    printf("\t\t\t  %c | %c  | %c  \n", arr[3], arr[4], arr[5]);
    printf("\t\t\t----+----+---\n");
    printf("\t\t\t  %c | %c  | %c  \n", arr[6], arr[7], arr[8]);
}

void SetPlayer(int count, int sign, int player)
{
    if (count % 2 == 0)
    {
        sign = 'X';
        player = 1;
    }
    else
    {
        sign = 'Y';
        player = 2;
    }
}