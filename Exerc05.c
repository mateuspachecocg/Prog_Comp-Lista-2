#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 1

struct data {
  int dia;
  int mes;
  int ano;
};

struct contato {
  char nome[15];
  char telefone[11];
  struct data aniversario;
};

// Lendo data no formato dd/mm/aaaa
struct data read_data(int tipo) {
  int contador = 0, CONTROL;
  struct data dt;
  switch (tipo) {
  case 1:
    CONTROL = 4;
    break;
  case 2:
    CONTROL = 8;
    break;
  default:
    exit(1);
  }
  char ch, data_string[CONTROL];

  while (contador < CONTROL) {
    ch = getchar();
    if (ch != '\n' && ch != '/') {
      data_string[contador] = ch;
      contador++;
    }
  }
  dt.dia = (data_string[0] - '0') * 10 + (data_string[1] - '0');
  dt.mes = (data_string[2] - '0') * 10 + (data_string[3] - '0');
  if (tipo == 2)
    dt.ano = (data_string[4] - '0') * 1000 + (data_string[5] - '0') * 100 +
             (data_string[6] - '0') * 10 + (data_string[7] - '0');
  return dt;
}

// Convertendo a data para dias
int convert_to_days(struct data dt) {
  return dt.ano * 365 + dt.mes * 30 + dt.dia;
}

// Verificando se a pessoa aniversaria na data de referencia
int is_birthday(struct data niver, struct data dt) {
  return (niver.mes == dt.mes && niver.dia == dt.dia);
}

int main() {

  int n, i, count;

  // Lendo padroes
  printf("Quantidade de contatos na agenda: ");
  scanf(" %d", &n);

  // Data de aniversario
  struct data dt_referencia;
  printf("\nDigite a data de referencia dd/mm: ");
  dt_referencia = read_data(1);

  // Lendo datas
  struct contato cts[n];
  for (i = 0; i < n; i++) {
    printf("\nDigite o nome do contato: ");
    scanf(" %[^\n]s", cts[i].nome);
    printf("\nDigite telefone do contato: ");
    scanf(" %[^\n]s", cts[i].telefone);
    printf("\nDigite a data de nascimento ");
    cts[i].aniversario = read_data(2);
  }

  // Verificando as datas dos contatos
  printf("\nANIVERSARIANTES: ");
  count = 0;
  for (i = 0; i < n; i++) {
    if (is_birthday(dt_referencia, cts[i].aniversario)) {
      count++;
      printf("\nNOME:\t%s\tTELEFONE:\t%s\t\n", cts[i].nome, cts[i].telefone);
    }
  }
  if (count == 0) {
    printf("\nNÆo h  aniversariantes nesta data.");
  }

  return 0;
}