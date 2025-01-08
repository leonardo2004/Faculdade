#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    char nome[70];
    data dlanc;
    data dcont;
    int valor;
    int membros;
    char produtora[70];
} cd;

int main(void){
    int n, i;
    cd* cds[100];

    printf("Quantos deseja inserir? ");
    scanf("%i",&n);

    for (i = 0; i<n; i++) {
        cds[i] = (cd*) malloc(sizeof(cd));
        scanf("%s", &cds[i]->nome);
    }



    for (i = 0; i<n; i++) {
        free(cds[i]);
    }
    


    return 0;
}