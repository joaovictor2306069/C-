#include <stdio.h>
#include <string.h>
int main() {
int resultado = strcmp("abc","ABC");

    if (resultado == 0) {
        printf("As string sao iguais.\n");
    }else if (resultado < 0) {
            printf("A string abc eh menor que ABC.\n");
        }else {
            printf("A string abc eh maior que ABC.\n");
    }
}
