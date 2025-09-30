#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

// Enumeração para facilitar a manipulação dos atributos
typedef enum {
    DENSIDADE = 1,
    PIB_PER_CAPITA = 2,
    AREA = 3,
    PIB = 4,
    POPULACAO = 5,
    PONTOS_TURISTICOS = 6
} Atributos;

// Body das string 
typedef struct {
    float Area;
    float PIB;
    float DencidadePopulacional;
    float PibPercapita;
    float Super;
    char estado[30];
    char codigoCarta[30];
    char cidade[30];
    int populacao;
    int PontosTuristicos;
    int estoque;
} cartas;

// Função para exibir as cartas
void exibircartas(cartas C1) {
    printf("Estado:%s\n", C1.estado);
    printf("Codigo da Carta:%s\n", C1.codigoCarta);
    printf("Nome da cidade:%s\n", C1.cidade);
    printf("População:%d\n", C1.populacao);
    printf("Área:%.2f\n", C1.Area);
    printf("PIB:%.2f\n", C1.PIB);
    printf("Pontos Turisticos:%d\n", C1.PontosTuristicos);
    printf("Dencidade Populacional:%.2f\n", C1.DencidadePopulacional);
    printf("PIB per Capita:%.2f\n", C1.PibPercapita);
    printf("------------------------------------\n");
}

void Prenchercartas(cartas *C2) {
    char Pncs[50];
    
    printf("Escolha seu estado: \n");
    fgets(Pncs, sizeof(Pncs), stdin);
    Pncs[strcspn(Pncs, "\n")] = 0;
    strcpy(C2->estado, Pncs);

    printf("Coloque um codigo para a carta(Ex:RJ01)\n");
    scanf("%s", C2->codigoCarta); 
    while (getchar() != '\n');

    printf("Escolha o nome da sua cidade: \n");
    fgets(Pncs, sizeof(Pncs), stdin);
    Pncs[strcspn(Pncs, "\n")] = 0;
    strcpy(C2->cidade, Pncs);

    printf("Qual é a população da sua cidade?: \n");
    scanf("%d", &C2->populacao); 
    while (getchar() != '\n');

    printf("Qual é aa Área da sua cidade?: \n");
    scanf("%f", &C2->Area); 
    while (getchar() != '\n');

    printf("Qual é o PIB da sua cidade: \n");
    scanf("%f", &C2->PIB); 
    while (getchar() != '\n');
    
    printf("Quantos pontos turisticos tem na sua cidade?: \n");
    scanf("%d", &C2->PontosTuristicos); 
    while (getchar() != '\n');

    // Calculos da Densidade e Área
    if (C2->Area > 0) { 
        C2->DencidadePopulacional = (float)C2->populacao / C2->Area;
    } else {
        C2->DencidadePopulacional = 0.0;
    }

    if (C2->populacao > 0) {
        C2->PibPercapita = C2->PIB / C2->populacao;
    } else {
        C2->PibPercapita = 0.0;
    }
}

// Funções de comparação para o menu
float getValorAtributo(cartas *carta, Atributos atributo) {
    switch (atributo) {
        case DENSIDADE:
            return carta->DencidadePopulacional;
        case PIB_PER_CAPITA:
            return carta->PibPercapita;
        case AREA:
            return carta->Area;
        case PIB:
            return carta->PIB;
        case POPULACAO:
            return carta->populacao;
        case PONTOS_TURISTICOS:
            return carta->PontosTuristicos;
        default:
            return 0.0;
    }
}

// Função para obter o nome do atributo
const char* getNomeAtributo(Atributos atributo) {
    switch (atributo) {
        case DENSIDADE:
            return "Densidade Populacional";
        case PIB_PER_CAPITA:
            return "PIB Per Capita";
        case AREA:
            return "Area";
        case PIB:
            return "PIB";
        case POPULACAO:
            return "Populacao";
        case PONTOS_TURISTICOS:
            return "Pontos Turisticos";
        default:
            return "Desconhecido";
    }
}

// Lógica de comparação avançada
void compararAtributos(cartas carta1, cartas carta2, Atributos atributo1, Atributos atributo2) {
    float valor1_1 = getValorAtributo(&carta1, atributo1);
    float valor2_1 = getValorAtributo(&carta2, atributo1);
    float valor1_2 = getValorAtributo(&carta1, atributo2);
    float valor2_2 = getValorAtributo(&carta2, atributo2);

    // Comparação do primeiro atributo
    printf("\n--- Comparando por %s ---\n", getNomeAtributo(atributo1));
    printf("Carta 1 (%s): %.2f\n", carta1.cidade, valor1_1);
    printf("Carta 2 (%s): %.2f\n", carta2.cidade, valor2_1);
    
    if (atributo1 == DENSIDADE) {
        if (valor1_1 < valor2_1) printf("Carta 1 vence!\n");
        else if (valor2_1 < valor1_1) printf("Carta 2 vence!\n");
        else printf("Empate!\n");
    } else {
        if (valor1_1 > valor2_1) printf("Carta 1 vence!\n");
        else if (valor2_1 > valor1_1) printf("Carta 2 vence!\n");
        else printf("Empate!\n");
    }
    
    // Comparação do segundo atributo
    printf("\n--- Comparando por %s ---\n", getNomeAtributo(atributo2));
    printf("Carta 1 (%s): %.2f\n", carta1.cidade, valor1_2);
    printf("Carta 2 (%s): %.2f\n", carta2.cidade, valor2_2);
    
    if (atributo2 == DENSIDADE) {
        if (valor1_2 < valor2_2) printf("Carta 1 vence!\n");
        else if (valor2_2 < valor1_2) printf("Carta 2 vence!\n");
        else printf("Empate!\n");
    } else {
        if (valor1_2 > valor2_2) printf("Carta 1 vence!\n");
        else if (valor2_2 > valor1_2) printf("Carta 2 vence!\n");
        else printf("Empate!\n");
    }

    // Soma e comparação final
    float soma1 = valor1_1 + valor1_2;
    float soma2 = valor2_1 + valor2_2;
    printf("\n--- Comparando por Soma Total ---\n");
    printf("Soma Carta 1: %.2f\n", soma1);
    printf("Soma Carta 2: %.2f\n", soma2);
    
    if (soma1 > soma2) printf("\nA Carta 1 (%s) vence a rodada!\n", carta1.cidade);
    else if (soma2 > soma1) printf("\nA Carta 2 (%s) vence a rodada!\n", carta2.cidade);
    else printf("\nEmpate na rodada!\n");
}


int main() {
    cartas carta1, carta2;
    int opcao1, opcao2;

    printf("--- Preenchendo a primeira carta ---\n");
    Prenchercartas(&carta1);
    printf("\n--- Preenchendo a segunda carta ---\n");
    Prenchercartas(&carta2);
    
    // Menu dinâmico
    do {
        printf("\n--- Escolha o PRIMEIRO atributo para comparar ---\n");
        printf("1. Densidade Populacional\n");
        printf("2. PIB Per Capita\n");
        printf("3. Area\n");
        printf("4. PIB\n");
        printf("5. Populacao\n");
        printf("6. Pontos Turisticos\n");
        printf("Sua opcao: ");
        scanf("%d", &opcao1);
        while (getchar() != '\n'); 

        if (opcao1 < 1 || opcao1 > 6) {
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao1 < 1 || opcao1 > 6);

    do {
        printf("\n--- Escolha o SEGUNDO atributo para comparar ---\n");
        printf("1. Densidade Populacional\n");
        printf("2. PIB Per Capita\n");
        printf("3. Area\n");
        printf("4. PIB\n");
        printf("5. Populacao\n");
        printf("6. Pontos Turisticos\n");
        printf("Sua opcao: ");
        scanf("%d", &opcao2);
        while (getchar() != '\n'); 

        if (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1) {
            printf("Opcao invalida ou ja escolhida. Tente novamente.\n");
        }
    } while (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1);
    
    // Chama a função de comparação com os dois atributos escolhidos
    compararAtributos(carta1, carta2, (Atributos)opcao1, (Atributos)opcao2);

    return 0;
}   CompararCartas(carta1, carta2);

    return 0;
}