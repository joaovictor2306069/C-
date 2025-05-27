#include <stdio.h>
int main() {
    int number1 , number2;
    printf("Digite dois numeros inteiros: ");
    scanf("%d", &number1);
    printf("Digite o outro numero: " );
    scanf("%d", &number2);



    printf("Soma = %d\n", number1 + number2);
    printf("Dif = %d\n", number1 - number2);
    printf("Prod = %d\n",  number1 * number2);
    printf("Div = %d\n", number1 / number2);


    return 0;
}
