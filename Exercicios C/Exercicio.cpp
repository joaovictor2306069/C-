#include <cstdio>
int main() {
    int numeros[10];
    int i, indice, valorNovo;

    printf("Valor original do vetor\n");
    for (i = 0; i < 10; i++) {
        numeros[i] = i +1 ;
        printf("%d", numeros[i]);
    }
        printf("\nDigite o valor do elemento do vetor a ser substituido : ");
        scanf("%d", &indice);

        printf("Digite o novo valor: ");
        scanf("%d", &valorNovo);

        numeros[indice] = valorNovo ;
        printf("O valor do elemento %d foi substituido pelo valor %d sugerido \n", indice, valorNovo);
        for (i = 0; i < 10; i++) {
            printf("%d", numeros[i]);
        }

    return 0;
}