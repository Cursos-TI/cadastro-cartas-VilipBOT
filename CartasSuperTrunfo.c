#include <stdio.h>
#include <string.h>

//Body das string
typedef struct {
    float Area;
    float PIB;
    float DencidadePopulacional;
    float PibPercapita;
    float Super;
    char estado [30];
    char codigoCarta[30];
    char cidade [30];
    int populacao;
    int PontosTuristicos;
    int estoque;
} cartas;

//Função para exibir as cartas
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
    
    
    while (getchar() != '\n'); 

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
    
    printf("Quantos pontos turistico tem na sua cidade?: \n");
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

void CompararCartas(cartas C3, cartas C4) {
    printf("---...Comparando as Cartas...--- \n");

    printf("Carta 1 (%s): %.2f \n", C3.cidade, C3.DencidadePopulacional);
    printf("Carta 2 (%s): %.2f \n", C4.cidade, C4.DencidadePopulacional);

    if (C3.DencidadePopulacional > C4.DencidadePopulacional) {
        printf("\nA Carta 1 (%s) Vence a carta 2(%s)!\n", C3.cidade, C4.cidade);
    } else if (C4.DencidadePopulacional > C3.DencidadePopulacional) {
        printf("\nA Carta 2 (%s) Vence a carta 1(%s)!\n", C4.cidade, C3.cidade);
    } else {
        printf("\nEmpate DE Ambas as Cartas!!.\n");
    }
}

int main() {
    cartas carta1, carta2;

    printf("--- Preenchendo a primeira carta ---\n");
    Prenchercartas(&carta1);

    printf("\n--- Preenchendo a segunda carta ---\n");
    Prenchercartas(&carta2);

    printf("\n--- Exibindo as cartas ---\n");
    printf("\n--- Carta 1 ---\n");
    exibircartas(carta1);

    printf("\n--- Carta 2 ---\n");
    exibircartas(carta2);
    
    CompararCartas(carta1, carta2);

    return 0;
}