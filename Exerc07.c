#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define PI 3.1415

// Function to calc fatorial of n
int fatorial(int n) {
  int fat, i;
  fat = 1;
  for (i = 1; i < n + 1; i++) {
    fat = fat * i;
  }
  return fat;
}

// Function to calc fatorial of n
double convert_to_radian(double degree) { return degree * (PI / 180); }

// Function to calc fatorial of n
double calcSin(double x) {
  double sin, termo;
  int i, c = 0;
  sin = 0;
  for (i = 1; true; i += 2, c++) {
    termo = (pow(x, i) / ((double)fatorial(i)));
    sin += pow((-1.0), c) * termo;
    if (termo < pow(10, -12)) {
      break;
    }
  }
  return sin;
}

int main() {

  double angulo;

  printf("Digite o valor para o ƒngulo em graus: ");
  scanf("%lf", &angulo);

  double seno = calcSin(convert_to_radian(angulo));

  printf("\nO seno de %0.2fø ‚ %0.2f.", angulo, seno);

  return 0;
}
