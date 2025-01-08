//Nome: Leonardo Tomasela Leal RA:170291
#include <stdio.h>
#include <stdlib.h>
#define lin 500
typedef struct no {
    int valor, col;
    struct no *prox;
} sno;
typedef sno *pno;
typedef pno matriz[lin];

void inicializa(matriz mat) {
    int i;
    for (i = 0; i<lin; i++) {
        mat[i] = NULL;
    }
}

pno criarno(pno prox, int col, int valor) {
    pno no = (pno) malloc(sizeof(sno));
    no->prox = prox;
    no->col = col;
    no->valor = valor;
    return no;
}

void inserir(matriz mat, int linha, int col, int valor) {
    pno ant, p;
    if ((linha>=lin || linha<0) || valor == 0) return; 
    for (ant = NULL, p=mat[linha]; p!= NULL && p->col < col; ant = p,p=p->prox);
    if (p!=NULL && p->col == col) p->valor = valor;
    else if (ant==NULL) mat[linha] = criarno(p, col, valor);
    else ant->prox = criarno(p, col, valor);

}

int remover(matriz mat, int linha, int col) {
    pno ant, p;
    if (linha>=lin || linha<0) return 0;
    for (ant = NULL, p = mat[linha]; p != NULL && p->col < col; ant = p, p = p->prox);
    if (p!=NULL && p->col == col) {
        p->valor--;
        if (p->valor == 0) {
            if (ant == NULL) mat[linha] = p->prox;
            else ant->prox = p->prox;
            free(p);
            return 1;
        }
        return 1;
    }
    return 0;
}

void liberar(matriz mat) {
    pno p;
	int i;
	for (i = 0; i < lin; i++) {
		for (p = mat[i]; mat[i] != NULL; p = mat[i]) { 
			mat[i] = p->prox;
			free(p);
		}
	}
}

int main(void) {
    int mtipos, ntamanhos, pedidos, i, j, entrada, saidalinha, saidacoluna, vendas = 0, valida;
    matriz mat;
    inicializa(mat);

    scanf("%i %i", &mtipos, &ntamanhos);

    for (i = 0; i<mtipos; i++) {
        for (j=0; j<ntamanhos; j++) {
            scanf("%i", &entrada);
            inserir(mat, i, j, entrada);
        }
    }

    scanf("%i", &pedidos);
    
    for (i = 0; i<pedidos; i++) {
        scanf("%i %i", &saidalinha, &saidacoluna);

        valida = remover(mat,(saidalinha-1),(saidacoluna-1));
        if (valida == 1) vendas++;
    }

    printf("%i", vendas);

    liberar(mat);

}