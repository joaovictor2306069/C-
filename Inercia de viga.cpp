#include <stdio.h>
#include <math.h> // Inclui funções matemáticas como pow() para elevar ao quadrado

int main() {

    double altura, base, area, inercia; // escolhi o double por trabalhar com casas decimais e com mais precisao e tamanho.

    printf("Vamos calcular a inercia e area de uma viga com secao transversal retangular.\n");

    printf("Digite o valor da base em cm: ");
    scanf("%lf", &base);

    printf("Digite o valor da altura em cm: ");
    scanf("%lf", &altura);

    area = altura * base; // calculo da area da secao transversal referente ao retangulo
    inercia = base * pow(altura, 3) / 12.0; // calculo da inercia para a secao do retangulo

    printf("\nArea da viga: %.2f cm^2", area);
    printf("\nInercia da viga: %.2f cm^4\n", inercia);

    if (area >= 100) {
        printf("A area de %.2f cm^2 esta apta para suportar uma carga minima. (Area >=100)\n", area);
    } else {
        printf("A area de %.2f cm^2 nao esta apta para suportar uma carga minima.(Area <100)\n", area);
    }

    return 0;
}



