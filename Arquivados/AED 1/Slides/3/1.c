#include<stdio.h>

typedef struct {
    char nomebanda[70], produtoracd[70];
    int datacd[3], dataem[3], integrantes;
    float valor;
} cd;

int main(void) {
    cd abc[10];
    int cont;

    for (cont = 0; cont<10; cont++) {
        printf("Digite o nome da banda");
        scanf("%s", &abc[cont].nomebanda);

        printf("Digite a data de lançamento do CD (utilize a formatação DD MM AAAA)");
        scanf("%i %i %i", &abc[cont].datacd[0], &abc[cont].datacd[1], &abc[cont].datacd[2]);

        printf("Digite a data de contratação da empresa (utilize a formatação DD MM AAAA)");
        scanf("%i %i %i", &abc[cont].dataem[0], &abc[cont].dataem[1], &abc[cont].dataem[2]);

        printf("Digite o valor do CD");
        scanf("%f", &abc[cont].valor);

        printf("Digite o número de integrantes da banda");
        scanf("%i", &abc[cont].integrantes);

        printf("Digite o nome da produtora");
        scanf("%s", &abc[cont].produtoracd);
    }
    
}