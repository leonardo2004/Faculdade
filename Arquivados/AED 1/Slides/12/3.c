#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *prox;
    struct no *ant;
    int info;
} Tno;
typedef Tno *Pno;
typedef struct lista {
    struct no *inicio;
    struct no *fim;
} Tlista;
typedef Tlista *Plista;

Plista inicializa() {
    Plista lista = (Plista) malloc (sizeof(Tlista));
    if (lista == NULL) exit (0);
    lista->inicio = lista->fim = NULL;
    return lista;
}

void libera(Plista lista) {
    if (lista == NULL) return;
    Pno p = lista->inicio;
    while (p!=NULL) {
        lista->inicio = lista->inicio->prox;
        free(p);
        p = lista->inicio;
    }
}

Plista inserecres(Plista lista, int v) {
    Pno no = (Pno) malloc (sizeof(Tno));
    Pno p;
    if (no == NULL) exit(0);
    no->info = v;

    if (lista == NULL) return lista;//Lista não inicializada

    if (lista->inicio == NULL) {//Lista vazia
        lista->inicio = lista->fim = no;
        no->ant = no->prox = NULL;
        return lista;
    }

    if (v<lista->inicio->info) {//Insere no começo
        no->prox = lista->inicio;
        no->ant = NULL;
        lista->inicio->ant = no;
        lista->inicio = no; 
        return lista;
    }

    if (v>lista->fim->info) {//Insere no fim
        no->prox = NULL;
        no->ant = lista->fim;
        lista->fim->prox = no;
        lista->fim = no;
        return lista;
    }

    p = lista->inicio;
    while(p!=NULL && p->info<v) {
        p = p->prox;
    }

    no->prox = p;
    no->ant = p->ant;
    p->ant->prox = no;
    p->ant = no;
    return lista;
}

Plista listacres (Plista lista1, Plista lista2) {
    Plista output = inicializa();
    Pno p;
    p = lista1->inicio;
    while(p!=NULL) {
        output = inserecres(output, p->info);
        p=p->prox;
    }
    p = lista2->inicio;
    while(p!=NULL) {
        output = inserecres(output, p->info);
        p=p->prox;
    }
    return output;
}

int main (void) {
    Plista lista1 = inicializa();
    Plista lista2 = inicializa();
    Plista lista3;
    Pno no;
    lista1 = inserecres(lista1, 1);
    lista1 = inserecres(lista1, 11);
    lista1 = inserecres(lista1, 41);
    lista1 = inserecres(lista1, 15);
    lista1 = inserecres(lista1, 66);
    lista2 = inserecres(lista2, 3);
    lista2 = inserecres(lista2, 6);
    lista3 = listacres(lista1, lista2);
    no = lista3->inicio;
    while (no!=NULL) {
        printf("%i",no->info);
        no = no->prox;
    }

    libera(lista1);
    libera(lista2);
    libera(lista3);

}