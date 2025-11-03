#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Função principal que organiza o fluxo do jogo
int main() {
    // Bibliotecas necessárias: utilizar srand(time(NULL)) para garantir aleatoriedade
    srand(time(NULL));
    
    Territorio* mapa = NULL; // Ponteiro para o início do vetor alocado
    int num_territorios = 0;
    
    printf("---------------------------------------------------\n");
    printf("  WAR - NIVEL AVENTUREIRO: ATAQUE E ALOCACAO DINAMICA\n");
    printf("---------------------------------------------------\n");
    
    // Alocação de memória: pede o numero total de territorios
    printf("Quantos territorios voce deseja cadastrar? (Minimo 2): ");
    if (scanf("%d", &num_territorios) != 1 || num_territorios < 2) {
        printf("Numero de territorios invalido. Encerrando o programa.\n");
        return 1;
    }
    while(getchar() != '\n'); 
    
    // CADASTRO (Alocação Dinâmica)
    mapa = cadastrar_territorios(num_territorios);
    if (mapa == NULL) {
        return 1; // Encerra se a alocação falhar
    }

    // Loop principal para ataques
    int idx_atacante, idx_defensor;
    char continuar;
    
    do {
        // mostra o mapa no início de cada turno
        exibir_mapa(mapa, num_territorios);
        
        // orienta o jogador sobre quais territórios
        printf("\n--- TURNO DE ATAQUE ---\n");
        
        // Recebe indices do atacante
        printf("Digite o INDICE do Territorio ATACANTE (0 a %d): ", num_territorios - 1);
        if (scanf("%d", &idx_atacante) != 1 || idx_atacante < 0 || idx_atacante >= num_territorios) {
            printf("Indice de atacante invalido.\n");
            while(getchar() != '\n'); 
            continue;
        }

        // Recebe indices do defensor
        printf("Digite o INDICE do Territorio DEFENSOR (0 a %d): ", num_territorios - 1);
        if (scanf("%d", &idx_defensor) != 1 || idx_defensor < 0 || idx_defensor >= num_territorios) {
            printf("Indice de defensor invalido.\n");
            while(getchar() != '\n');
            continue;
        }
        
        // Evita que um território ataque a si mesmo
        if (idx_atacante == idx_defensor) {
            printf("Um territorio nao pode atacar a si mesmo.\n");
            continue;
        }

        // ATAQUE (Uso de Ponteiros)
        // Chama a função de ataque, passando os ponteiros para os elementos do vetor
        // O endereço do elemento é &mapa[índice]
        atacar(&mapa[idx_atacante], &mapa[idx_defensor]);
        
        // Pergunta se deseja continuar
        printf("\nDeseja realizar outro ataque? (s/n): ");
        while(getchar() != '\n'); // Limpa buffer
        scanf(" %c", &continuar); // Espaço antes de %c para ignorar espaços em branco
        
    } while (continuar == 's' || continuar == 'S');
    
    // LIBERAÇÃO DE MEMÓRIA (Gerenciamento de memória)
    liberar_memoria(mapa);
    
    printf("\nPROGRAMA FINALIZADO.\n");
    return 0;
}