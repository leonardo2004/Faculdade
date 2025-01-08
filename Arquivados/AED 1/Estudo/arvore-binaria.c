#include <stdio.h>

typedef struct arvore {
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Tarv;
typedef Tarv *Parv;

Parv cria(int info, Parv esq, Parv dir) {
    Parv novo = (Parv) malloc (sizeof(Tarv));
    novo->esq = esq;
    novo->dir = dir;
    novo->info = info;
}

Parv libera(Parv a) {
    if (a==NULL) return NULL;
    a->esq = libera(a->esq);
    a->dir = libera(a->dir);
    free(a);
    return NULL;
}

void imprimir_prefixo(Parv a) {//Imprimir na ordem raiz, esquerda, direita
    if (a==NULL) return;
    printf("%d", a->info);
    imprimir_prefixo(a->esq);
    imprimir_prefixo(a->dir);
}

void imprimir_infixo (Parv a) {//Imprimir na ordem esquerda, raiz, direita
    if (a==NULL) return;
    imprimir_infixo(a->esq);
    printf("%i", a->info);
    imprimir_infixo(a->dir);
}

void imprimir_posfixo(Parv a) {//Imprimir na ordem esquerda, direita, raiz
    if (a==NULL) return;
    imprimir_prefixo(a->esq);
    imprimir_prefixo(a->dir);
    printf("%d", a->info);
}

Parv buscaNo(Parv a, int v) {
    Parv p;
    if (a==NULL) return NULL;
    if (a->info == v) return a;
    p = buscaNo(a->esq,v);
    if (p!=NULL) return p;
    else return(buscaNo(a->dir, v));
    
}

int busca(Parv a, int v) {
    if (a==NULL) return 0;
    if (a->info == v) return a;
    return (busca(a->esq,v)||busca(a->dir,v));
}

int quant_nos (Parv a) {
    if (a==NULL) return 0;
    return(quant_nos(a->esq)+quant_nos(a->dir)+1);
}

int altura(Parv a) {
    int esq, dir;
    if (a==NULL) return -1;
    esq = altura(a->esq+1);
    dir = altura(a->dir+1);
    if (esq>dir) return esq;
    else return dir;
}

int busca(Parv a, char c) {
    if (a==NULL) return 0;
    if (a->info==c) return 1;
    return(busca(a->esq,c)||busca(a->dir,c));
}

int main(void) {

}