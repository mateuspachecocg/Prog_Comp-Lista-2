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

int *vetorSoma(int tam, int *vptr1, int *vptr2){
    int *v;
    int i;
    v = (int *) calloc(tam, sizeof(int));
    for (i = 0; i<tam; i++){
        *(v+i) = *(vptr1+i) + *(vptr2+i);
    }    
    return v;

}


int *vetorProdutos(int tam, int *vptr1, int *vptr2){
    int *v;
    int i;
    v = (int *) calloc(tam, sizeof(int));
    for (i = 0; i<tam; i++){
        *(v+i) = *(vptr1+i) * *(vptr2+i);
    }    
    return v;
}

void mostrarVetor(int n, int *vetor){
    printf("Vetor: [");
    int c;
    for(c = 0; c < (n-1); c++){
        printf(" %d,", *(vetor+c));
    }
    printf(" %d ]\n", *(vetor+c));
}

int main(){
    
    int n, *vetor1, *vetor2, *vetSum, *vetProd;

    printf("Digite o tamanho dos vetor: ");
    scanf("%d", &n);

    vetor1 = (int *) calloc(n, sizeof(int));
    vetor2 = (int *) calloc(n, sizeof(int));

    carregarVetor(n, vetor1);
    carregarVetor(n, vetor2);

    vetSum = vetorSoma(n, vetor1, vetor2);
    vetProd = vetorProdutos(n, vetor1, vetor2);
    
    // Mostrando
    mostrarVetor(n, vetor1);
    mostrarVetor(n, vetor2);
    mostrarVetor(n, vetSum);
    mostrarVetor(n, vetProd);

    // Liberando Memoria
    free(vetor1);
    free(vetor2);
    free(vetSum);
    free(vetProd);
    return 0;
}