#include <stdio.h> 

typedef struct abb {
    int info;
    struct abb *esq;
    struct abb *dir;
} Tabb;
typedef Tabb *Pabb;

Pabb cria(int v, Pabb esq, Pabb dir) {
    Pabb novo = (Pabb) malloc(sizeof(Tabb));
    novo->info = v;
    novo->esq = esq;
    novo->dir = dir;
}

Pabb inserir(Pabb a, int v) {
    if (a==NULL) return(cria(v,NULL,NULL));
    if (a->info > v) {
        a->esq = inserir (a->esq,v);
    }
    else a->dir = inserir (a->dir, v);
    return a;
}

int iguais(Pabb a, Pabb b) {
    if (a==NULL && b== NULL) return 1;
    if (a==NULL || b==NULL) return 0;
    return (iguais(a->esq, b->esq) && iguais(a->dir, b->dir));
}

int menor(Pabb a) {
    Pabb p;
    for (p=a; p->esq!=NULL; p=p->esq)
    return p->info;
}

void imprime_crescente(Pabb a) {
    if (a==NULL) return;
    imprime_crescente(a->esq);
    printf("%i",a->info);
    imprime_crescente(a->dir);
}

void show_menor(Pabb a, int x) {
    if (a==NULL) return;
    show_menor(a->esq,x);
    if (a->info<x) {
        printf("%i",a->info);
        show_menor(a->dir,x);
    }
}

Pabb remove(Pabb a, int v) {
    Pabb p, aux;
    if (a==NULL) return a;
    if (a->info> v) a->esq=remover(a->esq,v);
    else if(a->info < v) a->dir=remover(a->dir,v);
    else {
        if (a->dir == NULL && a->esq == NULL) {//Caso 0 filhos:
            free(a);
            return NULL;
        }
        if (a->dir==NULL) {//Caso 1 filho esquerda
            p = a->esq;
            free(a);
            return p;
        }
        if (a->esq==NULL) {//caso 1 filho direita
            p = a->dir;
            free(a);
            return p;
        }
        else {
            for (p=a->esq, aux = a; p->dir!=NULL; aux = p, p=p->dir);
            a->info = p->info;
            if (aux == a) a->esq = p->esq;
            else aux->dir = p->esq;
            free(p);
        }
    }
    return (a);
}


int verifica_abb(Pabb a){
    if (a==NULL) return 1;
    if (a->esq != NULL && a->esq->info>a->info) return 0;
    if (a->dir != NULL && a->dir->info<a->info) return 0;
    verifica_abb(a->esq && a->dir);
}

Pabb exclui_folhas(Pabb a) {
    if (a==NULL) return a;
    if (a->esq == NULL && a->dir == NULL) {
        free(a);
        return NULL;
    }
    exclui_folhas(a->esq);
    exclui_folhas(a->dir);
    return a;
}

int conta_folhas(Pabb a) {
    if (a==NULL) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    return (conta_folhas(a->esq)+conta_folhas(a->dir));
}
Pabb poda(Pabb a) {
    if (a==NULL) return a;
    a->esq = poda(a->esq);
    a->dir = poda(a->dir);
    free(a);
    return NULL;
}

Pabb remove_no_descendentes(Pabb a, int v){
    if (a==NULL) return a;
    if (a->info == v) return(poda(a));
    a->esq = remove_no_descendentes(a->esq,v);
    a->dir = remove_no_descendentes(a->dir,v);
    return a;
}

//falta:
// Escreva uma função que receba uma lista encadeada e
// construa uma ABB com os elementos desta lista. Liberar
// a lista.