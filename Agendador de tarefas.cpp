#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa {
    int idTarefa; // conforme solicitado no material
    char descricao[100]; // conforme solicitado no material
    int prioridade; // 1 = alta, 2 = média, 3 = baixa ; conforme solicitado no material
    struct Tarefa *prox; // ponteiro para a próxima tarefa
} Tarefa;

Tarefa *lista = NULL; // lista encadeada (começa vazia)
int prox_id = 1; // variável para gerar IDs únicos

// Função para inserir tarefa ordenada por prioridade
void inserirTarefa() {
    Tarefa *nova = (Tarefa*)malloc(sizeof(Tarefa));
    if (!nova) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    printf("Digite a descricao da tarefa: ");
    fgets(nova->descricao, 99, stdin); // ler a descrição
    nova->descricao[strcspn(nova->descricao, "\n")] = 0;

    printf("Digite a prioridade (1 - Alta, 2 - Media, 3 - Baixa): "); // conforme solicitado no material
    scanf("%d", &nova->prioridade);
    getchar(); // Limpar '\n'

    nova->idTarefa = prox_id++; // atribuir um ID única
    nova->prox = NULL;

    if (!lista || lista->prioridade > nova->prioridade) {
        nova->prox = lista;
        lista = nova;
    } else {
        Tarefa *atual = lista;
        // Procura posição correta para inserir, ordem crescente de prioridade de 1 a 3.
        while (atual->prox && atual->prox->prioridade <= nova->prioridade)
            atual = atual->prox;
        nova->prox = atual->prox;
        atual->prox = nova;
    }

    printf("Tarefa adicionada com ID %d.\n", nova->idTarefa);
}

// Função para remover a tarefa com maior prioridade
void removerTarefaPrioridadeMaxima() {
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }

    Tarefa *removida = lista;
    lista = lista->prox;
    printf("Tarefa removida: ID %d - '%s' (Prioridade: %d)\n", removida->idTarefa, removida->descricao, removida->prioridade);
    free(removida);
}

// Função para editar uma tarefa pelo ID
void editarTarefa() {
    int id;
    printf("Digite o ID da tarefa que deseja editar: ");
    scanf("%d", &id);
    getchar(); // Limpa '\n'

    Tarefa *atual = lista;
    while (atual && atual->idTarefa != id)
        atual = atual->prox;

    if (!atual) {
        printf("Tarefa nao encontrada.\n");
        return;
    }

    printf("Nova descricao (atual: %s): ", atual->descricao);
    fgets(atual->descricao, 99, stdin);
    atual->descricao[strcspn(atual->descricao, "\n")] = 0;

    printf("Nova prioridade (1 - Alta, 2 - Media, 3 - Baixa) (atual: %d): ", atual->prioridade);
    scanf("%d", &atual->prioridade);
    getchar();

    // Reordenar a lista
    Tarefa *temp = lista;
    lista = NULL;

    while (temp) {
        Tarefa *prox = temp->prox;
        if (temp == atual) {
            free(temp);
            continue;
        }

        if (!lista || lista->prioridade > temp->prioridade) {
            temp->prox = lista;
            lista = temp;
        } else {
            Tarefa *curr = lista;
            while (curr->prox && curr->prox->prioridade <= temp->prioridade)
                curr = curr->prox;
            temp->prox = curr->prox;
            curr->prox = temp;
        }
        temp = prox;
    }

    // Inserir a tarefa editada novamente
    inserirTarefa();
    printf("Tarefa editada e reordenada.\n");
}

// Função para listar todas as tarefas
void listarTarefas() {
    if (!lista) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    Tarefa *atual = lista;
    printf("\nLista de tarefas\n");
    while (atual) {
        printf("ID: %d | Descricao: %s | Prioridade: %d\n", atual->idTarefa, atual->descricao, atual->prioridade);
        atual = atual->prox;
    }
}

// Função para salvar tarefas em CSV
void salvarCSV() {
    FILE *arquivo = fopen("tarefas.csv", "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "ID;Descricao;Prioridade\n");

    Tarefa *atual = lista;
    while (atual) {
        fprintf(arquivo, "%d;%s;%d\n", atual->idTarefa, atual->descricao, atual->prioridade);
        atual = atual->prox;
    }

    fclose(arquivo);
    printf("Tarefas salvas no arquivo 'tarefas.csv'.\n");
}

// Função para carregar tarefas do arquivo CSV
void carregarCSV() {
    FILE *arquivo = fopen("tarefas.csv", "r"); // Abrir o arquivo para leitura
    if (!arquivo) {
        printf("Arquivo não encontrado ou falha ao abrir.\n");
        return;
    }

    char linha[256];
    int primeira_linha = 1;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (primeira_linha) {
            primeira_linha = 0;
            continue; // Pular cabeçalho
        }

        // Extrair os dados da linha
        char *token = strtok(linha, ";");
        int id = atoi(token);

        token = strtok(NULL, ";");
        char descricao[100];
        strcpy(descricao, token);

        token = strtok(NULL, ";");
        int prioridade = atoi(token);

        // Criar nova tarefa
        Tarefa *nova = (Tarefa*)malloc(sizeof(Tarefa));
        if (!nova) {
            printf("Erro ao alocar memória.\n");
            continue;
        }

        nova->idTarefa = id;
        strcpy(nova->descricao, descricao);
        nova->prioridade = prioridade;
        nova->prox = NULL;

        // Inserir ordenadamente
        if (!lista || lista->prioridade > nova->prioridade) {
            nova->prox = lista;
            lista = nova;
        } else {
            Tarefa *atual = lista;
            while (atual->prox && atual->prox->prioridade <= nova->prioridade)
                atual = atual->prox;
            nova->prox = atual->prox;
            atual->prox = nova;
        }

        // Atualizar o próximo ID para evitar duplicados
        if (id >= prox_id) {
            prox_id = id + 1;
        }
    }

    fclose(arquivo);
    printf("Tarefas carregadas do arquivo 'tarefas.csv'.\n");
}

// Menu principal
int main() {
    int opcao;
    do {
        printf("\n Menu de opcoes : \n");
        printf("1) Inserir tarefa\n");
        printf("2) Remover tarefa prioridade maxima\n");
        printf("3) Editar uma tarefa\n");
        printf("4) Listar tarefa\n");
        printf("5) Sair (salvar CSV)\n");
        printf("6) Carregar do CSV\n"); // Nova opção!
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa '\n'

        switch(opcao) {
            case 1:
                inserirTarefa(); break;
            case 2:
                removerTarefaPrioridadeMaxima(); break;
            case 3:
                editarTarefa(); break;
            case 4:
                listarTarefas(); break;
            case 5:
                salvarCSV();
                printf("Arquivo salvo.\n"); break;
            case 6:
                carregarCSV(); break; // Chama a nova função
            default:
                printf("Opcao invalida.\n");
        }

    } while(opcao != 5);

    // Liberar memória
    Tarefa *atual;
    while (lista) {
        atual = lista;
        lista = lista->prox;
        free(atual);
    }

    return 0;
}
