#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUNAS 81
#define LINHAS 30

//CÓDIGO PARA LIDAR COM A FILA

typedef struct queue {
    int LINHA;
    int COLUNA;
    struct queue *prox;
} TQueue;
typedef TQueue *PQueue;


PQueue createNode(int LINHA, int COLUNA){
    PQueue new = (PQueue) malloc(sizeof(TQueue));
    if (!new) exit(0);
    new->prox = NULL;
    new->LINHA = LINHA;
    new->COLUNA = COLUNA;
    return new;
}

PQueue queueInsert(int LINHA, int COLUNA, PQueue queue) {
    PQueue aux;
    if (queue == NULL) {
        queue = createNode(LINHA, COLUNA);
        return queue;
    }
    for (aux = queue; aux->prox != NULL; aux=aux->prox);
    aux->prox = createNode(LINHA, COLUNA);
    return queue;
}

PQueue queueRemove(PQueue queue) {
    PQueue aux;
    if (queue == NULL) return queue;
    aux = queue;
    queue=queue->prox;
    free(aux);
    return queue;
}

PQueue freeQueue(PQueue queue) {
    while (queue != NULL) queue = queueRemove(queue);
    return queue;
}

//CÓDIGO PARA LER/IMPRIMIR O MAPA

void readMap(char map[LINHAS][COLUNAS]){
    int i;

    for (i = 0; i < LINHAS; i++) {
        fgets(map[i],COLUNAS,stdin);
        if (map[i][0]=='_') break;
    }
}

void printMap(char map[LINHAS][COLUNAS]){
    int i;

    for (i = 0; i < LINHAS && map[i-1][0] != '_'; i++) {
        puts(map[i]);
    }
}

//CÓDIGO PARA ENCONTRAR O ROBO (APENAS VERIFICANDO OS CENTROS DAS SALAS)

void findRobot(char map[LINHAS][COLUNAS], int start[2]) {
    int i,j;
    for (i=2; i<LINHAS; i+=4) {
        for (j=2; j<COLUNAS; j+=4) {
            if (map[i][j] == '*') {
                start[0] = i; 
                start[1] = j;
                return;
            }
        }
    }
}

//BESTEIRA :D

int isCleaned(char tile) {
    if (tile == ' ') return 0;
    else return 1;
}

int isWall(char tile, char wall) {
    if (tile == wall) return 1;
    else return 0;
}

void initializeFlag(int flag[LINHAS][COLUNAS]) {
    int i,j;
    for (i=0; i<LINHAS; i++) for (j=0;j<COLUNAS;j++) {
        flag[i][j] = 0;
    }
}

//TORTURA (BFS)

int BFS(char map[LINHAS][COLUNAS], int flags[LINHAS][COLUNAS], PQueue *queue,char wall) {
    int i, j, count = 0;

    while (*queue != NULL) {
        i = (*queue)->LINHA;
        j = (*queue)->COLUNA;
        *queue = queueRemove(*queue);

        // Se já foi visitado ou é uma parede, pula
        if (flags[i][j] == 1 || isWall(map[i][j],wall)) continue;

        // Marca como visitado
        flags[i][j] = 1;

        // Incrementa o contador apenas para células com espaço vazio
        if (!isCleaned(map[i][j])) count++;

        // Adiciona células vizinhas à fila
        if (i + 1 < LINHAS && !isWall(map[i+1][j],wall) && flags[i + 1][j] == 0)
            *queue = queueInsert(i + 1, j, *queue);
        if (i - 1 >= 0 && !isWall(map[i-1][j], wall) && flags[i - 1][j] == 0)
            *queue = queueInsert(i - 1, j, *queue);
        if (j + 1 < COLUNAS && !isWall(map[i][j+1],wall) && flags[i][j + 1] == 0)
            *queue = queueInsert(i, j + 1, *queue);
        if (j - 1 >= 0 && !isWall(map[i][j-1], wall) && flags[i][j - 1] == 0)
            *queue = queueInsert(i, j - 1, *queue);
    }

    return count;
}



int main(void) {
    char wall;
    char map[LINHAS][COLUNAS];
    int flag[LINHAS][COLUNAS];
    int start[2];
    int resultado;
    PQueue filaTeste = NULL;
    
    initializeFlag(flag);
    
    readMap(map);

    wall = map[0][0];
    findRobot(map, start);
    //printMap(map);

    filaTeste = queueInsert(start[0],start[1], filaTeste);
    resultado = BFS(map, flag, &filaTeste,wall);
    printf("%i", resultado);
    filaTeste = freeQueue(filaTeste);

}