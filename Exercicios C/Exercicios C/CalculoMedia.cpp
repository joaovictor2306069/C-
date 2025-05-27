#include <stdio.h>
int main() {
    float num1, num2, num3, media;
    printf("Calcular as medias com os valores de entrada do usuario");
    printf("\nDigite as notas das medias (notas 1, 2 e 3 : ");
    scanf("%f%f%f", &num1, &num2, &num3);
    media = (float)(num1 + num2 + num3) / 3;
    printf("\nMedia do usuario: %.2f", media);


    return 0;
}