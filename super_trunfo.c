#include <stdio.h>
#include <stdlib.h>

// Estrutura para agrupar todos os dados de uma carta
struct Card {
    char pais[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

// --- Protótipos das Funções ---
void cadastrarCartas(struct Card *c1, struct Card *c2);
void jogarRodada(struct Card c1, struct Card c2);
void exibirMenuAtributos();
const char* getNomeAtributo(int escolha);
double getValorAtributo(int escolha, struct Card c);


int main() {
    struct Card carta1, carta2;
    int cartasCadastradas = 0; // Flag para controlar se as cartas já foram inseridas
    int escolhaPrincipal;

    do {
        printf("\n\n===== SUPER TRUNFO - MENU PRINCIPAL =====\n");
        printf("1. Cadastrar Novas Cartas\n");
        printf("2. Jogar Rodada de Comparacao\n");
        printf("3. Sair\n");
        printf("=======================================\n");
        printf("Sua escolha: ");
        scanf("%d", &escolhaPrincipal);

        switch (escolhaPrincipal) {
            case 1:
                cadastrarCartas(&carta1, &carta2);
                cartasCadastradas = 1; // Marca que as cartas foram cadastradas
                break;
            case 2:
                if (cartasCadastradas) {
                    jogarRodada(carta1, carta2);
                } else {
                    printf("\nERRO: Voce precisa cadastrar as cartas primeiro! (Opcao 1)\n");
                }
                break;
            case 3:
                printf("\nSaindo do programa... Ate a proxima!\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }

    } while (escolhaPrincipal != 3);

    return 0;
}

/**
 * @brief Coleta os dados das duas cartas do usuário e calcula a densidade.
 * @param c1 Ponteiro para a struct da carta 1.
 * @param c2 Ponteiro para a struct da carta 2.
 */
void cadastrarCartas(struct Card *c1, struct Card *c2) {
    printf("\n--- Cadastro da Carta 1 ---\n");
    printf("Digite o nome do pais: ");
    scanf(" %[^\n]s", c1->pais);
    printf("Digite a populacao: ");
    scanf("%lu", &c1->populacao);
    printf("Digite a area (em km2): ");
    scanf("%f", &c1->area);
    printf("Digite o PIB (em bilhoes de dolares): ");
    scanf("%f", &c1->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &c1->pontosTuristicos);
    c1->densidade = (c1->area > 0) ? ((float)c1->populacao / c1->area) : 0;

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o nome do pais: ");
    scanf(" %[^\n]s", c2->pais);
    printf("Digite a populacao: ");
    scanf("%lu", &c2->populacao);
    printf("Digite a area (em km2): ");
    scanf("%f", &c2->area);
    printf("Digite o PIB (em bilhoes de dolares): ");
    scanf("%f", &c2->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &c2->pontosTuristicos);
    c2->densidade = (c2->area > 0) ? ((float)c2->populacao / c2->area) : 0;

    printf("\nCartas cadastradas com sucesso!\n");
}


/**
 * @brief Controla uma rodada completa: escolha de dois atributos, soma e comparação.
 * @param c1 Struct da carta 1.
 * @param c2 Struct da carta 2.
 */
void jogarRodada(struct Card c1, struct Card c2) {
    int escolha1, escolha2;

    // --- Escolha do Primeiro Atributo ---
    printf("\n--- Escolha o PRIMEIRO atributo para comparar ---\n");
    exibirMenuAtributos();
    printf("Sua escolha: ");
    scanf("%d", &escolha1);

    // Validação da primeira escolha
    if (escolha1 < 1 || escolha1 > 5) {
        printf("ERRO: Escolha invalida. Tente novamente.\n");
        return; // Retorna ao menu principal
    }

    // --- Escolha do Segundo Atributo (Menu "Dinâmico") ---
    printf("\n--- Escolha o SEGUNDO atributo para comparar ---\n");
    exibirMenuAtributos(); // Mostramos o menu completo
    printf("Sua escolha: ");
    scanf("%d", &escolha2);

    // Validação da segunda escolha
    if (escolha2 < 1 || escolha2 > 5) {
        printf("ERRO: Escolha invalida. Tente novamente.\n");
        return;
    }
    // Validação para garantir que os atributos são diferentes
    if (escolha1 == escolha2) {
        printf("ERRO: Voce nao pode escolher o mesmo atributo duas vezes. Tente novamente.\n");
        return;
    }

    // --- Obtenção dos Nomes e Valores dos Atributos ---
    const char* nomeAttr1 = getNomeAtributo(escolha1);
    const char* nomeAttr2 = getNomeAtributo(escolha2);

    double valor1_c1 = getValorAtributo(escolha1, c1);
    double valor1_c2 = getValorAtributo(escolha1, c2);
    double valor2_c1 = getValorAtributo(escolha2, c1);
    double valor2_c2 = getValorAtributo(escolha2, c2);

    // --- Soma e Comparação Final ---
    double soma_c1 = valor1_c1 + valor2_c1;
    double soma_c2 = valor1_c2 + valor2_c2;

    printf("\n\n================ RESULTADO DA RODADA ================\n");
    printf("Atributos escolhidos: %s e %s\n", nomeAttr1, nomeAttr2);
    printf("---------------------------------------------------\n");
    printf("Carta 1: %s\n", c1.pais);
    printf(" > %s: %.2f\n", nomeAttr1, valor1_c1);
    printf(" > %s: %.2f\n", nomeAttr2, valor2_c1);
    printf(" > SOMA TOTAL: %.2f\n", soma_c1);
    printf("---------------------------------------------------\n");
    printf("Carta 2: %s\n", c2.pais);
    printf(" > %s: %.2f\n", nomeAttr1, valor1_c2);
    printf(" > %s: %.2f\n", nomeAttr2, valor2_c2);
    printf(" > SOMA TOTAL: %.2f\n", soma_c2);
    printf("---------------------------------------------------\n");

    if (soma_c1 > soma_c2) {
        printf("VENCEDOR DA RODADA: %s!\n", c1.pais);
    } else if (soma_c2 > soma_c1) {
        printf("VENCEDOR DA RODADA: %s!\n", c2.pais);
    } else {
        printf("RESULTADO DA RODADA: EMPATE!\n");
    }
    printf("==================================================\n");
}


/**
 * @brief Exibe o menu de atributos para o jogador escolher.
 */
void exibirMenuAtributos() {
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de Pontos Turisticos\n");
    printf("5. Densidade Demografica (menor vence)\n");
}


/**
 * @brief Retorna o nome do atributo como uma string com base na escolha numérica.
 * @param escolha O número da escolha do usuário.
 * @return Uma string constante com o nome do atributo.
 */
const char* getNomeAtributo(int escolha) {
    switch (escolha) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Desconhecido";
    }
}


/**
 * @brief Retorna o valor de um atributo específico de uma carta, convertido para double.
 * @param escolha O número da escolha do usuário.
 * @param c A struct da carta da qual o valor será extraído.
 * @return O valor do atributo como um double.
 */
double getValorAtributo(int escolha, struct Card c) {
    switch (escolha) {
        case 1: return (double)c.populacao;
        case 2: return (double)c.area;
        case 3: return (double)c.pib;
        case 4: return (double)c.pontosTuristicos;
        case 5: return (double)c.densidade * -1; // Inverte o valor para a soma
        default: return 0.0;
    }
}