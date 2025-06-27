#include <stdio.h>
#include <string.h>

int main() {
    char produtos[3][50];      // Armazena os nomes dos produtos
    int quantidade[3];         // Armazena a quantidade de cada produto
    float precos[3];           // Armazena o preço de cada produto
    float estoquetotal = 0.0;  // Armazena o valor total do estoque
    int i, escolha, qtdevendas;

    // Cadastro dos produtos
    for (i = 0; i < 3; i++) {
        printf("Digite o nome do produto %d: ", i + 1);
        fgets(produtos[i], sizeof(produtos[i]), stdin);
        produtos[i][strcspn(produtos[i], "\n")] = 0; // Remove o '\n' do final da string

        printf("Digite a quantidade do produto: ");
        scanf("%d", &quantidade[i]);

        printf("Digite o preco do produto: ");
        scanf("%f", &precos[i]);

        getchar(); // Limpa o buffer
        printf("\n");
    }

    // Exibe o estoque inicial
    printf("\nEstoque de produtos:\n");
    estoquetotal = 0.0;
    for (i = 0; i < 3; i++) {
        printf("Produto: %s\t Quantidade: %d\t Preco: %.2f\n", produtos[i], quantidade[i], precos[i]);
        estoquetotal += quantidade[i] * precos[i];
    }
    printf("O valor total do estoque eh: %.2f\n", estoquetotal);

    // Venda
    printf("\nDigite o numero do codigo do produto vendido (1 a 3): ");
    scanf("%d", &escolha);
    getchar();

    if (escolha < 1 || escolha > 3) {
        printf("Codigo invalido!\n");
        return 1;
    }

    printf("Qual a quantidade vendida: ");
    scanf("%d", &qtdevendas);
    getchar();

    if (qtdevendas > quantidade[escolha - 1]) {
        printf("Quantidade insuficiente em estoque!\n");
    } else {
        quantidade[escolha - 1] -= qtdevendas;
    }

    // Exibe o estoque atualizado
    printf("\nEstoque atualizado:\n");
    estoquetotal = 0.0;
    for (i = 0; i < 3; i++) {
        printf("Produto: %s\t Quantidade: %d\t Preco: %.2f\n", produtos[i], quantidade[i], precos[i]);
        estoquetotal += quantidade[i] * precos[i];
    }
    printf("O valor total do estoque atualizado eh: %.2f\n", estoquetotal);

    return 0;
}
