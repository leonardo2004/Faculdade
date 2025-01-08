//Nome: Leonardo Tomasela Leal
//RA: 170291
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct arvore {
    char palavra[50];
    struct arvore *dir;
    struct arvore *esq;
} Tarv;
typedef Tarv *Parv;

Parv criano(char palavra[50]) {
    Parv arv = (Parv) malloc (sizeof(Tarv));
    strcpy(arv->palavra, palavra);
    arv->dir = arv->esq = NULL;
    return arv;
}

Parv insere(Parv arv, char palavra[50]) {
    int i;
    if (arv==NULL) //SE TA VAZIA
    {
        arv = criano(palavra);
        return arv;
    }
    if (!strcmp(arv->palavra, palavra)) return arv; //VERIFICA SE É IGUAL
 
    for (i=0; i<50; i++) {
        if (palavra[i]<arv->palavra[i]) 
        {
            arv->esq = insere(arv->esq, palavra);
            return arv;
        }
        else if (palavra[i]>arv->palavra[i]) 
        {
            arv->dir = insere(arv->dir, palavra);
            return arv;
        }
    }
}

void imprime(Parv arv) {
    if (arv==NULL) return;
    imprime(arv->esq);
    printf("%s\n", arv->palavra);
    imprime(arv->dir);
}

Parv libera (Parv arv) {
    if (arv == NULL) return arv;
    libera(arv->esq);
    libera(arv->dir);
    free(arv);
}

int main (void){
    char palavra[50];
    int i,j , numpalavras;
    Parv arvore = NULL;

    scanf("%i", &numpalavras);

    for (i=0; i<numpalavras; i++) {
        scanf("%s", palavra);
        for (j=0; j<strlen(palavra);j++) {
            if (palavra[j]>=65 && palavra[j]<=90) {
                palavra[j] += 32;
            }
        }
        arvore = insere(arvore,palavra);
    }

    imprime(arvore);


    arvore = libera(arvore);
    
    
}