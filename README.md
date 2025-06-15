# Super Trunfo em C - Jogo de Comparação de Atributos

Este é um programa em C que simula uma rodada do jogo Super Trunfo. O sistema permite ao usuário cadastrar duas cartas (representando países) e, em seguida, iniciar uma rodada de comparação. O jogador escolhe dois atributos diferentes, e a carta com a maior soma dos valores desses atributos vence a rodada.

## Funcionalidades

- **Cadastro de Cartas:** Permite inserir os dados de dois países para a comparação.
- **Menu Principal Interativo:** Navegação clara para cadastrar cartas, jogar uma rodada ou sair.
- **Escolha de Múltiplos Atributos:** O jogador escolhe dois atributos distintos para a comparação.
- **Validação de Escolha:** O sistema impede que o mesmo atributo seja escolhido duas vezes na mesma rodada.
- **Lógica de Comparação Flexível:** A carta com a maior soma dos atributos vence, com uma regra especial para a densidade demográfica.
- **Resultados Detalhados:** Exibição clara dos valores, somas e do vencedor da rodada.

## Como Compilar e Executar

Você precisará de um compilador C, como o **GCC**, instalado no seu sistema.

### 1. Compilação

Abra o terminal ou prompt de comando, navegue até o diretório onde você salvou o arquivo `super_trunfo.c` e execute o seguinte comando:

```bash
gcc -o super_trunfo super_trunfo.c -Wextra -Wall
```

- `gcc`: O comando para chamar o compilador.
- `-o super_trunfo`: Cria um arquivo executável chamado `super_trunfo`.
- `super_trunfo.c`: O nome do seu arquivo de código-fonte.
- `-Wextra -Wall`: Flags recomendadas que ativam avisos extras do compilador, ajudando a encontrar possíveis erros.

### 2. Execução

Após a compilação bem-sucedida, execute o programa com o seguinte comando:

**No Linux ou macOS:**
```bash
./super_trunfo
```

**No Windows:**
```bash
super_trunfo.exe
```

## Exemplo de Uso

1.  Ao iniciar o programa, você verá o menu principal:

    ```
    ===== SUPER TRUNFO - MENU PRINCIPAL =====
    1. Cadastrar Novas Cartas
    2. Jogar Rodada de Comparacao
    3. Sair
    =======================================
    Sua escolha:
    ```

2.  Escolha a opção `1` para cadastrar as duas cartas. O programa solicitará os dados de cada país.

3.  Após o cadastro, no menu principal, escolha a opção `2` para jogar uma rodada. O menu de atributos será exibido:

    ```
    --- Escolha o PRIMEIRO atributo para comparar ---
    1. Populacao
    2. Area
    3. PIB
    4. Numero de Pontos Turisticos
    5. Densidade Demografica
    ```

4.  Escolha o primeiro e, em seguida, o segundo atributo. O programa validará se as escolhas são diferentes.

5.  Finalmente, o resultado completo da rodada será exibido na tela:
    ```
    ================ RESULTADO DA RODADA ================
    Atributos escolhidos: Populacao e PIB
    ---------------------------------------------------
    Carta 1: Brasil
     > Populacao: 215000000.00
     > PIB: 1600.00
     > SOMA TOTAL: 215001600.00
    ---------------------------------------------------
    Carta 2: Argentina
     > Populacao: 45000000.00
     > PIB: 450.00
     > SOMA TOTAL: 45000450.00
    ---------------------------------------------------
    VENCEDOR DA RODADA: Brasil!
    ==================================================
    ```

## Atributos para Comparação

Você pode escolher dois atributos da lista abaixo para cada rodada:

1.  **População:** Número de habitantes (maior vence).
2.  **Área:** Extensão territorial em km² (maior vence).
3.  **PIB:** Produto Interno Bruto em bilhões de dólares (maior vence).
4.  **Número de Pontos Turísticos:** Quantidade de pontos de interesse (maior vence).
5.  **Densidade Demográfica:** Habitantes por km² (**MENOR** vence).