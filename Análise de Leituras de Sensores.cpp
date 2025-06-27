#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;  // número de leituras (deve ser inteiro)

    printf("Quantas leituras deseja realizar?\n"); // perguntar ao usuário o número de leituras
    scanf("%d", &n);

    // Alocar a memória para o armazenamento de n valores do tipo float
    float *leituras = (float*) malloc(n * sizeof(float));

    // Caso não haja memória suficiente para ser alocada no malloc
    if (leituras == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    // Ler os valores do usuário
    for (int i = 0; i < n; i++) {
        // contador da quantidade que o usuário escolher
        printf("Digite o valor %d:\n", i + 1);
        scanf("%f", &leituras[i]); //
    }

    // declarando as variáveis para a média, máximo e mínimo valores
    float soma = leituras[0];       // começa com o primeiro valor
    float minimo = leituras[0];
    float maximo = leituras[0];

    // calcular soma, mínimo e máximo
    for (int i = 1; i < n; i++) {
        soma += leituras[i];

        if (minimo > leituras[i]) {
            minimo = leituras[i];
        }

        if (maximo < leituras[i]) {
            maximo = leituras[i];
        }
    }

    float media = soma / n;

    // Resultados finais
    printf("O valor da media dos n termos eh %.2f \n", media);
    printf("O valor do maximo dos n termos eh %.2f\n", maximo);
    printf("O valor do minimo dos n termos eh %.2f\n", minimo);

    // Liberamos a memória alocada no final do uso
    free(leituras);

    return 0;
}

