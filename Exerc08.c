#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int fib(int n){
  if (n < 3){
    return 1;
  } else {
    return fib(n-1)+fib(n-2);
  }
}

int main() {

  int i, num;

  printf("Digite o numero n: ");
  scanf("%d", &num);
  for(i = 1;i < num+1 ; i++ ){
    printf("Fib(%d)\t=\t%d.\n", i, fib(i));
  }
  return 0;
}
