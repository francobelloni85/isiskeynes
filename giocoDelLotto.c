/******************************************************************************

Creare un esercizio sul gioco del lotto usando le funzioni.
L'utente inizialmente sceglie 5 numeri (diversi tra loro)
Poi avviene l'estrazione di 5 numeri (diversi tra loro)
Si controlla se l'utente ha fatto ambo, tris, ecc...
Si stampa il risultato


https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c

*******************************************************************************/

#include <stdio.h>

// ritorna 1 se il numero non è presente nell'arrey, -1 se il numero è già presente
int IsNumberPresent(int arreyToCheck[], int number, int arreySize);

// Chiede x numeri all'utente e li salva nell'arrey
void AskUserNumber(int arreyToCheck[], int arreySize);

int NumberToPick = 5;

int main()
{
    printf("Benvenuto al gioco del lotto\n");
    int userChoise[NumberToPick];
    AskUserNumber(userChoise, NumberToPick);
    return 0;
}

// ritorna 1 se il numero non è presente, -1 se il numero è già presente
int IsNumberPresent(int arreyToCheck[], int number, int arreySize)
{
    for (int i = 0; i < arreySize; i++)
    {
        if (arreyToCheck[i] == number)
        {
            return -1;
        }
    }
    return 1;
}

void AskUserNumber(int arreyToCheck[], int arreySize)
{
    int correctNumbers = 0;

    do
    {
        int c = correctNumbers + 1;
        printf("\n Inserisci un numero %d: ", c);

        int temp = 0;
        scanf("%d", &temp);

        if (temp <= 0 || temp >= 91)
        {
            printf("\nErrore, numero non consentito\n");
        }
        else
        {
            if (IsNumberPresent(arreyToCheck, temp, arreySize) == -1)
            {
                printf("\nErrore numero già presente");
            }
            else
            {
                arreyToCheck[correctNumbers] = temp;
                correctNumbers++;
            }
        }

    } while (!(correctNumbers == arreySize));
}
