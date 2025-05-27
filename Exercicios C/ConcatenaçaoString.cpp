#include <stdio.h>
#include <string.h>
int main() {
    char nome[50] = "Joao";
    char sobremone[50] = "Torrezan";
     strcat(nome," ");
    strcat(nome,sobremone);
    printf("Nome completo: %s\n",nome);
}
