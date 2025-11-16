#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Protótipos das funções
void inserirItem(Item mochila[], int *tamanho);
void removerItem(Item mochila[], int *tamanho);
void listarItens(Item mochila[], int tamanho);
void buscarItem(Item mochila[], int tamanho);

int main() {
    Item mochila[10]; // Vetor para armazenar até 10 itens
    int tamanho = 0;  // Número atual de itens na mochila
    int opcao;

    do {
        printf("\n===== MENU MOCHILA =====\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do ENTER

        switch (opcao) {
            case 1:
                inserirItem(mochila, &tamanho);
                break;
            case 2:
                removerItem(mochila, &tamanho);
                break;
            case 3:
                listarItens(mochila, tamanho);
                break;
            case 4:
                buscarItem(mochila, tamanho);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Função para inserir um novo item na mochila
void inserirItem(Item mochila[], int *tamanho) {
    if (*tamanho >= 10) {
        printf("Mochila cheia! Nao eh possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("Nome do item: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // Remove o '\n' da string

    printf("Tipo do item (arma, municao, cura, etc): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar(); // Limpa o buffer

    mochila[*tamanho] = novo;
    (*tamanho)++;

    printf("Item inserido com sucesso!\n");

    listarItens(mochila, *tamanho);
}

// Função para remover um item da mochila pelo nome
void removerItem(Item mochila[], int *tamanho) {
    if (*tamanho == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("Digite o nome do item a ser removido: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            // Move todos os itens à frente uma posição para trás
            for (int j = i; j < *tamanho - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*tamanho)--;
            encontrado = 1;
            printf("Item removido com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado na mochila.\n");
    }

    listarItens(mochila, *tamanho);
}

// Função para listar todos os itens da mochila
void listarItens(Item mochila[], int tamanho) {
    if (tamanho == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- Itens na Mochila ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Item %d: Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("-------------------------\n");
}

// Função para buscar item pelo nome (busca sequencial)
void buscarItem(Item mochila[], int tamanho) {
    if (tamanho == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("Digite o nome do item que deseja buscar: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado.\n");
    }
}
