#include <stdio.h>
#include <stdlib.h>

int main() {
    // --- Declaração de Variáveis para a Carta 1 ---
    char estado1[3];            // String para a sigla do estado (ex: "SP")
    char codigoCarta1[5];       // String para o código (ex: "A01")
    char nomeCidade1[50];       // String para o nome da cidade
    unsigned long int populacao1; // Usando unsigned long int para populações grandes
    float area1;
    float pib1;                 // PIB em bilhões
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;

    // --- Declaração de Variáveis para a Carta 2 ---
    char estado2[3];
    char codigoCarta2[5];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;

    // --- BLOCO 1: ENTRADA DE DADOS ---
    // Coleta de informações da primeira carta
    printf("--- Cadastro da Primeira Carta ---\n");
    printf("Digite a sigla do estado (ex: SP): ");
    scanf("%s", estado1);
    printf("Digite o codigo da carta (ex: A01): ");
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

    // Coleta de informações da segunda carta
    printf("--- Cadastro da Segunda Carta ---\n");
    printf("Digite a sigla do estado (ex: RJ): ");
    scanf("%s", estado2);
    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%s", codigoCarta2);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", nomeCidade2);
    printf("Digite a populacao: ");
    scanf("%lu", &populacao2);
    printf("Digite a area (km2): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);
    printf("\n");

    // --- BLOCO 2: CÁLCULOS DOS ATRIBUTOS DERIVADOS ---
    // Cálculo para a Carta 1
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / (float)populacao1;

    // Cálculo para a Carta 2
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / (float)populacao2;


    // --- BLOCO 3: COMPARAÇÃO E EXIBIÇÃO DO RESULTADO ---
    //
    // NESTA SEÇÃO, O ATRIBUTO PARA COMPARAÇÃO É ESCOLHIDO.
    // Para alterar, basta substituir as variáveis 'populacao1' e 'populacao2'
    // pelas variáveis do atributo desejado (ex: area1 vs area2).
    // Lembre-se de ajustar a regra de comparação se escolher Densidade Populacional.
    //
    printf("--------------------------------------------------\n");
    printf("--- Comparacao de Cartas (Atributo: Populacao) ---\n");
    printf("--------------------------------------------------\n\n");

    // Exibe os valores das duas cartas para o atributo escolhido
    printf("Carta 1 - %s (%s): %lu\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu\n\n", nomeCidade2, estado2, populacao2);

    // Lógica para determinar e anunciar o vencedor
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }
    printf("--------------------------------------------------\n");


    /*
    // EXEMPLO: Se quisesse comparar por DENSIDADE POPULACIONAL (menor vence)
    // O bloco de comparação seria assim:
    
    printf("------------------------------------------------------------\n");
    printf("--- Comparacao de Cartas (Atributo: Densidade Populacional) ---\n");
    printf("------------------------------------------------------------\n\n");

    printf("Carta 1 - %s (%s): %.2f hab/km2\n", nomeCidade1, estado1, densidadePopulacional1);
    printf("Carta 2 - %s (%s): %.2f hab/km2\n\n", nomeCidade2, estado2, densidadePopulacional2);

    // Regra invertida: o menor valor vence
    if (densidadePopulacional1 < densidadePopulacional2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (densidadePopulacional2 < densidadePopulacional1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }
    printf("------------------------------------------------------------\n");
    */

    return 0; // Indica que o programa terminou com sucesso
}