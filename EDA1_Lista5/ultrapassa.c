#include <stdio.h>

int soma, limite;
void ultrapassa(int *numeros) {

  if (*numeros == 0) {
    return;
  }

  if (soma + *numeros > limite) {
    soma = 0;
    ultrapassa(numeros + 1);
    printf("%d\n", *numeros);
  } else {
    soma = soma + *numeros;
    ultrapassa(numeros + 1);
  }
}

int main(void) {
  int v[1000];
  int lido = 0; 
  int i = 0;
  soma = 0; 
  while (scanf("%d", &lido) == 1 && lido != 0) {
    v[i] = lido;
    i++;
  }

  scanf("%d", &limite);

  ultrapassa(v);

  return 0;
}
