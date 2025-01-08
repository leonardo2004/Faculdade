//Nome: Leonardo Tomasela Leal 
//RA: 170291
//Judge 07 -> Grafos (Detectando pontes)
#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int valor;
    struct lista *prox;
    struct lista *ant;
} Tlista;
typedef Tlista *Plista;
typedef struct mat {
    int coluna;
    int valor;
    struct mat *prox;
} Tmat;
typedef Tmat *Pmat;
typedef Pmat *Matriz;


Plista addlistainicio(Plista lista, int valor){
    Plista novo = (Plista) malloc(sizeof(Tlista));
    novo->valor = valor;
    if (lista == NULL) {
        lista = novo;
        lista->prox = NULL;
        lista->ant = NULL;
        return lista;
    }
    novo->prox = lista;
    lista->ant = novo;
    novo->ant=NULL;
    lista = novo;
    return lista;
    }
Plista removeinstancia(Plista lista, int valor) {
    Plista aux;
    if (lista==NULL) return lista;
    for (aux=lista; aux!=NULL && aux->valor!=valor; aux=aux->prox);

    if (aux==NULL) return lista;

    if (aux->prox!=NULL)aux->prox->ant = aux->ant;// NÃO É O ULTIMO ELEMENTO
    if (aux->ant != NULL)aux->ant->prox = aux->prox;// NÃO É O PRIMEIRO ELEMENTO
    else if (aux->ant == NULL){//É O PRIMEIRO ELEMENTO
        lista = lista->prox;
        if (lista != NULL) lista->ant = NULL;
    }
    free(aux);
    return lista;
}
void liberalista(Plista lista) {
    Plista aux;
    if (lista==NULL) return;
    for (aux = lista; aux != NULL; aux = lista) {
        lista=lista->prox;
        free(aux);
    }
    return;
}
int verificalista(Plista lista, int valor) {
    Plista aux;
    if (lista==NULL) return 0;
    for (aux=lista; aux!=NULL && aux->valor != valor; aux = aux->prox);
    if (aux == NULL) return 0;
    return 1;
}

Matriz inici(int tamanho) {
    int i;
    Matriz novo = (Matriz) malloc (sizeof(Pmat)*tamanho);
    for (i = 0; i<tamanho; i++) {
        novo[i] = NULL;
    }
    return novo;
}
Pmat criarno(int coluna, int valor, Pmat prox) {
    Pmat novo = (Pmat) malloc (sizeof(Tmat));
    novo->coluna = coluna;
    novo->valor = valor;
    novo->prox = prox;
    return novo;
}
void inserir(Matriz matriz, int linha, int coluna, int valor) {
    Pmat ant, p;
	if (valor == 0) return; 
	for (ant = NULL, p = matriz[linha]; p != NULL && p->coluna < coluna; ant = p, p = p->prox); 
	if (p != NULL && p->coluna == coluna) p->valor = valor; 
	else if (ant == NULL) matriz[linha] = criarno(coluna, valor, p); 
	else ant->prox = criarno(coluna, valor, p); 
}

void liberamatriz(Matriz mat, int tamanho) {
    int i; Pmat aux;
    for (i=0; i<tamanho; i++) {
        while (mat[i]!=NULL) {
            aux = mat[i];
            mat[i] = mat[i]->prox;
            free(aux);
        }
    }
    free(mat);
}
int verifica(Matriz mat, int coluna, int linha) {
    Pmat aux;
    if (mat[linha]==NULL) return 0;
    for (aux=mat[linha]; aux!=NULL && aux->coluna!=coluna && aux->coluna<coluna; aux=aux->prox);
    if (aux == NULL) return 0;
    if (aux->coluna!=coluna) return 0;
    if (aux->valor == 1) return 1;
    return 0;
}

int main(void) {
    int C, P, i, X, Y, j, ciclo = 0;
    Plista lista = NULL;
    Matriz matriz;

    scanf("%i %i", &C, &P);
    matriz = inici(C);

    for (i=0; i<P;i++) {
        scanf("%i %i", &X, &Y);
        if (X<Y) inserir(matriz, X-1, Y-1, 1);
        if (X>Y) inserir(matriz, Y-1, X-1, 1);
    }

    for (i = 0; i<(C-1); i++) {
        lista = removeinstancia(lista, i);
        for (j=i+1; j<C; j++) {
            if (verifica(matriz, j, i) == 1) {
                if (verificalista(lista, j) == 0) lista = addlistainicio(lista, j); 
                else {
                    ciclo++;
                }
            }
        }
    }
    printf("%i", ciclo);
    liberalista(lista);
    liberamatriz(matriz, C);
}