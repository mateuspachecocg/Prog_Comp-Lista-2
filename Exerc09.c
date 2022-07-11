#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void matriz_to_string(int dim, int *matriz)
{
    int l;
    
    for(l = 0; l < dim*dim;l++){
        printf("\t %d \t", *(matriz+l));
        if (l > 0 && (l+1)%dim == 0)
           printf("\n");
    }
}

int *trocandoLinhas(int dim, int l1, int l2, int mtz[][dim]){
    int l, k, temp;
    l1 = l1-1;
    l2 = l2-1;
    for(l = 0; l < dim;l++){
      for(k = 0; k < dim; k++){
        temp = mtz[l1][k];
        mtz[l1][k] = mtz[l2][k];
        mtz[l2][k] = temp;
      }
    }
    return *mtz;
}

int main() {

  int i, l, k, j, m;

  // Dimensoes da Matriz
  printf("Digite a dimensÆo da matriz quadrada: ");
  scanf("%d", &m);

  // Criando a matriz
  int A[m][m];
  for (l = 0; l < m; l++) {
    for (k = 0; k < m; k++) {
      printf("Digite linha %d coluna %d: ", (l + 1), (k + 1));
      scanf(" %d", &A[l][k]);
    }
  }

  // Trocando os elementos
  printf("\n<<<<<<<<< Parƒmetros de troca >>>>>>>>>>");
  printf("\nDigite a primeira linha: ");
  scanf("%d", &i);
  printf("\nDigite a segunda linha: ");
  scanf("%d", &j);
  
  printf("\nMatriz Original\n");
  printf("\n\n");
  matriz_to_string(m, *A);
  **A = *trocandoLinhas(m, i, j, A);

  printf("\nMatriz Trocada");
  printf("\n\n");
  matriz_to_string(m, *A);

  return 0;
}
