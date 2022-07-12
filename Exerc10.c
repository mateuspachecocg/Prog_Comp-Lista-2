#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(double A, double B, double C, double *X1, double *X2)
{
    double delta, x1,x2;
    delta = (pow(B, 2.0) - 4 * A * C);
    if (delta > 0) 
    {
        *X1 = (-B + sqrt(delta))/(A + A);
        *X2 = (-B - sqrt(delta))/(A + A);
        return 2;
    } 
    else if (delta == 0)
    {
        *X1 = (-B) / (2 * A);
        return 1;
    } 
    else 
    {
        return 0;
    }
}

void main(){
    double a, b, c, raiz_1, raiz_2;

    // Lendo os parametros da equacao.
    printf("\nDigite o coeficente a: ");
    scanf(" %lf", &a);
    printf("\nDigite o coeficente b: ");
    scanf(" %lf", &b);
    printf("\nDigite o coeficente c: ");
    scanf(" %lf", &c);

    switch (raizes(a, b, c, &raiz_1, &raiz_2)) {
        case 0:
            printf("Case 0");
            printf("\nEsta equaá∆o n∆o apresenta ra°zes reais.");
            break;
        case 1:
            printf("Case 1");
            printf("\nEsta equacao apresenta uma raiz real: \nRAIZ: %.2f.", raiz_1);
            break;
        case 2:
            printf("Case 2");
            printf("\nEsta equacao apresenta duas raizes reais: ");
            printf("\nRAIZ 1: %.2f.", raiz_1);
            printf("\nRAIZ 2: %.2f.", raiz_2);
            break;
        }
}