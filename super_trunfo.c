# SuperTrunfo
#include <stdio.h>

int main () {
// Variáveis para a carta 1:
char estado1, codigo1[4], cidade1[50];
int populacao1, pontosturisticos1;
float area1, pib1;

// Variáveis para a carta 2:
char estado2, codigo2[4], cidade2[50];
int populacao2, pontosturisticos2;
float area2, pib2;

// Colocando os Dados - Carta 1:
printf("Carta 1: \n");
printf("Estado (A-H): \n");
scanf(" %c", &estado1);

printf("Código (ex: A01): \n");
scanf("%s", codigo1);

printf("Cidade: \n");
scanf("%s", cidade1);

printf("População: \n");
scanf("%d", &populacao1);

printf("Área (em Km²): \n");
scanf("%f", &area1);

printf("PIB: \n");
scanf("%f", &pib1);

printf("Número de Pontos Turísticos: \n");
scanf("%d", &pontosturisticos1);

// Colocando os Dados - Carta 2:
printf("Carta 2: \n");
printf("Estado (A-H): \n");
scanf(" %c", &estado2);

printf("Código (ex: A01): \n");
scanf("%s", codigo2);

printf("Cidade: \n");
scanf("%s", cidade2);

printf("População: \n");
scanf("%d", &populacao2);

printf("Área (em Km²): \n");
scanf("%f", &area2);

printf("PIB: \n");
scanf("%f", &pib2);

printf("Número de Pontos Turísticos: \n");
scanf("%d", &pontosturisticos2);

// Exibição das Cartas:
printf("\n === Carta 1 === \n");
printf("Estado: %c \n", estado1);
printf("Código: %s \n", codigo1);
printf("Nome da Cidade: %s \n", cidade1);
printf("População: %d \n", populacao1);
printf("Área: %.2f Km² \n", area1);
printf("PIB: %.2f Bilhões de reais \n", pib1);
printf("Número de Pontos Turísticos: %d \n", pontosturisticos1);

printf("\n === Carta 2 === \n");
printf("Estado: %c \n", estado2);
printf("Código: %s \n", codigo2);
printf("Nome da Cidade: %s \n", cidade2);
printf("População: %d \n", populacao2);
printf("Área: %.2f Km² \n", area2);
printf("PIB: %.2f Bilhões de reais \n", pib2);
printf("Número de Pontos Turísticos: %d \n", pontosturisticos2);

return 0; // Código realizado com Sucesso
}
