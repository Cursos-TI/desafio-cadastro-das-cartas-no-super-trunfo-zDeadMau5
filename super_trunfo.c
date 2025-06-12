#include <stdio.h>
#include <stdlib.h>

int main() {
    // Constante para definir o número de cartas, facilitando futuras modificações
    const int NUM_CARTAS = 5;

    // --- Arrays para armazenar os dados de todas as cartas ---
    char estadoCarta[NUM_CARTAS];
    char codigoCarta[NUM_CARTAS][5];
    char nomeCidade[NUM_CARTAS][50];
    unsigned long int populacao[NUM_CARTAS];
    float area[NUM_CARTAS];
    float pib[NUM_CARTAS]; // Em bilhões
    int pontosTuristicos[NUM_CARTAS];
    float densidadePopulacional[NUM_CARTAS];
    float pibPerCapita[NUM_CARTAS];
    float superPoder[NUM_CARTAS];

    // --- Leitura dos dados usando um laço 'for' ---
    printf("--- Cadastro de %d Cartas Super Trunfo ---\n", NUM_CARTAS);
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\n--- Inserindo dados da Carta %d ---\n", i + 1);
        printf("Digite o estado (A-H): ");
        scanf(" %c", &estadoCarta[i]);
        printf("Digite o codigo (ex: A01): ");
        scanf("%s", codigoCarta[i]);
        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]s", nomeCidade[i]);
        printf("Digite a populacao: ");
        scanf("%lu", &populacao[i]); // %lu para unsigned long int
        printf("Digite a area (km2): ");
        scanf("%f", &area[i]);
        printf("Digite o PIB (em bilhoes de reais): ");
        scanf("%f", &pib[i]);
        printf("Digite o numero de pontos turisticos: ");
        scanf("%d", &pontosTuristicos[i]);
    }

    // --- Cálculos para todas as cartas usando um laço 'for' ---
    for (int i = 0; i < NUM_CARTAS; i++) {
        // Evita divisão por zero
        if (area[i] > 0) {
            densidadePopulacional[i] = (float)populacao[i] / area[i];
        } else {
            densidadePopulacional[i] = 0;
        }
        
        if (populacao[i] > 0) {
            pibPerCapita[i] = (pib[i] * 1000000000.0) / (float)populacao[i];
        } else {
            pibPerCapita[i] = 0;
        }

        superPoder[i] = (float)populacao[i] + area[i] + (pib[i] * 1000000000.0) + (float)pontosTuristicos[i] + pibPerCapita[i];
        // Adiciona o inverso da densidade, se a densidade não for zero
        if (densidadePopulacional[i] > 0) {
             superPoder[i] += (1.0 / densidadePopulacional[i]);
        }
    }

    // --- Determinar a carta vencedora para cada atributo ---
    int idxVencedorPop = 0, idxVencedorArea = 0, idxVencedorPIB = 0;
    int idxVencedorPontos = 0, idxVencedorDensidade = 0, idxVencedorPIBpc = 0, idxVencedorPoder = 0;

    for (int i = 1; i < NUM_CARTAS; i++) {
        // Maior valor vence
        if (populacao[i] > populacao[idxVencedorPop]) idxVencedorPop = i;
        if (area[i] > area[idxVencedorArea]) idxVencedorArea = i;
        if (pib[i] > pib[idxVencedorPIB]) idxVencedorPIB = i;
        if (pontosTuristicos[i] > pontosTuristicos[idxVencedorPontos]) idxVencedorPontos = i;
        if (pibPerCapita[i] > pibPerCapita[idxVencedorPIBpc]) idxVencedorPIBpc = i;
        if (superPoder[i] > superPoder[idxVencedorPoder]) idxVencedorPoder = i;

        // Regra especial para densidade: Menor valor vence
        if (densidadePopulacional[i] < densidadePopulacional[idxVencedorDensidade]) idxVencedorDensidade = i;
    }

    // --- Exibição dos Resultados Finais ---
    printf("\n\n--- Resumo e Analise das %d Cartas ---\n", NUM_CARTAS);

    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\n--- Carta %d: %s ---\n", i + 1, nomeCidade[i]);
        printf("Populacao: %lu\n", populacao[i]);
        printf("Area: %.2f km2\n", area[i]);
        printf("PIB: %.2f bilhoes\n", pib[i]);
        printf("Pontos Turisticos: %d\n", pontosTuristicos[i]);
        printf("Densidade Populacional: %.2f hab/km2\n", densidadePopulacional[i]);
        printf("PIB per Capita: R$ %.2f\n", pibPerCapita[i]);
        printf("SUPER PODER: %.2f\n", superPoder[i]);
    }

    // --- Exibição dos Vencedores por Categoria ---
    printf("\n\n--- VENCEDORES POR CATEGORIA ---\n");
    printf("Maior Populacao:       Carta %d (%s) com %lu habitantes\n", idxVencedorPop + 1, nomeCidade[idxVencedorPop], populacao[idxVencedorPop]);
    printf("Maior Area:            Carta %d (%s) com %.2f km2\n", idxVencedorArea + 1, nomeCidade[idxVencedorArea], area[idxVencedorArea]);
    printf("Maior PIB:             Carta %d (%s) com %.2f bilhoes\n", idxVencedorPIB + 1, nomeCidade[idxVencedorPIB], pib[idxVencedorPIB]);
    printf("Mais Pontos Turisticos:Carta %d (%s) com %d pontos\n", idxVencedorPontos + 1, nomeCidade[idxVencedorPontos], pontosTuristicos[idxVencedorPontos]);
    printf("Menor Densidade:       Carta %d (%s) com %.2f hab/km2\n", idxVencedorDensidade + 1, nomeCidade[idxVencedorDensidade], densidadePopulacional[idxVencedorDensidade]);
    printf("Maior PIB per Capita:  Carta %d (%s) com R$ %.2f\n", idxVencedorPIBpc + 1, nomeCidade[idxVencedorPIBpc], pibPerCapita[idxVencedorPIBpc]);
    printf("Maior SUPER PODER:     Carta %d (%s) com %.2f\n", idxVencedorPoder + 1, nomeCidade[idxVencedorPoder], superPoder[idxVencedorPoder]);

    return 0;
}