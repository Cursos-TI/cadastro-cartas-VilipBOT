#include <stdio.h>
#include <string.h>


typedef struct {
    char estado[30];
    char nome_cidade[50];
    char codigo_carta[10];
    int populacao;
    float area_km2;
    float pib;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder; 
    int numeros_turisticos;
} Carta;

// Função para exibir a carta
void exibirCarta(Carta c) {
    printf("--------------------------\n");
    printf("Estado: %s\n", c.estado);
    printf("Codigo da Carta: %s\n", c.codigo_carta);
    printf("Cidade: %s\n", c.nome_cidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area em Km²: %.2f\n", c.area_km2);
    printf("PIB: %.2f\n", c.pib);
    printf("Numeros Turisticos: %d\n", c.numeros_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("PIB Per Capita: %.2f\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder); // Exibe o Super Poder
    printf("--------------------------\n");
}

// Função para preencher a carta
void preencherCarta(Carta *c) {
    char input_buffer[50];

   
    while (getchar() != '\n');

    printf("Escolha o Estado: \n");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = 0;
    strcpy(c->estado, input_buffer);

    printf("Coloque um codigo para a carta (Ex: RJ01): \n");
    scanf("%s", c->codigo_carta);

    while (getchar() != '\n');

    printf("Escolha o nome da sua cidade: \n");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = 0;
    strcpy(c->nome_cidade, input_buffer);

    printf("Qual e a populacao da sua cidade? \n");
    scanf("%d", &c->populacao);

    printf("Qual e a area em Km² da sua cidade? \n");
    scanf("%f", &c->area_km2);

    printf("Qual e o PIB da sua cidade? \n");
    scanf("%f", &c->pib);

    printf("Quantos pontos turisticos tem na sua cidade? \n");
    scanf("%d", &c->numeros_turisticos);

    // Cálculos da Densidade Populacional e PIB Per Capita
    if (c->area_km2 > 0) {
        c->densidade_populacional = (float)c->populacao / c->area_km2;
    } else {
        c->densidade_populacional = 0.0;
    }

    if (c->populacao > 0) {
        c->pib_per_capita = c->pib / c->populacao;
    } else {
        c->pib_per_capita = 0.0;
    }

    // Cálculo do Super Poder
    float inverso_densidade = (c->densidade_populacional > 0) ? (1.0 / c->densidade_populacional) : 0.0;
    c->super_poder = (float)c->populacao + c->area_km2 + c->pib + c->numeros_turisticos + c->pib_per_capita + inverso_densidade;
}

//  Função para comparar as cartas
void compararCartas(Carta c1, Carta c2) {
    printf("\n--- Comparando as cartas... ---\n");

    printf("Super Poder da Carta 1 (%s): %.2f\n", c1.nome_cidade, c1.super_poder);
    printf("Super Poder da Carta 2 (%s): %.2f\n", c2.nome_cidade, c2.super_poder);

    if (c1.super_poder > c2.super_poder) {
        printf("\nA Carta 1 (%s) vence a Carta 2 (%s)!\n", c1.nome_cidade, c2.nome_cidade);
    } else if (c2.super_poder > c1.super_poder) {
        printf("\nA Carta 2 (%s) vence a Carta 1 (%s)!\n", c2.nome_cidade, c1.nome_cidade);
    } else {
        printf("\nEmpate! Ambas as cartas tem o mesmo Super Poder.\n");
    }
}


int main() {
    Carta carta1, carta2;

    printf("--- Preenchendo a primeira carta ---\n");
    preencherCarta(&carta1);

    printf("\n--- Preenchendo a segunda carta ---\n");
    preencherCarta(&carta2);

    printf("\n--- Exibindo as cartas ---\n");
    printf("\n--- Carta 1 ---\n");
    exibirCarta(carta1);

    printf("\n--- Carta 2 ---\n");
    exibirCarta(carta2);

    // Compara as cartas
    compararCartas(carta1, carta2);

    return 0;
}