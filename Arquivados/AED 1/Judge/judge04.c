//NOME: LEONARDO TOMASELA LEAL RA: 170291
#include <stdio.h>
#include <stdlib.h>

typedef struct no { //Estrutura do nó
    int info;
    struct no* prox;
} Tno;
typedef Tno *Pno;

typedef struct fila { //Estrutura da fila
    Pno inicio;
    Pno fim;
} Tfila;
typedef Tfila *Pfila;

Pfila inicializa() { //Função para inicialiar a fila
    Pfila fila = (Pfila) malloc (sizeof(Tfila));
    if(!fila) exit(0); //Verificando se a fila foi alocada corretamente
    fila->inicio = fila->fim = NULL;
    return fila;
}

Pfila insere(Pfila fila, int v) { //Função para inserir na fila
    Pno novo = (Pno) malloc (sizeof(Tno));
    if (!novo) exit(0); //Verificando se o nó foi alocado corretamente
    novo->info = v;
    novo->prox = NULL;
    if (fila->inicio == NULL) {
        fila->inicio = fila->fim = novo;
        return fila;
    }
    fila->fim->prox = novo;
    fila->fim = novo;
    return fila;
}

 void libera(Pfila fila) { //Função para liberar a fila
    Pno no = fila->inicio;
    while(!no) {
        fila->inicio = fila->inicio->prox;
        free(no);
        no = fila->inicio;
    }
    free(fila);
 }

 int main() {
    int ncaixas, input, i, j, pont, pontmax = 100;
    Pfila fila = inicializa(fila); //Inicializa a fila
    Pno per;

    scanf("%i", &ncaixas); //Escaneando o número de caixas
    for (i = 0; i<ncaixas; i++) { //Loop para escanear o valor de cada caixa e verificar o maior premio possível
        scanf("%i", &input); //Escaneando o valor da caixa
        fila = insere(fila, input); //Inserindo o valor na fila
        per = fila->inicio; //Atribuindo um nó ao inicio da fila
        pont = 100; //Atribuindo o valor base ao número de pontos verificados nesse loop
        pont += per->info; //Somando o valor do primeiro elemento da fila
        for (j = 0; j < i; j++) { //Loop secundário que verifica a possibilidade contando de j até i. Ex: De 0 até 1, de 0 até 2, de 0 até 3, ..., de 0 até ncaixas
            per = per->prox; //O nó que percorre a fila recebe o próximo
            pont += per->info; //O valor do próximo é somado ao número de pontos verificados nesse loop
        }
        if (pont > pontmax) pontmax = pont;
    }

    printf("%i", pontmax);
    free(per);
    libera(fila);
}