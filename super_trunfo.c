#include <stdio.h>
#include <stdlib.h>

int main() {
    // --- Variáveis da Carta 1 ---
    // Variáveis para dados de entrada
    char estadoCarta1;
    char codigoCarta1[5];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1; // PIB em bilhões de reais
    int pontosTuristicos1;

    // Variáveis para dados calculados
    float densidadePopulacional1;
    float pibPerCapita1;

    // --- Variáveis da Carta 2 ---
    // Variáveis para dados de entrada
    char estadoCarta2;
    char codigoCarta2[5];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2; // PIB em bilhões de reais
    int pontosTuristicos2;

    // Variáveis para dados calculados
    float densidadePopulacional2;
    float pibPerCapita2;

    // --- Inserção de dados da Carta 1 ---
    printf("--- Cadastro da Primeira Carta ---\n");

    printf("Digite o estado da primeira carta (A-H): ");
    scanf(" %c", &estadoCarta1);

    printf("Digite o codigo da primeira carta (ex: A01): ");
    scanf("%s", codigoCarta1);

    printf("Digite o nome da cidade da primeira carta: ");
    scanf(" %[^\n]s", nomeCidade1);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao1);

    printf("Digite a area da cidade (em km2): ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n");

    // --- Inserção de dados da Carta 2 ---
    printf("--- Cadastro da Segunda Carta ---\n");

    printf("Digite o estado da segunda carta (A-H): ");
    scanf(" %c", &estadoCarta2);

    printf("Digite o codigo da segunda carta (ex: B02): ");
    scanf("%s", codigoCarta2);

    printf("Digite o nome da cidade da segunda carta: ");
    scanf(" %[^\n]s", nomeCidade2);

    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao2);

    printf("Digite a area da cidade (em km2): ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Cálculos para a Carta 1 ---
    // Evita divisão por zero se a área ou população for 0
    if (area1 > 0) {
        densidadePopulacional1 = (float)populacao1 / area1;
    } else {
        densidadePopulacional1 = 0;
    }

    if (populacao1 > 0) {
        // Multiplica o PIB por 1 bilhão para calcular o valor per capita corretamente
        pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    } else {
        pibPerCapita1 = 0;
    }


    // --- Cálculos para a Carta 2 ---
    if (area2 > 0) {
        densidadePopulacional2 = (float)populacao2 / area2;
    } else {
        densidadePopulacional2 = 0;
    }

    if (populacao2 > 0) {
        pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    } else {
        pibPerCapita2 = 0;
    }

    // --- Exibição dos dados cadastrados e calculados ---
    printf("\n\n--- Cartas Cadastradas e Analisadas ---\n\n");

    // Exibe os dados da primeira carta
    printf("Carta 1:\n");
    printf("Estado: %c\n", estadoCarta1);
    printf("Codigo: %s\n", codigoCarta1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    // Exibe os dados calculados para a Carta 1
    printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional1);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita1);

    printf("\n");

    // Exibe os dados da segunda carta
    printf("Carta 2:\n");
    printf("Estado: %c\n", estadoCarta2);
    printf("Codigo: %s\n", codigoCarta2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    // Exibe os dados calculados para a Carta 2
    printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional2);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita2);


    return 0;
}