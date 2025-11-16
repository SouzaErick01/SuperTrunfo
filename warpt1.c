#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Armazenando informações sobre um território: nome, cor do exército e número de tropas
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    // Vetor de structs com capacidade para 5 territórios
    struct Territorio territorios[5];

    printf("=== Cadastro de Territórios ===\n\n");

    // Laço para entrada dos dados dos 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);

        // Entrada do nome do território
        printf("Digite o nome do território: ");
        scanf(" %[^\n]", territorios[i].nome); // lê até nova linha (com espaço antes do % para limpar buffer)

        // Entrada da cor do exército
        printf("Digite a cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor);

        // Entrada do número de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Monstrando os dados cadastrados
    printf("=== Territórios Cadastrados ===\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
