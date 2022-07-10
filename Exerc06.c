#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int verifica_encaixe(int a, int b) {
  int i;
  // Vendo ordem de grandeza de b
  for (i = 0; true; i++) {
    if (b % ((int)pow(10, i)) == b) {
      break;
    }
  }
  if (a % ((int)pow(10, i)) == b){
      return true;
  } else {
      return false;
  }
}

int main() {

    int num_A, num_B, i, count;

    printf("El valor de a: ");
    scanf(" %d", &num_A);

    printf("El valor de b: ");
    scanf(" %d", &num_B);

    if(verifica_encaixe(num_A, num_B)){
        printf("Os n£meros digitados encaixam... ");
    } else {
        printf("Os n£meros NÇO digitados encaixam... ");
    }

    return 0;
}