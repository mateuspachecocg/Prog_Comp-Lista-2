#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define true 1
#define false 0

/*** Elabore um algoritmo C para efetuar a correá∆o das provas dos alunos da disciplina 
   * de Programaá∆o Computacional do curso de Engenharia da Computaá∆o da UFC. 
   * A prova Ç composta por 10 quest‰es, onde cada uma vale 1,0 ponto. Primeiramente, 
   * o gabarito da prova deve ser lido. Em seguida, devem ser lidas as respostas de cada 
   * aluno. Assuma que a turma possua N alunos, tal que 1 ? ?? ? 100, calcule e imprima 
   * o n£mero e a nota de cada aluno. (Considere que o gabarito Ç formado por apenas 
   * caracteres a, b, c ou d).
   */

struct aluno {
    char nome[15];
    char respostas[10];
};

char read_answer(int numero_questao)
{
    printf("\nGABARITO QUEST«O %d: ", numero_questao);
        while(true){
            char c = getchar();
            if ((c == 'a' || c == 'b' || c == 'c' || c == 'd') && c != '\n'){
                return  c ;
                break;
            } else if (c != '\n') { // Para n∆o considerar a quebra de linha
                printf("Resposta inv†lida.\n Digite outro: ");
            }
        }
}

int calc_nota(char *gabarito, char *respostas)
{
    int i, nota = 0;
    for(i = 0; i < 10; i++){
        if(*(gabarito+i) == *(respostas+i)){
            nota++;
        }
    }
    return nota;
}

int main()
{
    char espelho[10];
    int nota, n_alunos, i, k;

    // Lendo o gabarito da prova
    printf("FORNEÄA O GABARITO DA PROVA\n");
    for(i = 0;i < 10; i++){
        espelho[i] = read_answer(i+1);
    }

    // Lendo as notas de cada alunos:
    printf("Quantos alunos a turma tem: ");
    scanf(" %d", &n_alunos);
    
    struct aluno alunos[n_alunos];
    
    for(i = 0;i < n_alunos; i++){
        printf("\nNOME DO ALUNO: %d: ", (i+1));
        scanf(" %[^\n]s", alunos[i].nome);
        
        for(k = 0;k < 10; k++){
            alunos[i].respostas[k] = read_answer(k+1);
        }        
    }

    // Imprimindo a nota de cada aluno
    for(i = 0;i < n_alunos; i++){
        printf("\nA note de %s foi %d.", alunos[i].nome
                                        , calc_nota(espelho, alunos[i].respostas));
    }
}