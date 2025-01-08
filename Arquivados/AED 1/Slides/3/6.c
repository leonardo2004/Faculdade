#include <stdio.h>
#include <string.h>

typedef struct {
    char unome[15];
    char pnome[15];
    float pg;
} Aluno;

typedef struct {
    char unome[15];
    char pnome[15];
    float salario;
} Funcionario;

int main(void) {
    Aluno alunos[5];
    Funcionario funcionarios[5];
    int i;

    strcpy(alunos[0].pnome, "a");
    strcpy(alunos[0].unome, "a");
    alunos[0].pg = 2.0;
    strcpy(alunos[1].pnome, "b");
    strcpy(alunos[1].unome, "b");
    alunos[1].pg = 2.0;
    strcpy(alunos[2].pnome, "c");
    strcpy(alunos[2].unome, "c");
    alunos[2].pg = 2.0;
    strcpy(alunos[3].pnome, "d");
    strcpy(alunos[3].unome, "d");
    alunos[3].pg = 4.0;
    strcpy(alunos[4].pnome, "e");
    strcpy(alunos[4].unome, "e");
    alunos[4].pg = 2.0;

    funcionarios[3].salario = 1000.0;
    printf("%.1f\n", funcionarios[3].salario);
    for (i = 0; i<5; i++) {
        if(alunos[i].pg > 3.0) funcionarios[i].salario += funcionarios[i].salario/10;
    }
    printf("%.1f", funcionarios[3].salario);
    return 0;
}