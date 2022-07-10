#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int ordem_de_grandeza(int x)
{
  int i;
  // Vendo ordem de grandeza de b
  for (i = 0; true; i++) {
    if (x % ((int)pow(10, i)) == x) {
      return i;
    }
  }
}

int verifica_encaixe(int a, int b) {
  int i;
  // Vendo ordem de grandeza de b
  i = ordem_de_grandeza(b);
  if (a % ((int)pow(10, i)) == b){
      return true;
  } else {
      return false;
  }
}

int is_segment(int a, int b){
    int o_a, o_b, k;
    if (b > a){
        k = b;  b = a;  a = k;
    }

    o_a = ordem_de_grandeza(a);
    o_b = ordem_de_grandeza(b);
    
    for(k = 0; k < (o_a - o_b); k++){
        if (verifica_encaixe(a, b)) {
            return true;
        }
        a = (a - (a % 10))/10;
    }
    return false;
}
int main() {

    int num_A, num_B, i, count;

    printf("El valor de A: ");
    scanf(" %d", &num_A);

    printf("El valor de B: ");
    scanf(" %d", &num_B);

    if(verifica_encaixe(num_A, num_B)){
        printf("Os n£meros digitados encaixam... ");
    } else {
        printf("Os n£meros N«O digitados encaixam... ");
    }

    if(is_segment(num_A, num_B)){
        if (num_A > num_B){
            printf("\nB Ç segmento de A.");
        } else { 
            printf("\nA Ç segmento de B.");
        }
    } else {
        printf("\nUm n∆o Ç segmento do outro. ");
    }

    return 0;
}