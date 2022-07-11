#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define true  1
#define false 0
#define PI    3.1415

void matriz_to_string(int linhas, int colunas, int matriz[][colunas])
{
    int l, k;

    for(l = 0; l < linhas;l++){
        for(k = 0; k < colunas; k++){
          printf("\t%d\t ", matriz[l][k]);
        }
        printf("\n");
    }
}


int main() {
  
  int i, j;

    // Dimensoes da Matriz
    printf("Quantidade de linhas da matriz: ");
    scanf("%d", &i);
    printf("Quantidade de colunas da matriz: ");
    scanf("%d", &j);

    // Criando a matriz
    int mtz[i][j];
    int l, k;
    for (l = 0; l  < i; l++){
        for (k = 0; k  < j; k++){
            printf("Digite linha %d coluna %d: ", (l+1), (k+1));
            scanf(" %d", &mtz[l][k]); 
        }
    }
    
    // a. Mostrar cada elemento da matriz;
    matriz_to_string(i, j, mtz);
  
  return 0;
}
