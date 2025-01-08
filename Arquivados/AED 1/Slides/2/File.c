//Nome: Leonardo Tomasela Leal RA: 170291
//Programa que conta o número de linhas, não conta linhas vazias.

#include <stdio.h>

int main(void) {
    //Declarando variáveis
    FILE* arquivo;
    char letra;
    int nlinhas = 0, nletraslinha = 0;

    //Abre o arquivo e verifica se foi aberto corretamente
    arquivo = fopen("arquivo.txt", "r");
    if (!arquivo) {
        printf("Não fui capaz de abrir o arquivo");
        exit(0);
        }

    //Algoritmo:
    // Le cada letra enquanto ela não representar EOF e soma o número de linhas e o número de letras em cada linha
    letra = fgetc(arquivo);
    while (letra!=EOF) {

        if (fgetc(arquivo) == '\n') 
        {
            nlinhas++;
            nletraslinha = 0;
        }
        else nletraslinha++;

        letra = fgetc(arquivo);
    }

    //Analisa de a última linha está vazia (Se o número de letras na última linha for maior do que 0)
    if (nletraslinha > 0) 
    {
        nlinhas++;
    }

    //Fecha o arquivo
    fclose(arquivo);

    //Imprime o número de linhas
    printf("%i linhas", nlinhas);

    return 0;
}