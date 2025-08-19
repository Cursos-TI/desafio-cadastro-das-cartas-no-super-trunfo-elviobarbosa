#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Elvio Castro Barbosa


int main() {
    // Carta 1
    char estado1[2];
    char codigo1[4];
    char nomeCidade1[50];
    int totalPopulacao1;
    float areaCidade1;
    float pib1;
    int totalNumTurismo1;

    // Carta 2
    char estado2[2];
    char codigo2[4];
    char nomeCidade2[50];
    int totalPopulacao2;
    float areaCidade2;
    float pib2;
    int totalNumTurismo2;

    // ======= CARTA 1 =======
    printf("====== CADASTRE A CARTA 1 ======\n");
    printf("Estado (Digite uma letra de A a H): ");
    scanf("%1s", estado1);

    printf("Digite o código (ex: 01): ");
    scanf("%3s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a população: ");
    scanf("%d", &totalPopulacao1);

    printf("Digite a área (em km²): ");
    scanf("%f", &areaCidade1);

    printf("Digite o PIB: ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &totalNumTurismo1);

    // ======= CARTA 2 =======
    printf("\n====== CADASTRE A CARTA 2 ======\n");
    printf("Estado (Digite uma letra de A a H): ");
    scanf("%1s", estado2);

    printf("Digite o código (ex: 02): ");
    scanf("%3s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a população: ");
    scanf("%d", &totalPopulacao2);

    printf("Digite a área (em km²): ");
    scanf("%f", &areaCidade2);

    printf("Digite o PIB: ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &totalNumTurismo2);

    // ======= EXIBIÇÃO =======
    printf("\n\n=== CARTA 1 ===\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", totalPopulacao1);
    printf("Área: %.2f km²\n", areaCidade1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", totalNumTurismo1);

    printf("\n=== CARTA 2 ===\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", totalPopulacao2);
    printf("Área: %.2f km²\n", areaCidade2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", totalNumTurismo2);

    return 0;
}

