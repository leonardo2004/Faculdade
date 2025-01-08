#include <stdio.h>
#include <stdlib.h>
int remove_dup(float v[], int n) {
    int i,j,l, tam = n;

    for (i = 0; i<tam; i++) {
        for (j = i+1; j<tam; j++) {
            if (v[i] == v[j]) {
                for (l = j; l<tam-1; l++) {
                    v[l] = v[l+1];
                }
                tam--;
            }
        }
    }
    n = tam;
    return n;
}

void ordem(float v[], int n) {
    int i, j, tam = n, posm;
    float menor;
    float *vaux = (float*) malloc (n*sizeof(float));
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

int merge (float r[], float s[], float v[], int n, int m) {
    int i, size=n+m;
    for (i=0; i<n; i++) {
        v[i] = r[i];
    }
    for (i=0; i<m; i++) {
        v[i+n] = s[i];
    }
    ordem(v,size);
    size = remove_dup(v, size);

    return size;
}

int main() {
    float *r, *s, *v;
    int n,m,i,sizev;
    scanf("%i %i",&n, &m);
    r = (float*) malloc (sizeof(float)*n);
    s = (float*) malloc (sizeof(float)*m);
    v = (float*) malloc (sizeof(float)* (n*m));

    for (i=0; i<n; i++) {
        scanf("%f", &r[i]);
    }
    for (i=0; i<m; i++) {
        scanf("%f", &s[i]);
    }
    sizev = merge(r,s,v,n,m);
    printf("%i",sizev);
    for (i=0; i<sizev; i++) {
        printf(" %f ", v[i]);
    }

    free(r);
    free(s);
    free(v);
    return 0;
}