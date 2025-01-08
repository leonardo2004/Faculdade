#include <stdio.h>
#include <stdlib.h>

typedef struct no2 {
    struct no2* prox;
    struct no2* ant;
    int info;
} Tno2;
typedef Tno2 *Pno2;
typedef struct lista2 {
    struct no2* ini;
    struct no2* fim;
} Tlista2;
typedef Tlista2 *Plista2;

Plista2 inicializa(){
    Plista2 novo = (Plista2) malloc (sizeof(Tlista2));
    if (novo == NULL) exit (0);
    novo->ini = novo->fim = NULL;
    return novo;
}

Plista2 insere(Plista2 lista, int v) {
    Pno2 novo = (Pno2) malloc (sizeof(Tno2));
    novo->info = v;
    novo->prox = NULL;
    if (lista->ini == NULL) {
        novo->ant = NULL;
        lista->ini = lista->fim = novo;
        return lista;
    }
    novo->ant = lista->fim;
    lista->fim->prox = novo;
    lista->fim = novo;
    return lista;
}

void libera(Plista2 lista) {
    Pno2 p = lista->ini;
    while (p != NULL) {
        lista->ini = p->prox;
        free(p);
        p = lista->ini;
    }
    lista->fim = lista->ini = NULL;
}

int main(void) {
    Plista2 Casas, Cartas;
    int n, m, output;//N casas, M cartas
    int i, input; //Contador e input
    output = 0; //Inicializando a saida com 0
    Casas = inicializa();
    Cartas = inicializa();
    Pno2 c, p; //Nós utilizados para percorrer a lista

//Inserindo os valores nas listas
    scanf("%i %i", &n, &m);
    for (i=0; i<n; i++) {
        scanf("%i",&input);
        Casas = insere(Casas, input);
    }
    for (i=0; i<m; i++) {
        scanf("%i",&input);
        Cartas = insere(Cartas, input);
    }


//Programa que faz o pedido:
    c = Cartas->ini;//Atribui o inicio da lista de cartas a um nó c que vai percorrer a lista
    p = Casas->ini;//Atribui o inicio da lista de casas a um nó p que vai percorrer a lista
    while(c!=NULL && p!=NULL) {
        if(p != NULL && c->info == p->info)//Verifica se a casa é igual ao destino da carta
            c = c->prox;//Aqui não há soma de um valor em output pois já está na casa necessária
        else if(p != NULL && c->info > p->info) {//Percorre a lista para a direita
            while(c != NULL && p != NULL && c->info!=p->info) {
                p=p->prox;
                output++;
            }
            c = c->prox;
        } 
        else if (p != NULL && c->info < p->info) {//Percorre a lista para a esquerda
            while(c != NULL && p != NULL && c->info!=p->info){
                p=p->ant;
                output++;
            }
            c = c->prox;
        }
    }

//Imprimindo resultado
    printf("%i",output);

//Liberando as listas:
    libera(Cartas);
    libera(Casas);
    c = p = NULL;

    return 0;
}