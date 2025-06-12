#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração das variáveis para a primeira carta
    char estadoCarta1;
    char codigoCarta1[5]; // "H04" + caractere nulo '\0'
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Declaração das variáveis para a segunda carta
    char estadoCarta2;
    char codigoCarta2[5];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // --- Inserção de dados da Carta 1 ---
    printf("--- Cadastro da Primeira Carta ---\n");

    // Solicita e lê o estado da primeira carta
    printf("Digite o estado da primeira carta (A-H): ");
    scanf(" %c", &estadoCarta1);

    // Solicita e lê o código da primeira carta
    printf("Digite o codigo da primeira carta (ex: A01): ");
    scanf("%s", codigoCarta1);

    // Solicita e lê o nome da cidade da primeira carta
    printf("Digite o nome da cidade da primeira carta: ");
    scanf(" %[^\n]s", nomeCidade1); // Lê a string até encontrar uma nova linha

    // Solicita e lê a população da primeira carta
    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao1);

    // Solicita e lê a área da primeira carta
    printf("Digite a area da cidade (em km2): ");
    scanf("%f", &area1);

    // Solicita e lê o PIB da primeira carta
    printf("Digite o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib1);

    // Solicita e lê o número de pontos turísticos da primeira carta
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n"); // Adiciona uma linha em branco para separação

    // --- Inserção de dados da Carta 2 ---
    printf("--- Cadastro da Segunda Carta ---\n");

    // Solicita e lê o estado da segunda carta
    printf("Digite o estado da segunda carta (A-H): ");
    scanf(" %c", &estadoCarta2);

    // Solicita e lê o código da segunda carta
    printf("Digite o codigo da segunda carta (ex: B02): ");
    scanf("%s", codigoCarta2);

    // Solicita e lê o nome da cidade da segunda carta
    printf("Digite o nome da cidade da segunda carta: ");
    scanf(" %[^\n]s", nomeCidade2);

    // Solicita e lê a população da segunda carta
    printf("Digite a populacao da cidade: ");
    scanf("%d", &populacao2);

    // Solicita e lê a área da segunda carta
    printf("Digite a area da cidade (em km2): ");
    scanf("%f", &area2);

    // Solicita e lê o PIB da segunda carta
    printf("Digite o PIB da cidade (em bilhoes de reais): ");
    scanf("%f", &pib2);

    // Solicita e lê o número de pontos turísticos da segunda carta
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Exibição dos dados cadastrados ---
    printf("\n\n--- Cartas Cadastradas ---\n\n");

    // Exibe os dados da primeira carta
    printf("Carta 1:\n");
    printf("Estado: %c\n", estadoCarta1);
    printf("Codigo: %s\n", codigoCarta1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1); // %.2f para formatar com 2 casas decimais
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);

    printf("\n"); // Adiciona uma linha em branco para separação

    // Exibe os dados da segunda carta
    printf("Carta 2:\n");
    printf("Estado: %c\n", estadoCarta2);
    printf("Codigo: %s\n", codigoCarta2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);

    return 0; // Indica que o programa terminou com sucesso
}