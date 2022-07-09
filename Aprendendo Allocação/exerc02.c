#include <stdio.h>
#include <stdlib.h>

void carregarVetor(int tam, int *vptr){
    int i;
    for (i = 0; i<tam; i++){
        printf("Digite o %dø elemento: ", (i+1));
        scanf("%d", vptr);
        vptr++;
    }
}

int main(){
    
    int n, *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = (int *) calloc(n, sizeof(int));
    carregarVetor(n, vetor);
    
    int c;
    printf("Vetor: [");
    for(c = 0; c < (n-1); c++){
        printf(" %d,", *(vetor+c));
    }
    printf(" %d ]", *(vetor+c));
    free(vetor);
    return 0;
}