#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void matriz_to_string(int linhas, int colunas, int *matriz){
    int l;

    for(l = 0; l < linhas*colunas;l++){
        printf("\t %d \t", *(matriz+l));
        if (l > 0 && (l+1)%colunas == 0)
           printf("\n");
    }
}

int main()
{
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
    
    // Mostrando a matriz
    matriz_to_string(i, j, *mtz);
    
}