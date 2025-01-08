#include <stdio.h>
#include <stdlib.h>

void ordem(int v[], int n) {
    int i, j, tam = n, menor, posm;
    int *vaux = (int*) malloc (n*sizeof(int));
    if (!vaux) exit(0);
    
    for (i=0; i<n; i++) {
        menor = v[i];
        posm = i;
        for (j=0; j<tam; j++) {
            if (v[j]<menor) {
                menor = v[j];
                posm = j;
            }
        }

        vaux[i] = menor;

        for (j=posm; j<n; j++) {
            v[j] = v[j+1];
        }
        tam--;
    }
    for (i=0; i<n ;i++) v[i] = vaux[i];
    
    free(vaux);
    return;
}

int main() {
    int v[] = {5,4,1,2,1};
    int n = 5, i;
    ordem(v, n);
    for (i=0;i<n;i++) printf("%i ", v[i]);
    return 0;

}