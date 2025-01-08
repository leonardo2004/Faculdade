//NOME: LEONARDO TOMASELA LEAL RA:170291

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int N, L, C, count1, Ssize, Cpl, linhas = 0, paginas = 0;
    
    scanf("%i %i %i", &N , &L, &C);
    
    char* S = (char*) malloc(C + 1); // Aumenta o tamanho para incluir o caractere nulo
    if (S == NULL) exit(0);
    
    for (count1 = 0; count1 < N; count1++) {
        scanf("%s", S);
        Ssize = strlen(S);
        if (Cpl + Ssize > C) { // Verifica se a próxima palavra excede o limite de caracteres por linha
            linhas++; // Incrementa o número de linhas
            if (linhas > L) { // Verifica se o número de linhas excede o limite de linhas por página
                linhas = 1; // Reinicia o contador de linhas
                paginas++; // Incrementa o número de páginas
            }
            Cpl = Ssize + 1; // Reinicia o contador de caracteres na linha atual
        } else {
            Cpl += Ssize + 1; // Adiciona o tamanho da palavra e o espaço entre palavras
        }
    }
    
    if (Cpl > 0) linhas++; // Adiciona uma linha para a última palavra, se houver

    if (linhas > L) paginas+=2; // Adiciona uma página para as linhas restantes, se houver. Se houver mais linhas do que cabe em uma pagina, ele adiciona duas.
    else if (linhas > 0) paginas++;
    
    printf("%i", paginas);
    free(S);
    return 0;
}