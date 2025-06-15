#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções para melhor organização (opcional, mas boa prática)
void exibirMenu();
void compararPopulacao(char pais1[], unsigned long int pop1, char pais2[], unsigned long int pop2);
void compararArea(char pais1[], float area1, char pais2[], float area2);
void compararPIB(char pais1[], float pib1, char pais2[], float pib2);
void compararPontosTuristicos(char pais1[], int pontos1, char pais2[], int pontos2);
void compararDensidade(char pais1[], float dens1, char pais2[], float dens2);

int main() {
    // --- BLOCO 1: Declaração de Variáveis ---
    // Atributos da Carta 1
    char pais1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;

    // Atributos da Carta 2
    char pais2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;

    int escolha; // Variável para a escolha do usuário no menu

    // --- BLOCO 2: Cadastro das Cartas ---
    printf("--- Cadastro do Jogo Super Trunfo ---\n");

    // Coleta de dados da Carta 1
    printf("\n--- Dados da Carta 1 ---\n");
    printf("Digite o nome do pais: ");
    scanf(" %[^\n]s", pais1);
    printf("Digite a populacao: ");
    scanf("%lu", &populacao1);
    printf("Digite a area (em km2): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhoes de dolares): ");
    scanf("%f", &pib1);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // Coleta de dados da Carta 2
    printf("\n--- Dados da Carta 2 ---\n");
    printf("Digite o nome do pais: ");
    scanf(" %[^\n]s", pais2);
    printf("Digite a populacao: ");
    scanf("%lu", &populacao2);
    printf("Digite a area (em km2): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes de dolares): ");
    scanf("%f", &pib2);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- BLOCO 3: Cálculos Iniciais ---
    // Calcula a densidade demográfica para ambas as cartas
    if (area1 > 0) densidade1 = (float)populacao1 / area1; else densidade1 = 0;
    if (area2 > 0) densidade2 = (float)populacao2 / area2; else densidade2 = 0;


    // --- BLOCO 4: Laço Principal do Jogo (Menu Interativo) ---
    do {
        exibirMenu(); // Mostra as opções para o jogador
        printf("Sua escolha: ");
        scanf("%d", &escolha);

        // A estrutura switch direciona para a comparação correta com base na escolha
        switch (escolha) {
            case 1:
                compararPopulacao(pais1, populacao1, pais2, populacao2);
                break;
            case 2:
                compararArea(pais1, area1, pais2, area2);
                break;
            case 3:
                compararPIB(pais1, pib1, pais2, pib2);
                break;
            case 4:
                compararPontosTuristicos(pais1, pontosTuristicos1, pais2, pontosTuristicos2);
                break;
            case 5:
                compararDensidade(pais1, densidade1, pais2, densidade2);
                break;
            case 6:
                printf("\nSaindo do programa... Obrigado por jogar!\n");
                break;
            default:
                // Lida com entradas inválidas do usuário
                printf("\nOpcao invalida! Por favor, escolha um numero de 1 a 6.\n");
                break;
        }

    } while (escolha != 6); // O laço continua até o usuário escolher sair (opção 6)

    return 0; // Fim do programa
}


/**
 * @brief Exibe o menu de opções para o jogador.
 */
void exibirMenu() {
    printf("\n\n--------------------------------------");
    printf("\nQual atributo voce deseja comparar?\n");
    printf("--------------------------------------\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de Pontos Turisticos\n");
    printf("5. Densidade Demografica (menor vence)\n");
    printf("6. Sair do Jogo\n");
    printf("--------------------------------------\n");
}

/**
 * @brief Compara as cartas pelo atributo Populacao.
 */
void compararPopulacao(char pais1[], unsigned long int pop1, char pais2[], unsigned long int pop2) {
    printf("\n--- Comparando por: Populacao ---\n");
    printf("Carta 1 (%s): %lu\n", pais1, pop1);
    printf("Carta 2 (%s): %lu\n", pais2, pop2);
    if (pop1 > pop2) {
        printf("Resultado: %s venceu!\n", pais1);
    } else if (pop2 > pop1) {
        printf("Resultado: %s venceu!\n", pais2);
    } else {
        printf("Resultado: Empate!\n");
    }
}

/**
 * @brief Compara as cartas pelo atributo Area.
 */
void compararArea(char pais1[], float area1, char pais2[], float area2) {
    printf("\n--- Comparando por: Area ---\n");
    printf("Carta 1 (%s): %.2f km2\n", pais1, area1);
    printf("Carta 2 (%s): %.2f km2\n", pais2, area2);
    if (area1 > area2) {
        printf("Resultado: %s venceu!\n", pais1);
    } else if (area2 > area1) {
        printf("Resultado: %s venceu!\n", pais2);
    } else {
        printf("Resultado: Empate!\n");
    }
}

/**
 * @brief Compara as cartas pelo atributo PIB.
 */
void compararPIB(char pais1[], float pib1, char pais2[], float pib2) {
    printf("\n--- Comparando por: PIB ---\n");
    printf("Carta 1 (%s): %.2f bilhoes\n", pais1, pib1);
    printf("Carta 2 (%s): %.2f bilhoes\n", pais2, pib2);
    if (pib1 > pib2) {
        printf("Resultado: %s venceu!\n", pais1);
    } else if (pib2 > pib1) {
        printf("Resultado: %s venceu!\n", pais2);
    } else {
        printf("Resultado: Empate!\n");
    }
}

/**
 * @brief Compara as cartas pelo atributo Pontos Turisticos.
 */
void compararPontosTuristicos(char pais1[], int pontos1, char pais2[], int pontos2) {
    printf("\n--- Comparando por: Pontos Turisticos ---\n");
    printf("Carta 1 (%s): %d\n", pais1, pontos1);
    printf("Carta 2 (%s): %d\n", pais2, pontos2);
    if (pontos1 > pontos2) {
        printf("Resultado: %s venceu!\n", pais1);
    } else if (pontos2 > pontos1) {
        printf("Resultado: %s venceu!\n", pais2);
    } else {
        printf("Resultado: Empate!\n");
    }
}

/**
 * @brief Compara as cartas pelo atributo Densidade Demografica.
 * Neste caso, o menor valor vence.
 */
void compararDensidade(char pais1[], float dens1, char pais2[], float dens2) {
    printf("\n--- Comparando por: Densidade Demografica (MENOR vence) ---\n");
    printf("Carta 1 (%s): %.2f hab/km2\n", pais1, dens1);
    printf("Carta 2 (%s): %.2f hab/km2\n", pais2, dens2);
    if (dens1 < dens2) {
        printf("Resultado: %s venceu!\n", pais1);
    } else if (dens2 < dens1) {
        printf("Resultado: %s venceu!\n", pais2);
    } else {
        printf("Resultado: Empate!\n");
    }
}