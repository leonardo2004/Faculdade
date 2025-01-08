#include <stdio.h>
#include <stdlib.h>

void insert(float v[], int n, float valor, int pos) {
    int i;
    v = (float*) realloc(v, sizeof(float)*(n+1));
    for(i= n+1; i>pos; i--) {
        v[i] = v[i-1];
    }
    v[pos] = valor;
    return;
}

int main() {
    int tam=5,i, pos = 2;
    float valor = 2.4;
    float *v = (float*)malloc(sizeof(float)*tam);

    for (i=0; i<tam; i++) {
        scanf("%f", &v[i]);
    }
    insert(v, tam, valor, pos);
    for (i=0; i<tam+1; i++) {
        printf("%.1f ", v[i]);
    }
    free(v);
    return 0;
}