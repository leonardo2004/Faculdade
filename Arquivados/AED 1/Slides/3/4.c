#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[81];
    int mat;
    char end[121];
    char tel[21];
} Aluno;

Aluno* inicializa( int n) {
    Aluno *aluno = (Aluno*) malloc(n*sizeof(Aluno));
    if (!aluno) return NULL;
    else return aluno;
}

void armazena(int n, Aluno* lista) {
    scanf("%s", lista[n].nome);
    scanf("%i", &lista[n].mat);
    scanf("%s", lista[n].end);
    scanf("%s", lista[n].tel);
}

void mostra(int n, Aluno* lista) {
  
    printf("%s\n", lista[n].nome);
    printf("%i\n", lista[n].mat);
    printf("%s\n", lista[n].end);
    printf("%s\n", lista[n].tel);

}

int main(void) {
    int n, i;
    Aluno* lista;

    printf("Quantos alunos deseja inserir?");
    scanf("%i", &n) ;
    
    lista =  inicializa(n);
    if (!lista) {
            printf("Falha ao alocar memoria.\n");
            return 1;
        }
    armazena(n, lista);
    mostra(n, lista);
    free(lista);

    return 0;
}
/*Your code has several issues that need to be addressed to work correctly. Here's a breakdown of the problems and how to fix them:

Memory Allocation in inicializa Function: The inicializa function is supposed to allocate memory for an array of Aluno structures, but it doesn't return the allocated memory to the caller. Instead, it returns a boolean value indicating success or failure. This means the lista pointer in main remains uninitialized, leading to undefined behavior when you try to use it.

Incorrect Use of scanf in armazena Function: The scanf function is used incorrectly. When reading strings with %s, you should not use the address-of operator (&). Also, lista is an array of pointers, not a pointer to a pointer, so you need to pass it correctly to the armazena function.

Incorrect Use of printf in mostra Function: Similar to scanf, the printf function is used incorrectly. You need to use format specifiers (%s for strings, %d for integers) to print the values.

Memory Leak in main Function: You're freeing lista in a loop, but lista is not an array of pointers; it's a single pointer. This will likely cause a crash or undefined behavior*/