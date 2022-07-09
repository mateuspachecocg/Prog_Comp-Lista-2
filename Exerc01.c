#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void matriz_to_string(int linhas, int colunas, int *matriz)
{
    int l;

    for(l = 0; l < linhas*colunas;l++){
        printf("\t %d \t", *(matriz+l));
        if (l > 0 && (l+1)%colunas == 0)
           printf("\n");
    }
}

void sum_elements(int linhas, int colunas, int *matriz)
{
    int l;
    int total = 0;
    for(l = 0; l < linhas*colunas;l++){
        total += *(matriz+l);
    }
    printf("\n A soma dos elementos da matriz ‚ %d.\n",total);
}

void the_greatest(int linhas, int colunas, int *matriz)
{
    int l;
    int max = *matriz;
    for(l = 1; l < linhas*colunas;l++){
        if(max < *(matriz+l)){
            max = *(matriz+l);
        }
    }
    printf("\n O maior elemento da matriz ‚ %d.\n", max);
}

int the_smallest(int linhas, int colunas, int *matriz)
{
    int l;
    int min = *matriz;
    for(l = 1; l < linhas*colunas;l++){
        if(min < *(matriz+l)){
            min = *(matriz+l);
        }
    }
    printf("\n O menor elemento da matriz ‚ %d.\n", min);
}

void the_greatest_smallest(int linhas, int colunas, int *matriz)
{
    the_greatest(linhas, colunas, matriz);
    the_smallest(linhas, colunas, matriz);
}

void greater_than_50(int linhas, int colunas, int *matriz)
{
    int l, contador = 0;
    int total = 0;
    for(l = 0; l < linhas*colunas;l++){
        if(*(matriz+l) > 50){
            if (contador < 1){
                printf("\nElementos maiores que 50: [");
            }
            printf(" %d,", *(matriz+l));
            contador++;
        }
    }
    if (contador > 0){
        printf("]\n");
    } else {
        printf("\n NÆo h  elementos maiores que 50.");
    }
}

void even_elemnts(int linhas, int colunas, int *matriz)
{
    int l, contador = 0;
    int total = 0;

    for(l = 0; l < linhas*colunas;l++){
        if(*(matriz+l) % 2 == 0){
            if (contador < 1){
                printf("\nElementos pares: [");
            }
            printf(" %d,", *(matriz+l));
            contador++;
        }
    }
    if (contador == 0){
        printf("\nNÆo h  elementos pares.");
    } else {
        printf(" ]");
    }
}

void count_even_elements(int linhas, int colunas, int *matriz)
{
    int l, contador = 0;
    for(l = 0; l < linhas*colunas;l++){
        if(*(matriz+l) % 2 == 0){
            contador++;
        }
    }
    printf("\nA quantidade de elementos pares ‚: %d", contador);
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
    
    // a. Mostrar cada elemento da matriz;
    matriz_to_string(i, j, *mtz);
    
    // b. Calcular e mostrar a soma dos elementos da matriz;
    sum_elements(i, j, *mtz);
    
    // c. Calcular e mostrar o maior elemento da matriz; 
    the_greatest(i, j, *mtz);
    
    // d. Calcular e mostrar o menor elemento da matriz;
    the_smallest(i, j, *mtz);

    // e. Calcular e mostrar o maior e o menor elemento da matriz;
    the_greatest_smallest(i, j, *mtz);
    
    // f. Exibir cada elemento cujo valor seja maior que 50;
    greater_than_50(i, j, *mtz);

    // g. Exibir cada elemento cujo valor seja par;
    even_elemnts(i, j, *mtz);
    
    // g. Exibir cada elemento cujo valor seja par;
    even_elemnts(i, j, *mtz);

    // h. Calcular e exibir a quantidade de elementos pares da matriz.
    count_even_elements(i, j, *mtz);
}