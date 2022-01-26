Stampare se l'utente ha fatto ambo terno quaterna cinquina.

/******************************************************************************

Creare un esercizio sul gioco del lotto usando le funzioni.
L'utente inizialmente sceglie 5 numeri (diversi tra loro)
Poi avviene l'estrazione di 5 numeri (diversi tra loro)
Si controlla se l'utente ha fatto ambo, tris, ecc...
Si stampa il risultato


https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// ritorna 1 se il numero non è presente nell'arrey, -1 se il numero è già presente
int IsNumberPresent(int arreyToCheck[], int number, int arreySize);

// Chiede x numeri all'utente e li salva nell'arrey
void AskUserNumber(int arreyToCheck[], int arreySize);

// Mi torna un numero random. Da 1 a maxValue
int GetRandomNumber(int maxValue);

// Mi riempie l'arrey con x numeri random
void FillArreyLottoExtraction(int arreyToFill[], int arreySize);

// Stampo il risultato dell'utente
void ShowResult(int arreyToCheck[], int arreyLotto[], int arreySize);

int NumberToPick = 5;

int main()
{
   printf("Numero random= %d\n",GetRandomNumber(90));
    
    printf("Benvenuto al gioco del lotto\n");
    int userChoise[NumberToPick];
    int numbersReleased[NumberToPick];
    
    // Inizializziamo l'arrey con i numeri random
    FillArreyLottoExtraction(numbersReleased,NumberToPick);
    
    // Stampiamo il risultato
    for (int i = 0; i < NumberToPick; i++)
    {
        printf("Numeri random= %d \n",numbersReleased[i]);
    }
    
    
    AskUserNumber(userChoise, NumberToPick);
    
    ShowResult(userChoise,numbersReleased,NumberToPick);
    
    
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



void FillArreyLottoExtraction(int arreyToFill[], int arreySize)
{
    int correctNumbers = 0;
    sleep(1);
    do
    {
        int temp = GetRandomNumber(90);

        if (temp <= 0 || temp >= 91)
        {
            printf("\nErrore, numero non consentito nella funzione random\n");
        }
        else
        {
            if (IsNumberPresent(arreyToFill, temp, arreySize) == -1)
            {
                //printf("\nErrore numero già presente= %d", temp);
            }
            else
            {
                arreyToFill[correctNumbers] = temp;
                correctNumbers++;
            }
        }

    } while (!(correctNumbers == arreySize));
}


int GetRandomNumber(int maxValue){
    
   time_t t;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to x */
   return (rand() % (maxValue-1))+1;
   
}

void ShowResult(int arreyToCheck[], int arreyLotto[], int arreySize){
    
    int numbersTaken = 0;
    
    for (int i = 0; i < arreySize; i++){
        for (int j = 0; i < arreySize; j++){
            if (arreyToCheck[j] == arreyLotto[i]){
                printf("Numero Trovato\n");
                numbersTaken++;
                continue;
            }
        }
    }

}





