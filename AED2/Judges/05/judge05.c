#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUNAS 81
#define LINHAS 30

// Definição da estrutura da fila
typedef struct queue {
    int LINHA;
    int COLUNA;
    struct queue *prox;
} TQueue;

typedef TQueue *PQueue;

// Funções para manipulação da fila
PQueue createNode(int LINHA, int COLUNA) {
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
    for (aux = queue; aux->prox != NULL; aux = aux->prox);
    aux->prox = createNode(LINHA, COLUNA);
    return queue;
}

PQueue queueRemove(PQueue queue) {
    PQueue aux;
    if (queue == NULL) return queue;
    aux = queue;
    queue = queue->prox;
    free(aux);
    return queue;
}

// Função para ler o mapa
void readMap(char map[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        fgets(map[i], COLUNAS, stdin);
        if (map[i][0] == '_') {  // Marca o fim do mapa
            map[i][0] = '\0';
            break;
        }
    }
}

// Função para encontrar a posição inicial do robô
void findRobot(char map[LINHAS][COLUNAS], int start[2]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (map[i][j] == '*') {
                start[0] = i;
                start[1] = j;
                return;
            }
        }
    }
}

// Função BFS para explorar o mapa e contar células limpas
int BFS(char map[LINHAS][COLUNAS], int flags[LINHAS][COLUNAS], PQueue queue) {
    int i, j, count = 0;

    while (queue != NULL) {
        i = queue->LINHA;
        j = queue->COLUNA;
        queue = queueRemove(queue);

        // Se já foi visitado ou é uma parede, pula
        if (flags[i][j] == 1 || map[i][j] == 'X') continue;

        // Marca como visitado
        flags[i][j] = 1;

        // Incrementa o contador apenas para células com espaço vazio
        if (map[i][j] == ' ') count++;

        // Adiciona células vizinhas à fila
        if (i + 1 < LINHAS && map[i + 1][j] != 'X' && flags[i + 1][j] == 0)
            queue = queueInsert(i + 1, j, queue);
        if (i - 1 >= 0 && map[i - 1][j] != 'X' && flags[i - 1][j] == 0)
            queue = queueInsert(i - 1, j, queue);
        if (j + 1 < COLUNAS && map[i][j + 1] != 'X' && flags[i][j + 1] == 0)
            queue = queueInsert(i, j + 1, queue);
        if (j - 1 >= 0 && map[i][j - 1] != 'X' && flags[i][j - 1] == 0)
            queue = queueInsert(i, j - 1, queue);
    }

    return count;
}

int main(void) {
    char map[LINHAS][COLUNAS];
    int flags[LINHAS][COLUNAS] = {0};
    int start[2];
    int resultado;
    PQueue filaTeste = NULL;

    // Lê o mapa
    readMap(map);

    // Encontra a posição inicial do robô
    findRobot(map, start);

    // Adiciona a posição inicial do robô à fila
    filaTeste = queueInsert(start[0], start[1], filaTeste);

    // Chama o BFS para explorar o mapa e contar células limpas
    resultado = BFS(map, flags, filaTeste);

    // Imprime o número de células limpas
    printf("%i", resultado);

    return 0;
}
