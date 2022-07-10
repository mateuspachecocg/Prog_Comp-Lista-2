#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define true      1
#define false     1

struct data{
    int dia;
    int mes;
    int ano;
};

// Lendo data no formato dd/mm/aaaa
struct data read_data()
{
    struct data dt;
    char ch, data_string[8];
    int contador = 0;
    while(contador < 9) {
        ch = getchar();
        if(ch != '\n' && ch != '/'){
            data_string[contador] = ch;
            contador++;
        }
    }
    dt.dia = (data_string[0] - '0')*10   + (data_string[1] - '0');
    dt.mes = (data_string[2] - '0')*10   + (data_string[3] - '0');
    dt.ano = (data_string[4] - '0')*1000 + (data_string[5] - '0')*100
            +(data_string[6] - '0')*10   + (data_string[7] - '0');
    return dt;
}

// Data mais recente
int mais_recente(struct data data_referencia, int tam_vetor, struct data *datas)
{
    int i, index_min;
    for(i = 0;i < tam_vetor; i++){
        
    }
}
int main(){

    int n, i;
    struct data dt_refer;

    // Lendo padroes
    printf("Digite a quantidade de data a serem lidas: ");
    scanf(" %d", &n);
    printf("Digite data na forma dd/mm/aaaa: ");
    dt_refer = read_data();
    
    // Lendo datas
    struct data dts[n];
    for(i = 0;i < n; i++){
        printf("Digite data na forma dd/mm/aaaa: ");
        dts[i] = read_data();
    }


    return 0;
}