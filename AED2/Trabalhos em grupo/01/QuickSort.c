//Nome: Leonardo Tomasela Leal RA:170291
//Algoritmo de ordenação - QuickSort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

void quicksort(int array[], int indexA, int indexB) {
    int i, j, aux, aux2;
    i = indexA - 1;
    j = indexA;
    if((indexA - indexB) == 1 || (indexB - indexA) == 1) return;

    while (j<indexB) {
        if (array[j]<array[indexB]) {
            i++;
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
        j++;
    }
    aux = array[indexB];
    for (aux2 = indexB; aux2>i+1; aux2--) {
        array[aux2] = array[aux2-1];
    }
    array[i+1] = aux;
    quicksort(array, indexA, i);
    quicksort(array, i+2, indexB);

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
    quicksort(array, 0, TAM-1);

    //Finaliza o cronometro
    horaFinal = clock();
    tempoTotal = ((double)(horaFinal - horaInicial))/CLOCKS_PER_SEC;

    //Impressão
    printf("%i ",array[0]);
    for (i = 1; i<TAM; i++) printf("- %i ",array[i]);
    printf("%lf",tempoTotal);
}