#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fatorial(int n)
{   
    int fat, i;
    fat = 1;
    for(i = 1; i < n + 1; i++){
        fat = fat * i;
    }
    return fat;
}
double calcSin(double x)
{
    double sin, ratio;
    int i;
    sin = 0;
    ratio = 0;
    printf("Ebaaa Carai");
    for(i = 1; ratio < pow(10, -12); i+=2){
        sin += ratio*pow(-1, i+1);
        printf("%f", ratio);
        ratio = pow(x, i)/fatorial(i);
    }
    printf("%f", sin);
    return sin;
}

int main()
{   
   double angulo;
   printf("Digite o valor para o ƒngulo em radianos: ");
   scanf("%f", &angulo);
   double seno = calcSin(angulo);
   printf("%f", seno);
   return 0;
}


