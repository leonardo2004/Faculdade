//Nome: Leonardo Tomasela Leal RA:170291
//Algoritmo de ordenação - CountingSort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

//Define a quantidade de valores a serem analizados
#define TAM 100000

void InicializaVetor(char nomeArquivo[], int array[]) {
    FILE* file;
    char input[10];
    int i, arrayInput;
    
    file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Não foi possível abrir o arquivo");
        exit(0);
    }
    
    for (i = 0; i<TAM; i++) {
        fgets(input, 10 ,file);
        arrayInput = atoi(input);
        array[i] = arrayInput;
    }
    fclose(file);
}

void countingSort(int array[]) {
    int i, index = 0;
    int* countingArray;
    countingArray = calloc(N,sizeof(int));
    for (i=0; i<TAM; i++) {
        countingArray[array[i]]++;
    }

    for (i=0; i<N; i++) {
        while (countingArray[i]>0) {
            countingArray[i]--;
            array[index] = i;
            index++;
        }
    }

    free(countingArray);
}

int main(void){
    //Declaração de variáveis
    clock_t horaInicial, horaFinal;
    double tempoTotal;
    int array[TAM], i;

    //Inicializa os valores em um vetor
    InicializaVetor("1.txt", array);

    //Inicializa o cronometro
    horaInicial = clock();
    
    //Algoritmo de ordenação
    countingSort(array);

    //Finaliza o cronometro
    horaFinal = clock();
    tempoTotal = ((double)(horaFinal - horaInicial))/CLOCKS_PER_SEC;

    //Impressão
    printf("%i ",array[0]);
    for (i = 1; i<TAM; i++) printf("- %i ",array[i]);
    printf("%lf",tempoTotal);
}