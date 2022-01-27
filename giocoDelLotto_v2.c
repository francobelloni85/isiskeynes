/******************************************************************************
C'è un BUG Stampa l'arrey finale in modo sbagliato

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

// Riempi un arrey con dei numeri. Puo essere inizializzata da umano o pc
// isHuman = 0 come se fosse falso Riempi il pc
// isHuman = 1 come riempie l'utente
void FillArreyWithNumber(int arreyToFill[], int arreySize, int isHuman);

// Mi torna un numero random. Da 1 a maxValue
int GetRandomNumber(int maxValue, int seed);

// Stampo il risultato dell'utente
void ShowResult(int arreyLotto[], int arreyToCheck[], int arreySize);

int NumberToPick = 5;

int main()
{
   
    printf("Benvenuto al gioco del lotto\n");
    int userChoise[NumberToPick];
    int numbersReleased[NumberToPick];
    
    // Inizializziamo l'arrey con i numeri random (PC)
    
    FillArreyWithNumber(numbersReleased,NumberToPick,0);
    
    // Stampiamo il risultato
    for (int i = 0; i < NumberToPick; i++)
    {
        printf("Numeri random= %d \n",numbersReleased[i]);
    }
    
    // Inizializziamo l'arrey con i numeri chiesti all'utente
    FillArreyWithNumber(userChoise, NumberToPick,1);
    
    ShowResult(numbersReleased,userChoise,NumberToPick);
    
    
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

void FillArreyWithNumber(int arreyToCheck[], int arreySize, int isHuman)
{
    int correctNumbers = 0;
    
    // Idea
    // Inizio uso il tempo
    // Poi uso la somma dei numeri fino ad esso estratti
    int sumNumbers = 0;
    
    do
    {
        int temp = 0;
        
        if (isHuman == 0){
            int c = correctNumbers + 1;
            printf("\n Inserisci un numero %d: ", c);
            scanf("%d", &temp);
        }else{
            temp = GetRandomNumber(90, sumNumbers);
            sumNumbers = sumNumbers + temp;
        }
        

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


// Se seed è 0 allora uso il tempo
// Se seed è != 0 allora uso il numero che gli passo
int GetRandomNumber(int maxValue, int seed){
   
    if (seed == 0){
     time_t t;
     srand(time(NULL));
    }else{
      srand(seed);
    }

   /* Print 5 random numbers from 0 to x */
   return (rand() % (maxValue-1))+1;
   
}

void ShowResult(int arreyLotto[], int arreyToCheck[], int arreySize){
    
    int numbersTaken = 0;
    
    for (int i = 0; i < arreySize; i++){
        for (int j = 0; j < arreySize; j++){
            if (arreyToCheck[j] == arreyLotto[i]){
                numbersTaken++;
            }
        }
    }
    
    switch (numbersTaken)
    {
        case 2:
        printf("Hai fatto ambo \n");
        break;
        
        case 3:
        printf("Hai fatto terno \n");
        break;
        
        case 4:
        printf("Hai fatto quaterna \n");
        break;
        
        case 5:
        printf("Hai fatto cinquina \n");
        break;
        
        default:
        printf("Non hai vinto\n");
        break;
    }
    
    printf("I numeri usciti sono: \n");
    for (int i = 0; i < arreySize; i++){
        printf("  %d",arreyLotto[i] );
    }

}




