#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
    int S, N, *vet, search;         // Variáveis principais
    int i, j, output = 0;            // Contadores
 
    scanf("%i %i", &S, &N);            // Lê os valores de S e N
    vet = (int*) malloc(sizeof(int)*S);    // Aloca o vetor com 
                        // valores de S
    for (i=0; i<S; i++) {
        scanf("%i", &vet[i]);
    }
    
    for (i=0; i<S; i++) {
        search = N - vet[i];
        for (j=i+1; j<S; j++) {
            if (vet[j] == search) output++;
        }
    }
 
    printf("%i", output);
 
}