#include <stdio.h>
int main() {
    float base, altura, areatotal;
    printf("Iremos calcular a area de um triangulo, para isso siga as instrucoes de entrada!\n");
    printf("\nDigite o valor da altura: ");
    scanf("%f", &altura);
    printf("\nDigite o valor da base: ");
    scanf("%f", &base);
    areatotal = base*altura/ 2;

    printf("O valor da area do triangulo eh : %.2f\n", areatotal);

    return 0;
}
