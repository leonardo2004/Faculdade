#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    int turma;
    int p1;
    int p2;
    int p3;
    int p4;
} Aluno;

void procura();
void exclui();

int main(void) {

    Aluno alunos[15];
    char nome[30] = "Leonardo Tomasela Leal";

    strcpy(alunos[0].nome, "Leonardo Tomasela Leal");

    alunos[0].turma = 1;
    alunos[0].p1 = 10;
    alunos[0].p2 = 10;
    alunos[0].p3 = 10;
    alunos[0].p4 = 10;

    procura(alunos, nome);
    exclui(alunos, nome);
    printf("%s",alunos[0].nome);
    procura(alunos, nome);
    return 0;

}

void procura(Aluno alunos[], char nome[]) {
    int i;
    for (i = 0; i<15; i++) {
        if (strcmp(nome, alunos[i].nome) == 0) {
            printf("%s\n", alunos[i].nome);
            printf("%i\n", alunos[i].turma);
            printf("%i\n", alunos[i].p1);
            printf("%i\n", alunos[i].p2);
            printf("%i\n", alunos[i].p3);
            printf("%i\n", alunos[i].p4);
            return;
        }
    }
    printf("Aluno não encontrado.");
    return;
}

void exclui(Aluno alunos[], char nome[]) {
int i;
    for (i = 0; i<15; i++) {
        if (strcmp(nome, alunos[i].nome) == 0) {
            strcpy(alunos[i].nome, "");
            alunos[i].turma = alunos[i].p1 = alunos[i].p2 = alunos[i].p3 = alunos[i].p4 = 0;
            return;
        }
    }
    printf("Aluno não encontrado.");
    return;
}
