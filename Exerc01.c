#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void matriz_to_string(int linhas, int colunas, int **matriz){
    int l, k;

    for(l = 0; l < linhas;l++){
        for(k = 0; k < colunas; k++){
            printf("\t %d \t", matriz[l][k]);
        }
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

    // Criando a matrz
    //int matriz[i][j];
    int matrix[3][2] = {{3, 5}, {6, 9}, {2, 12}};
    // Mostrando a matriz
    matriz_to_string(3, 2, matrix);
    
}