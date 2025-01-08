//None: Leonardo Tomasela Leal RA: 170291
//

//usar vetor auxilar pra ver se vai doar ou não, não retirar do vetor principal
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double B; //Beleza
    double F; //Fortuna
    long D; //Doação mudar para long int 
} convidado;
typedef convidado* pconvidado;

pconvidado inicia(int n){
    pconvidado vetor = (pconvidado) malloc (n*sizeof(convidado));
    if (!vetor) exit (0);
    return vetor;
}

int main(void) {
    //Definindo variáveis
    int N, i, j;
    double Dmax = 0, DS = 0;
    pconvidado convidados;

    scanf("%d", &N); // Escaneia quantos são os convidados
    convidados = inicia(N); // Inicializa o vetor de structs dos convidados
    

        
    for (i = 0; i<N; i++) {
        scanf("%lf %lf %ld", &convidados[i].B, &convidados[i].F, &convidados[i].D);
    }



    for (i = 0; i<N; i++) {
        DS = convidados[i].D;
        for (j = 0; j<N; j++) { 
            if (i==j || ((convidados[i].B > convidados[j].B && convidados[j].F >= convidados[i].F) || 
                (convidados[i].F > convidados[j].F && convidados[j].B >= convidados[i].B )) || 
                ((convidados[i].B >= convidados[j].B && convidados[j].F > convidados[i].F) || 
                (convidados[i].F >= convidados[j].F && convidados[j].B > convidados[i].B ))) {}
            else DS += convidados[j].D;
        }
        if (DS > Dmax) Dmax = DS;
    }



    printf("%.0lf", Dmax);
    free(convidados);
    return 0;
}