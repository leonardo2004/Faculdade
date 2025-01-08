//Nome: Leonardo Tomasela Leal RA:170291
//Algoritmo para gerar números aleatórios
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int main(void) {
    //Declaração de variáveis
    int i, number;
    FILE* file;

    //Criando um arquivo para armazenar os valores
    file = fopen("New_file.txt", "a");

    //Verifica se o arquivo foi criado e aberto com sucesso
    if (file == NULL) {
        printf("O arquivo não foi aberto.");
        exit(0);
    }

    //Gera uma lista números aleatórios e grava ela no arquivo, sendo cada linha um valor
    srand(time(NULL));
    for (i=0; i<N; i++) {
        number = rand();
        fprintf(file,"%i\n", number);
    }

    //Fecha o arquivo
    fclose(file);
}