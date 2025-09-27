#include <stdio.h>
#include <string.h>


typedef struct {
    char estado[30];
    char nome_cidade[50];
    char codigo_carta[10];
    int populacao;
    float area_km2;
    float pib;
    int numeros_turisticos;
} Carta;

int main() {
    
    Carta minha_carta;
    
   
    char estado_input[30];
    char nome_cidade_input[50];
    char codigo_carta_input[10];

    printf("Escolha seu Estado: \n");
    
  
    fgets(estado_input, sizeof(estado_input), stdin);
    estado_input[strcspn(estado_input, "\n")] = 0;
    strcpy(minha_carta.estado, estado_input);

    printf("Coloque um codigo para a carta (Ex: Rio de Janeiro 'RJ01'): \n");
   
    scanf("%s", codigo_carta_input);
    strcpy(minha_carta.codigo_carta, codigo_carta_input);

    printf("Escolha o nome da sua cidade: \n");
    while (getchar() != '\n'); 
    fgets(nome_cidade_input, sizeof(nome_cidade_input), stdin);
    nome_cidade_input[strcspn(nome_cidade_input, "\n")] = 0;
    strcpy(minha_carta.nome_cidade, nome_cidade_input);

    printf("Quantos pontos turísticos tem na sua cidade? \n");
    scanf("%d", &minha_carta.numeros_turisticos);

    printf("Qual é a população da sua cidade? \n");
    scanf("%d", &minha_carta.populacao);

    printf("Qual é a área em Km² da sua cidade? \n");
    scanf("%f", &minha_carta.area_km2);

    printf("Qual é o PIB da sua cidade? \n");
    scanf("%f", &minha_carta.pib);

    printf("\n--- Carta Criada ---\n");
    printf("Estado: %s\n", minha_carta.estado);
    printf("Codigo da Carta: %s\n", minha_carta.codigo_carta);
    printf("Cidade: %s\n", minha_carta.nome_cidade);
    printf("Populacao: %d\n", minha_carta.populacao);
    printf("Area em Km²: %.2f\n", minha_carta.area_km2);
    printf("PIB: %.2f\n", minha_carta.pib);
    printf("Numeros Turisticos: %d\n", minha_carta.numeros_turisticos);


   
void exibirCarta(Carta c) {
    printf("--------------------------\n");
    printf("Estado: %s\n", c.estado);
    printf("Codigo da Carta: %s\n", c.codigo_carta);
    printf("Cidade: %s\n", c.nome_cidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area em Km²: %.2f\n", c.area_km2);
    printf("PIB: %.2f\n", c.pib);
    printf("Numeros Turisticos: %d\n", c.numeros_turisticos);
}


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
}

    
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

    return 0;
}


