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
    while(contador < 8) {
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

// Convertendo a data para dias 
int convert_to_days(struct data dt)
{
    return dt.ano*365 + dt.mes*30 + dt.dia;
}
// Data mais recente
int mais_recente(struct data dt_refer, int tam_vetor, struct data *datas)
{
    int i, index_min, menor_dif, data_dias;
    int dias_refer = convert_to_days(dt_refer);
    // Datas
    menor_dif = convert_to_days(datas[0]) - dias_refer;
    index_min = 0;
    
    for(i = 1;i < tam_vetor; i++){
        if(menor_dif > (convert_to_days(datas[i]) - dias_refer)){
            menor_dif = convert_to_days(datas[i]) - dias_refer;
            index_min = 0;
        }
    }
    return index_min;
}
int main(){

    int n, i;
    struct data dt_refer;

    // Lendo padroes
    printf("Digite data na forma dd/mm/aaaa: ");
    dt_refer = read_data();
    printf("Digite a quantidade de data a serem lidas: ");
    scanf(" %d", &n);
    
    
    // Lendo datas
    struct data dts[n];
    for(i = 0;i < n; i++){
        printf("\nDigite data na forma dd/mm/aaaa: ");
        dts[i] = read_data();
    }
    
    // Data mais proxima da referenica
    int index = mais_recente(dt_refer, n, dts);
    printf("A data mais recente ‚ %d/%d/%d.", dts[index].dia, dts[index].mes, dts[index].ano);

    return 0;
}