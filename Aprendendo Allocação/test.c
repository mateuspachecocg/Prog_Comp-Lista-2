#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define true  1
#define false 0
#define PI    3.1415


int main() {
  
  int i;
  char c, gab[10];
  printf("enter the ansquers:\n");
  for(i = 0;i < 10; i++){
    printf("Question %d: ", i+1);
    while(1){
      c = getchar();
      if(c != '\n'){
        gab[i] = c;
        break;
      }
    }
  }
  
  return 0;
}
