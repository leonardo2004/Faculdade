//NOME: Leonardo Tomasela Leal RA: 170291
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    struct pilha* prox;
    char nucleo; //char referente ao nucleotídeo
    int sedobrou; //Inteiro que verifica se o elemento é resultado de uma dobra
} tpilha;
typedef tpilha* ppilha;

ppilha inicializa() {
    ppilha pilha = NULL;
    return pilha;
}

ppilha push(char nucleo, int sedobrou, ppilha pilha) {
    ppilha no = (ppilha) malloc (sizeof(tpilha)); 
    if (!no) exit(0); 
    if (pilha == NULL) 
        no->prox = NULL;
    else 
        no->prox = pilha;
    no->nucleo = nucleo;
    no->sedobrou = sedobrou;
    return no;
}

ppilha pop(char *nucleo, int* sedobrou, ppilha pilha) {
    ppilha p = pilha;
    if (pilha==NULL) return NULL;
    pilha = pilha->prox;
    *nucleo = p->nucleo;
    *sedobrou = p->sedobrou;
    free(p);
    return pilha;
}

ppilha libera(ppilha pilha) {
    ppilha p = pilha;
    while (pilha) {
        p = pilha;
        pilha = pilha->prox;
        free(p);
    }
    return NULL;
}

int conta(ppilha pilha) { //Função para contar quantos elementos tem na pilha
    ppilha p = pilha;
    int count = 0;
    while(p) {
        p = p->prox;
        count++;
    }
    return count;
}

int main() {
    char scan, nucaux1;
    int vezesdogo = 1, sedaux1;
    ppilha sg, aux1, aux2;
    sg = inicializa();
    aux1 = inicializa();
    aux2 = inicializa();


    //escaneia a seguência gênica e insere na pilha
    do {
        scanf("%c", &scan);
        if (scan == 'A' || scan == 'C' || scan == 'G' || scan == 'T' ) sg = push(scan, 0, sg);
    } while(scan != '\n' && scan != '\0');

    while(vezesdogo !=0) {
        vezesdogo = 0; //Zera as vezes que o dogo foi aplicado (que houve uma dobra)
        while(sg) {
            if (aux1 != NULL && sg->nucleo == aux1->nucleo && sg->sedobrou == 0 && aux1->sedobrou == 0) {
                //se se o nucleo do ultimo elemento de sg for igual ao nucleo do ultimo elemento de aux1
                //aux1 recebe um pop e o elemento é adicionado a aux2 porém agora sendo considerado que ja
                //foi dobrado antes (aplica o dogo)
                aux1 = pop(&nucaux1, &sedaux1, aux1); //remove o ultimo elemento do auxliar 1
                aux2 = push(nucaux1, 1, aux2); //insere o elemento removido no auxiliar 1 no auxiliar 2
                sg = pop(&nucaux1, &sedaux1, sg); //tira o elemento repetido da pilha principal
                vezesdogo++; //Aumenta 1 nas vezes que o dogo foi aplciado

            }
            else {
                while (aux2 != NULL) { //transfere todos do auxiliar 2 pro auxiliar 1
                    aux2 = pop(&nucaux1, &sedaux1, aux2); 
                    aux1 = push(nucaux1, sedaux1, aux1); 
                }
                sg = pop(&nucaux1, &sedaux1, sg); //Move um da pilha pricipal pra auxiliar 1
                aux1 = push(nucaux1, sedaux1, aux1);

            }

        }

        while (aux1) { //Transfere todos da pilha auxiliar 1 pra principal para 
            //recomeçar o loop, assim o programa só vai finalizar quando a iteração não fizer nenhuma modificação
            //na pilha principal (as modificações são contadas no inteiro vezesdogo)
            aux1 = pop(&nucaux1, &sedaux1, aux1); 
            sg = push(nucaux1, sedaux1, sg);
        }

    }

    printf("%i", (conta(sg))); //Conta e imprime quantos elementos tem na pilha principal

    libera(sg);
    libera(aux1);
    libera(aux2);
    return 0;
}
