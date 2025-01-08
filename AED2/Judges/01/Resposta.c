#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int input, *vet, i, j, maior, *vet2, soma, maiorsoma, k, dist;
  scanf("%i", &input);
  vet = malloc(sizeof(int) * input);
  for (j = 0; j < input; j++) {
    scanf("%i", &vet[j]);
  }
 
  maior = vet[0];
 
  for (j = 0; j < input; j++) {
    if (maior < vet[j]) {
      maior = vet[j];
    }
  }
 
  vet2 = calloc(maior, sizeof(int));
  for (j = 0; j < input; j++) {
    vet2[vet[j] - 1]++;
  }
  for (j = 0; j < maior; j++) {
    soma = 0;
    for (k = 0; k < maior; k++) {
      if (vet2[k] > 0 && j != k) {
        vet2[k]--;
        if (k > j) {
          dist = k - j;
        } else
          dist = j - k;
        soma += dist;
      }
    }
    if (j == 0)
      maiorsoma = soma;
    if (soma < maiorsoma) {
      maiorsoma = soma;
    }
    for (k = 0; k < input; k++) {
      vet2[vet[k] - 1]++;
    }
  }
  printf("%i\n", maiorsoma);
  free(vet);
  free(vet2);
  return 0;
}