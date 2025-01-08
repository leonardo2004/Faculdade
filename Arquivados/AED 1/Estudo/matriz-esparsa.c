#include <stdio.h>
#include <stdlib.h>


typedef struct matriz {
    int coluna;
    int valor;
    struct mariz *prox;
} TMat;
typedef TMat *PMat;
typedef PMat *LMat;

LMat inicializa (int linhas){//Inicializa a matriz esparsa
    int i;
    LMat nova = (LMat) malloc (sizeof(PMat)*linhas);//Aloca um vetor dinamicamente pra guardar cada linha da matriz
    for (i=0; i<linhas; i++) {
        nova[i] = NULL;//Define o ponteiro inicial de cada linha como nulo
    }
    return nova; //Retorna a matriz inicializada
}

PMat criarno(int coluna, int valor, PMat prox) {//Cria cada nó novo (Cada novo elemento da matriz esparsa)
    PMat novo = (PMat) malloc (sizeof(TMat));//Aloca um novo nó na memória
    novo->prox = prox;//Define o ponteiro para próximo de acordo com a chamada da função
    novo->coluna = coluna;//Define a coluna
    novo->valor = valor;//Define o valor
    return novo;//Retorna o novo nó
}

LMat insere(LMat matriz, int linha, int coluna, int valor) {//Função pra inserir um elemento na matriz
    PMat p, ant;//Define duas varíaveis de tipo nó pra percorrer a linha
    if (!valor) return matriz;//Se o elemento for zero, não adiciona
    for (p=matriz[linha], ant = NULL; p!=NULL && p->coluna<coluna; ant = p, p=p->prox);//Percorre a linha, iniciando do elemento
    //mais a esquerda, assim que ele acha um valor maior que a coluna de p, ele sai do for
    //Casos especiais: Linha vazia: ant == NULL ; Coluna ja existe: p->valor = valor ; 
    //Coluna não existe: ant->prox = criarno(coluna, valor, p(vai inserir antes de p))
    if (p!=NULL&&p->coluna==coluna) p->valor = valor;//Coluna já existe, atualiza o valor da coluna
    if (ant == NULL) {
        matriz[linha] = criarno(coluna, valor, p);//Coluna não existe e a linhas está vazia, cria uma coluna nova e atualiza o 
        //valor do primeiro elemento da linha da matriz
     }//COLUNA NAO EXISTE E PRIMEIRO LUGAR
    else ant->prox = criarno(coluna, valor, p);//Coluna não existe e a linha não está vazia, cria uma coluna nova
    return matriz;
}

LMat removematriz(LMat matriz, int linha, int coluna, int *valor) {//Remove um elemento da matriz e retorna o valor do elemento
//removido
    PMat p, ant;//Variáveis auxiliares p/ percorrer a matriz
    if (matriz == NULL) return matriz;//Em caso da matriz for nula (não ter sido inicializa) retorna a própria matriz
    for (p=matriz[linha], ant=NULL; p!=NULL && p->coluna<coluna; ant=p, p=p->prox);//Percorre a linha da matriz a procura da coluna
    //a ser removida
    //3 casos de remoção:
    //  1º Elemento não está na linha
    //  2º Primeiro elemento da linha
    //  3º Elemento no meio da linha
    if (p==NULL || p->coluna != coluna) return matriz; //1º Caso: Se a coluna não estiver na linha ou se a coluna em p for diferente da
    //coluna procurada, retorna a matriz da mesma maneira que a encontrou
    if (ant==NULL) matriz[linha] = p->prox; //2º Caso: Se o valor anterior for nulo, ou seja, se a coluna procurada for a primeira,
    //atualiza o ponteiro em matriz pra poder retira-lo da linha
    else ant->prox = p->prox;//3º Caso: Elemento no meio da linha, atualiza o campo "prox" do elemento anterior para apontar para o
    //próximo elemento
    *valor = p->valor;//Modifica o valor pra demonstrar o valor do elemento retirado
    free(p);//Libera o nó removido
    return matriz;

}

LMat libera(LMat matriz, int linhas) {//Função para liberar a matriz
    PMat p;
    int i;
    for (i=0;i<linhas;i++) {//Percorre cada uma das linhas
        for (p=matriz[i]; matriz[i]!=NULL; p=matriz[i], matriz[i]=matriz[i]->prox) {//Percorre cada uma das colunas da respectaiva linha
        //atualizando o valor de matriz[i] (em que i é a linha analisada) de forma a liberar o elemeneto analisado e diminuir o tamanho 
        //da matriz
            free(p);//libera o elemento analisado
        }
    }
    free(matriz);//libera a matriz por completo
    return NULL;//retorna null, atualizando o valor da matriz
}

int busca(LMat matriz, int coluna, int linha) {//Função que busca o valor em uma posição especifica na matriz e retorna o valor do
//elemento
    PMat p;//Variavel auxiliar
    if (matriz == NULL || matriz[linha] == NULL) return 0;//Se a matriz não tiver sido inicializada ou se a linha estiver vazia
    //retorna zero (definição de matriz esparsa)
    for (p=matriz[linha]; p!=NULL && p->coluna<coluna; p=p->prox);//Percorre a linha enquando p->coluna<coluna definida ou até NULL
    //(caso não estiver) 
    if (p!= NULL && p->coluna==coluna) return p->valor;//Se encontrou a coluna, retorna o valor presente na coluna
    else return 0;//Caso contrário retorna zero (definição de matriz esparsa)
}

void imprimesemzero (LMat matriz, int numlinhas) {//Imprime uma matriz esparsa sem os zeros
    PMat p;//Variavel auxiliar
    int i;//Contador
    for (i=0; i<numlinhas; i++) {//Enquanto não estourar o número de linhas
        for (p=matriz[i]; p!=NULL;p=p->prox) {//Percorre a coluna
            printf("%i ", p->valor);//Imprime o valor na posição
        }
        printf("\n");//Pula uma linha no console quando trocar de linha da matriz
    }
}

void imprime (LMat matriz, int numlinhas, int numcolunas) {//Imprime uma lista esparsa com os zeros
    PMat p;//Var auxiliar
    int i, j;//Contadores
    for (i=0; i<numlinhas;i++) {//Conta até o número de linhas
        for (j=0, p=matriz[i]; j<numcolunas;j++) {//Conta até o número de colunas
            if (p!=NULL && p->coluna == j) {//Se tiver um elemento naquela posição, imprime o valor do elemento
                printf("%i ",p->valor);//Iprime o elemento
                p = p->prox;//Joga o elemento para o próximo
            }
            else printf("0 ");//Se não tiver um elemento naquela posição, não imprime o valor do elemento
        }
        printf("\n");//Pula uma linha no console em cada linha que ele passa
    }
}

LMat transposta (LMat matriz, int linhas, int colunas){//Retorna uma matriz transposta à matriz de entrada
    int i,j;//Contadores
    PMat p;//Var auxiliar
    LMat transposta = inicializa(colunas);//Inicializa a matriz transposta (atenção que aqui o número
    //de colunas da matriz de entrada é o parâmetro de inicialização da matriz transposta)
    for (i=0; i<colunas; i++) {//Vai de zero até o número de colunas da matriz de entrada (por conveniên-
    //cia vou chamar ela só de matriz)
        for (j=0; j<linhas; j++) {//Conta de zero até o número de linhas da matriz
            for (p=matriz[j]; p!=NULL && p->coluna<=colunas; p=p->prox) {//Percorre cada linha da matriz
            //até achar a coluna com valor exatamente igual ao contador de colunas (o primeiro)
                if (p->coluna == i) transposta = insere(transposta, i, j, p->valor);
                //Se houver um valor lá, a transposta recebe o valor na posição correspondente
            }
        }
    }
    return transposta;//Retorna a transposta
}


//A FAZER: VER SIMETRIA, VER DIAGONIAL, VER TRIANGULAR INFERIOR, MAIOR VALOR MÉDIO LINHA E COLUNA
//DEBUGGAR LIBERAR
 
int main(void) {
    LMat matriz;
    LMat transp;
    int linhas = 2, colunas = 3;
    int output;
    matriz = inicializa(linhas);
    matriz = inicializa(colunas);
    matriz = insere(matriz, 0, 0, 1);
    matriz = insere(matriz, 0, 1, 2);
    matriz = insere(matriz, 0, 2, 3);
    matriz = insere(matriz, 1, 0, 4);
    matriz = insere(matriz, 1, 1, 5);
    matriz = insere(matriz, 1, 2, 6);
    matriz = removematriz(matriz, 0, 2, &output);
    imprime(matriz, linhas, colunas);
    transp = transposta(matriz, linhas, colunas);
    imprime(transp, colunas, linhas);
    printf("%d\n",output);
    imprimesemzero(matriz, linhas);
    matriz = libera(matriz, linhas);
    transp = libera(transp, colunas);

    
}