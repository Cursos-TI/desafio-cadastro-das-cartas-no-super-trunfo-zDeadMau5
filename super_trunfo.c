#include <stdio.h>
#include <stdlib.h>

int main() {
    // --- Variáveis da Carta 1 ---
    char estadoCarta1;
    char codigoCarta1[5];
    char nomeCidade1[50];
    unsigned long int populacao1; // Tipo alterado para unsigned long int
    float area1;
    float pib1; // Em bilhões
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    // --- Variáveis da Carta 2 ---
    char estadoCarta2;
    char codigoCarta2[5];
    char nomeCidade2[50];
    unsigned long int populacao2; // Tipo alterado para unsigned long int
    float area2;
    float pib2; // Em bilhões
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // --- Variáveis para os resultados das comparações ---
    // Em C, uma comparação booleana resulta em 1 (verdadeiro) ou 0 (falso)
    int vitoriaPopulacao;
    int vitoriaArea;
    int vitoriaPIB;
    int vitoriaPontosTuristicos;
    int vitoriaDensidade; // Regra especial: menor vence
    int vitoriaPIBperCapita;
    int vitoriaSuperPoder;


    // --- Leitura dos dados da Carta 1 ---
    printf("--- Cadastro da Primeira Carta ---\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estadoCarta1);
    printf("Digite o codigo (ex: A01): ");
    scanf("%s", codigoCarta1);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", nomeCidade1);
    printf("Digite a populacao: ");
    scanf("%lu", &populacao1); // Use %lu para unsigned long int
    printf("Digite a area (km2): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);
    printf("\n");

    // --- Leitura dos dados da Carta 2 ---
    printf("--- Cadastro da Segunda Carta ---\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estadoCarta2);
    printf("Digite o codigo (ex: B02): ");
    scanf("%s", codigoCarta2);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", nomeCidade2);
    printf("Digite a populacao: ");
    scanf("%lu", &populacao2); // Use %lu para unsigned long int
    printf("Digite a area (km2): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);
    printf("\n");

    // --- Cálculos para a Carta 1 ---
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;
    // O Super Poder soma todos os atributos, convertendo-os para float para a soma
    superPoder1 = (float)populacao1 + area1 + (pib1 * 1000000000.0) + (float)pontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);

    // --- Cálculos para a Carta 2 ---
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + (pib2 * 1000000000.0) + (float)pontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);


    // --- Comparações Atributo por Atributo ---
    // Para a maioria, o maior valor vence (Carta 1 > Carta 2 resulta em 1)
    vitoriaPopulacao = populacao1 > populacao2;
    vitoriaArea = area1 > area2;
    vitoriaPIB = pib1 > pib2;
    vitoriaPontosTuristicos = pontosTuristicos1 > pontosTuristicos2;
    vitoriaPIBperCapita = pibPerCapita1 > pibPerCapita2;
    vitoriaSuperPoder = superPoder1 > superPoder2;

    // Regra especial para densidade: o menor valor vence (Carta 1 < Carta 2 resulta em 1)
    vitoriaDensidade = densidadePopulacional1 < densidadePopulacional2;


    // --- Exibição dos Resultados Finais ---
    printf("\n\n--- Resumo e Analise das Cartas ---\n\n");

    // Exibe os dados completos da Carta 1
    printf("--- Carta 1: %s ---\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional1);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita1);
    printf("SUPER PODER: %.2f\n", superPoder1);
    printf("\n");

    // Exibe os dados completos da Carta 2
    printf("--- Carta 2: %s ---\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional2);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita2);
    printf("SUPER PODER: %.2f\n", superPoder2);
    printf("\n");

    // --- Exibição dos Resultados das Comparações ---
    printf("--- Resultado das Comparacoes (1 = Vitoria da Carta 1, 0 = Vitoria da Carta 2) ---\n");
    printf("Vitoria em Populacao: %d\n", vitoriaPopulacao);
    printf("Vitoria em Area: %d\n", vitoriaArea);
    printf("Vitoria em PIB: %d\n", vitoriaPIB);
    printf("Vitoria em Pontos Turisticos: %d\n", vitoriaPontosTuristicos);
    printf("Vitoria em Densidade (menor eh melhor): %d\n", vitoriaDensidade);
    printf("Vitoria em PIB per Capita: %d\n", vitoriaPIBperCapita);
    printf("Vitoria em SUPER PODER: %d\n", vitoriaSuperPoder);

    return 0;
}