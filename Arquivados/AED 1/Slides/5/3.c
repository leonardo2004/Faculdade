#include <stdio.h>
#include <stdlib.h>

int remove_dup(int v[], int *n) {
    int i,j,l, num = 0, tam = *n;

    for (i = 0; i<tam; i++) {
        for (j = i+1; j<tam; j++) {
            if (v[i] == v[j]) {
                for (l = j; l<tam-1; l++) {
                    v[l] = v[l+1];
                }
                tam--;
                num++;
            }
        }
    }
    *n = tam;
    return num;
}

int main() {
    int i, *vet, tam = 10, dup;
    vet = (int*) malloc(tam*sizeof(int));
    if (!tam) exit(0);

    for (i=0; i<tam;i++) {
        scanf("%i", &vet[i]);
    }
    dup = remove_dup(vet, &tam);
    for (i=0; i<tam;i++) {
        printf("%i ",vet[i]);
    }
    printf(" aa %i", dup);

    free(vet);
    return 0;
}