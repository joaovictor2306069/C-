#include <stdio.h>
int somar( int num1, int num2){
int resultado = num1 + num2;
return resultado;
}

int main() {
    int num1, num2;
    printf("Digite um numero: ");
    scanf("%d", &num1);
    printf("Digite outro numero: ");
    scanf("%d", &num2);
    int resultado = somar(num1, num2);
    printf("Resultado da soma entre eles : %d", resultado);
    return 0;


}

