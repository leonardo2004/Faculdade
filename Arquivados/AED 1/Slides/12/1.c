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
} Tlista;
typedef Tlista *Plista;

Plista inicializa(){
    Plista lista = (Plista) malloc(sizeof(Tlista));
    if (!lista) exit(0);
    lista->fim = NULL;
    return lista;
}

Plista insere(Plista lista, int v) {
    Pno no = (Pno) malloc (sizeof(Tno));
    if (!no) exit(0);
    no->info = v;
    no->prox = NULL;
    if (lista->fim == NULL) {
        no->ant = NULL;
        lista->fim = no;
        return lista;
    }
    no->ant = lista->fim;
    lista->fim = no;
    return lista;
}

Plista remover(Pno no, Plista lista) {
    if(lista->fim == NULL) return lista;//LISTA VAZIA
    if (no->ant == NULL) {//1 ELEMENTO
        lista->fim = no->prox;
        if (no->prox != NULL)
            no->prox->ant = NULL;
        free(no);
        return lista;
    }
    if (no == lista->fim) {//Ultimo ELEMENTO
        no->ant->prox = NULL;
        lista->fim = no->ant;
        free(no);
        return lista;
    }
    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    free(no);
    return lista;
}

void libera(Plista lista) {
    Pno p = lista->fim;
    while(p!=NULL) {
        p = lista->fim;
        lista->fim = p->ant;
        free(p);
    }
    free(lista);
}

Pno busca(Plista lista, int v) {
    Pno p = lista->fim;
    while (p != NULL) {
        if (p->info == v) {
            return p;
        }
        p = p->ant;
    }
    return NULL;
}

Plista removey(Plista lista, int v) {
    Pno no = busca(lista, v);
    while (no != NULL) {
        lista = remover(no, lista);
        no = busca(lista, v);
    }
    return lista;
}
int main(void) {
    Plista lista = inicializa();
    lista = insere(lista, 5);
    lista = insere(lista, 5);
    lista = insere(lista, 5);
    lista = insere(lista, 5);
    lista = insere(lista, 5);
    lista = insere(lista, 4);
    lista = removey(lista, 5);
    if (lista->fim != NULL) {
        printf("%iaaa", lista->fim->info);
    } else {
        printf("List is empty.\n");
    }

    libera(lista);

}
