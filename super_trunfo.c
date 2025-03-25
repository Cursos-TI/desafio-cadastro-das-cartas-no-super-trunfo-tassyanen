#include <stdio.h>

// Definindo a estrutura para armazenar as informações de cada carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para capturar os dados da carta
void lerCarta(Carta *carta, int numero) {
    printf("\nInforme os dados da Carta %d:\n", numero);

    // Lendo Estado
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    // Lendo Código da Carta
    printf("Código (ex: A01, B03): ");
    scanf(" %3s", carta->codigo);

    // Limpando buffer
    while (getchar() != '\n');

    // Lendo Nome da Cidade
    printf("Nome da Cidade: ");
    fgets(carta->nomeCidade, 50, stdin);

    // Remover a nova linha capturada pelo fgets
    int len = 0;
    while (carta->nomeCidade[len] != '\0') {
        if (carta->nomeCidade[len] == '\n') {
            carta->nomeCidade[len] = '\0';
            break;
        }
        len++;
    }

    // Lendo População
    printf("População: ");
    scanf("%d", &carta->populacao);

    // Lendo Área
    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    // Lendo PIB
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    // Lendo Número de Pontos Turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    Carta carta1, carta2;

    // Ler os dados das duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    // Exibir os dados das duas cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
