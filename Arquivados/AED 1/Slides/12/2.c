#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *prox;
    struct no *ant;
    int info;
} Tno;
typedef Tno *Pno;
typedef struct lista {
    struct no *fim;
    struct no *inicio;
} Tlista;
typedef Tlista *Plista;

Plista inicializa(){
    Plista lista = (Plista) malloc (sizeof(Tlista));
    if (lista==NULL) exit (0);
    lista->fim = lista->inicio = NULL;
    return lista;
}

Plista inserecresc(Plista lista, int v) {
    Pno novo = (Pno) malloc (sizeof(Tno));
    Pno p;
    novo->info = v;
    if (novo == NULL) exit (0);
    if (lista == NULL) return lista; //lista nao inicializada
    if (lista->inicio == NULL) {//lista vazia
        lista->inicio = lista->fim = novo;
        novo->prox = novo->ant = NULL;
        return lista;
    }
    p = lista->inicio;
    while(p != NULL && p->info<novo->info) {
        p = p->prox;
    }
    if (p==NULL) { //inserindo no fim
        novo->ant = lista->fim;
        novo->prox = NULL;
        lista->fim->prox = novo;
        lista->fim = novo;
        return lista;
    }
    if (p==lista->inicio) {//inserindo no inicio
        lista->inicio = novo;
    }
    novo->prox = p;
    novo->ant = p->ant;
    if (p->ant != NULL)
    p->ant->prox = novo;
    p->ant = novo;
    return lista;
}

void libera(Plista lista){
    Pno p = lista->inicio;
    while (p!=NULL) {
        p = lista->inicio;
        lista->inicio = p->prox;
        free(p);
    }
    free(lista);

}

int main (void) {
    Plista lista = inicializa();
    Pno p;
    lista = inserecresc(lista, 5);
    lista = inserecresc(lista, 4);
    lista = inserecresc(lista, 3);
    lista = inserecresc(lista, 2);
    printf("por aqui tudo bme");
    
    for (p = lista->inicio; p != NULL; p = p->prox) {
        printf("%i ", p->info);
    }

    libera(lista);

}