#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5   // Tamanho fixo da fila

// Estrutura que representa uma peça do Tetris
typedef struct {
    char nome;   // Tipo da peça ('I', 'O', 'T', 'L')
    int id;      // Identificador único
} Peca;

// Estrutura de fila circular
typedef struct {
    Peca itens[TAM_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

// --------------------- PROTÓTIPOS ---------------------
void inicializarFila(Fila *f);
int filaCheia(Fila *f);
int filaVazia(Fila *f);
Peca gerarPeca(int id);
void enqueue(Fila *f, Peca nova);
Peca dequeue(Fila *f);
void exibirFila(Fila *f);

// --------------------- FUNÇÃO PRINCIPAL ---------------------
int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    int contadorID = 0; // Controla o ID de cada peça criada

    // Gerar fila inicial com 5 peças
    for (int i = 0; i < TAM_FILA; i++) {
        enqueue(&fila, gerarPeca(contadorID++));
    }

    do {
        printf("\n==============================\n");
        printf("      FILA DE PEÇAS TETRIS\n");
        printf("==============================\n");

        exibirFila(&fila);

        printf("\nOpções:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!filaVazia(&fila)) {
                    Peca jogada = dequeue(&fila);
                    printf("\nPeça jogada: [%c %d]\n", jogada.nome, jogada.id);
                } else {
                    printf("\nA fila está vazia! Não há peça para jogar.\n");
                }
                break;

            case 2:
                if (!filaCheia(&fila)) {
                    enqueue(&fila, gerarPeca(contadorID++));
                    printf("\nNova peça inserida na fila!\n");
                } else {
                    printf("\nA fila está cheia! Não é possível inserir mais peças.\n");
                }
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

// --------------------- FUNÇÕES DA FILA ---------------------

// Inicializa fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

// Verifica se fila está cheia
int filaCheia(Fila *f) {
    return f->quantidade == TAM_FILA;
}

// Verifica se fila está vazia
int filaVazia(Fila *f) {
    return f->quantidade == 0;
}

// Gera uma peça com tipo aleatório
Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca nova;
    nova.nome = tipos[rand() % 4];
    nova.id = id;
    return nova;
}

// Insere peça ao final da fila
void enqueue(Fila *f, Peca nova) {
    if (!filaCheia(f)) {
        f->itens[f->fim] = nova;
        f->fim = (f->fim + 1) % TAM_FILA;
        f->quantidade++;
    }
}

// Remove peça da frente da fila
Peca dequeue(Fila *f) {
    Peca removida = {'X', -1}; // Caso erro
    if (!filaVazia(f)) {
        removida = f->itens[f->inicio];
        f->inicio = (f->inicio + 1) % TAM_FILA;
        f->quantidade--;
    }
    return removida;
}

// Exibe fila completa
void exibirFila(Fila *f) {
    printf("\nFila de peças:\n");
    if (filaVazia(f)) {
        printf("[vazia]\n");
        return;
    }

    int i = f->inicio;
    for (int c = 0; c < f->quantidade; c++) {
        printf("[%c %d] ", f->itens[i].nome, f->itens[i].id);
        i = (i + 1) % TAM_FILA;
    }
    printf("\n");
}
