#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];

    unsigned long int totalPopulacao;
    float areaCidade;
    float pib;
    int totalTurismo;

    float densidadePopulacao;
    float pibPerCapita;
    float superPoder;
} Carta;

static void lerCarta(Carta *carta, int cartaNum) {
    printf("====== CADASTRE A CARTA %d ======\n", cartaNum);
    printf("Estado (Digite uma letra de A a H): ");
    scanf(" %2s", carta->estado);

    printf("Digite o código (ex: 01): ");
    scanf("%3s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Digite a população: ");
    scanf("%lu", &carta->totalPopulacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->areaCidade);

    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->totalTurismo);
    printf("\n");
}

static void calcIndices(Carta *carta) {
    if (carta->areaCidade > 0.0f && carta->totalPopulacao > 0) {
        carta->densidadePopulacao = (float)carta->totalPopulacao / carta->areaCidade;
    } else {
        carta->densidadePopulacao = 0.0f;
    }

    if (carta->totalPopulacao > 0) {
        carta->pibPerCapita = carta->pib / (float)carta->totalPopulacao;
    } else {
        carta->pibPerCapita = 0.0f;
    }

    float inversoDensidade = (carta->densidadePopulacao > 0.0f) ? (1.0f / carta->densidadePopulacao) : 0.0f;

    carta->superPoder = (float)carta->totalPopulacao 
                     + carta->areaCidade
                     + carta->pib
                     + (float)carta->totalTurismo
                     + carta->pibPerCapita
                     + inversoDensidade;
}

static void showCarta(const Carta *carta, int idx) {
    printf("=== CARTA %d ===\n", idx);
    printf("Estado: %s\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %lu\n", carta->totalPopulacao);
    printf("Área: %.2f km²\n", carta->areaCidade);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->totalTurismo);
    printf("Densidade Populacional: %.2f\n", carta->densidadePopulacao);
    printf("PIB per Capita: %.2f\n", carta->pibPerCapita);
    printf("Super Poder: %.2f\n", carta->superPoder);
    printf("\n");
}

static void printResult(const char *power, int winner) {
    printf("%s: Carta %s venceu (%d)\n", power, winner ? "1" : "2", winner ? 1 : 0);
}

static void compare(const Carta *a, const Carta *b) {
    int winner;
    printf("*********** COMPARAÇÃO ***********:\n\n");

    winner = ( (float)a->totalPopulacao > (float)b->totalPopulacao );
    printResult("População", winner);

    winner = ( a->areaCidade > b->areaCidade );
    printResult("Área", winner);

    winner = ( a->pib > b->pib );
    printResult("PIB", winner);

    winner = ( a->totalTurismo > b->totalTurismo );
    printResult("Pontos Turísticos", winner);

    winner = ( a->densidadePopulacao < b->densidadePopulacao );
    printResult("Densidade Populacional", winner);

    winner = ( a->pibPerCapita > b->pibPerCapita );
    printResult("PIB per Capita", winner);

    winner = ( a->superPoder > b->superPoder );
    printResult("Super Poder", winner);

    printf("\n");
}

int main(void) {
    Carta carta1 = {0}, carta2 = {0};

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    calcIndices(&carta1);
    calcIndices(&carta2);
    
    showCarta(&carta1, 1);
    showCarta(&carta2, 2);

    compare(&carta1, &carta2);

    return 0;
}