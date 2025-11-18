#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------
// Estrutura da sala (nó da árvore)
// ---------------------------
typedef struct sala {
    char nome[50];          // Nome do cômodo
    struct sala *esq;       // Caminho à esquerda
    struct sala *dir;       // Caminho à direita
} Sala;

// ---------------------------
// Função: criarSala()
// Aloca uma sala com nome e filhos nulos
// ---------------------------
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

// ---------------------------
// Função: explorarSalas()
// Permite ao jogador navegar pela árvore,
// escolhendo esquerda (e), direita (d) ou sair (s).
// ---------------------------
void explorarSalas(Sala *atual) {
    char opcao;

    while (atual != NULL) {
        printf("\n-----------------------------------\n");
        printf("Você está na sala: %s\n", atual->nome);

        // Se não há caminhos, o jogador chegou ao final
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Não há mais caminhos. Você chegou ao fim da exploração!\n");
            return;
        }

        printf("Caminhos disponíveis:\n");
        if (atual->esq != NULL) printf(" (e) - Ir para %s\n", atual->esq->nome);
        if (atual->dir != NULL) printf(" (d) - Ir para %s\n", atual->dir->nome);
        printf(" (s) - Sair da exploração\n");

        printf("Escolha sua ação: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esq != NULL) {
            atual = atual->esq;
        }
        else if (opcao == 'd' && atual->dir != NULL) {
            atual = atual->dir;
        }
        else if (opcao == 's') {
            printf("Exploração encerrada.\n");
            return;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// ---------------------------
// Função principal
// Monta manualmente o mapa (árvore binária)
// e inicia a exploração
// ---------------------------
int main() {
    // Criando as salas
    Sala *hall      = criarSala("Hall de Entrada");
    Sala *estudo    = criarSala("Sala de Estudo");
    Sala *cozinha   = criarSala("Cozinha");
    Sala *biblioteca= criarSala("Biblioteca");
    Sala *jardim    = criarSala("Jardim");
    Sala *adega     = criarSala("Adega");

    // Montando a árvore (mapa da mansão)
    
    hall->esq      = estudo;
    hall->dir      = cozinha;

    estudo->esq    = biblioteca;
    estudo->dir    = jardim;

    cozinha->esq   = adega;

    // Iniciar exploração
    explorarSalas(hall);

    return 0;
}
