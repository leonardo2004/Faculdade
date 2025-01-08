//Nome: Leonardo Tomasela Leal RA:170291
//Algoritmo de ordenação - BubbleSort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Define a quantidade de valores a serem analizados
#define TAM 200

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

int main(void){
    //Declaração de variáveis
    clock_t horaInicial, horaFinal;
    double tempoTotal;
    int array[TAM];
    int numTroca = 0, i, aux;

    //Inicializa os valores em um vetor
    InicializaVetor("3.txt", array);
    
    //Inicializa o cronometro
    horaInicial = clock();

    //Algoritmo de ordenação
    do {
        numTroca = 0;
        for (i = 0; i<TAM-1; i++) {
            if (array[i] > array[i+1]) {
                aux = array[i];
                array[i] = array[i+1];
                array[i+1]=aux;
                numTroca++;
                }
        }
    } while (numTroca != 0);

    //Finaliza o cronometro
    horaFinal = clock();
    tempoTotal = ((double)(horaFinal - horaInicial))/CLOCKS_PER_SEC;

    //Impressão
    printf("%i ",array[0]);
    for (i = 1; i<TAM; i++) printf("- %i ",array[i]);
    printf("%lf",tempoTotal);
}