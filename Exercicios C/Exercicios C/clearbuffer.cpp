#include <stdio.h>
void clearBuffer() {
    int k;
    while ((k = getchar()) != '\n' && k != EOF);
}
int main() {
    int i, n;
    char c;
    printf("\nInsira um numero inteiro e um caractere ! ");
    printf("\nInsira um numero inteiro: ");
    clearBuffer();
    printf("\nInsira um caracterer : ");
    scanf("%c", &c);
    clearBuffer();
    printf("\nQuantas vezes deseja incrementar o numero e o caractere? ");
    scanf("%d", &n);
    clearBuffer();

    for (int j = 0; j < n; j++) {
        i++/
            c++;

        printf("\nApos incrementar %d vezes, o valor inteiro eh %d e o caracterer eh %c.\n", n,i,c);

    }
return 0;
}