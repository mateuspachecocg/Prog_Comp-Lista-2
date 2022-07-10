#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 1
#define NOTAS_MAX 4
/**** Crie um algoritmo para armazenar as quatro notas de uma turma de N alunos,
 * informado pelo usu rio. Como resultado, o algoritmo deve apresentar um
 * relat¢rio informando: a. A m‚dia de cada aluno; b. A prova em que o aluno
 * teve MENOR nota; c. Quais alunos foram aprovados por m‚dia. Assuma que a
 * m‚dia seja 7,0. OBS: Utilize uma fun‡Æo para cada item.
 */
struct aluno {
  char nome[15];
  double notas[NOTAS_MAX];
};

double media(double *notas) {
  int k;
  double sum = 0;
  for (k = 0; k < NOTAS_MAX; k++) {
    sum += notas[k];
  }
  return sum / NOTAS_MAX;
}

int return_index_min(double *notas) // Retorna o ¡ndice da menor nota
{
  int k, index_min = -1;
  double min = 11;
  for (k = 0; k < NOTAS_MAX; k++) {
    if (notas[k] < min) {
      min = notas[k];
      index_min = k;
    }
  }
  return index_min;
}

void show_medias(int tam, struct aluno *vetor_alunos) {
  int i;
  for (i = 0; i < tam; i++) {
    printf("\nA m‚dia de %s", vetor_alunos[i].nome);
    printf(" ‚: %0.1f.", media(vetor_alunos[i].notas));
  }
}

void min_nota(int tam, struct aluno *vetor_alunos) {
  int i, index_menor_nota;
  double menor_nota, min = 11;
  for (i = 0; i < tam; i++) {
    printf("\nA menor nota de %s ", vetor_alunos[i].nome);
    printf("foi na prova %d.", (return_index_min(vetor_alunos[i].notas)) + 1);
  }
}

void show_approved(int tam, struct aluno *vetor_alunos) {
  int i;
  double media_aluno;
  for (i = 0; i < tam; i++) {
    media_aluno = media(vetor_alunos[i].notas);
    if (media_aluno >= 7.0) {
      printf("\nO aluno %s est  APROVADO.", vetor_alunos[i].nome);
    } else {
      printf("\nO aluno %s est  REROVADO.", vetor_alunos[i].nome);
    }
  }
}

int main() {

  int n_alunos, i, k;
  // Lendo as notas de cada alunos:
  printf("Quantos alunos a turma tem: ");
  scanf(" %d", &n_alunos);
  struct aluno alunos[n_alunos];

  for (i = 0; i < n_alunos; i++) {
    printf("\nDigite o nome do aluno: ");
    scanf(" %[^\n]s", alunos[i].nome);
    for (k = 0; k < NOTAS_MAX; k++) {
      printf("\nQual a nota %d: ", (k + 1));
      scanf(" %lf", &alunos[i].notas[k]);
    }
  }

  // a. A m‚dia de cada aluno;
  show_medias(n_alunos, alunos);

  // b. A prova em que o aluno teve MENOR nota;
  min_nota(n_alunos, alunos);

  // c. Quais alunos foram aprovados por m‚dia. Assuma que a m‚dia seja 7,0.
  show_approved(n_alunos, alunos);

  return 0;
}
