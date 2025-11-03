#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declaração externa do vetor de missões (definido em funcoes.c)
extern char* MISSOES[]; 
extern const int TOTAL_MISSOES;

int main() {
    srand(time(NULL));
    
    Territorio* mapa = NULL;
    char* missao_jogador = NULL; 
    int num_territorios = 0;
    
    printf("--------------------------------------------------\n");
    printf("  WAR - NIVEL MESTRE: MISSOES E VITORIA\n");
    printf("--------------------------------------------------\n");
    
    // Alocação da missão (Armazenamento e acesso)
    missao_jogador = (char*)malloc(TAM_MAX_MISSAO * sizeof(char));
    if (missao_jogador == NULL) {
        printf("Erro na alocacao de memoria para a missao.\n");
        return 1;
    }

    //ATRIBUIÇÃO DA MISSÃO (Passagem por Referência)
    atribuir_missao(missao_jogador, MISSOES, TOTAL_MISSOES);
    
    // Interface intuitiva: exibe a missão apenas uma vez
    exibir_missao(missao_jogador);

    // Entrada do número de territórios
    printf("Quantos territorios voce deseja cadastrar? (Minimo 2): ");
    if (scanf("%d", &num_territorios) != 1 || num_territorios < 2) {
        printf("Numero de territorios invalido. Encerrando o programa.\n");
        liberar_memoria(mapa, missao_jogador);
        return 1;
    }
    while(getchar() != '\n'); 
    
    // CADASTRO (Alocação Dinâmica)
    mapa = cadastrar_territorios(num_territorios);
    if (mapa == NULL) {
        liberar_memoria(mapa, missao_jogador);
        return 1;
    }

    // Loop principal de jogo
    int idx_atacante, idx_defensor;
    char continuar;
    
    do {
        exibir_mapa(mapa, num_territorios);
        
        printf("\n--- TURNO DE ATAQUE ---\n");
        
        // Leitura e validação dos índices
        printf("Digite o INDICE do Territorio ATACANTE (0 a %d): ", num_territorios - 1);
        if (scanf("%d", &idx_atacante) != 1 || idx_atacante < 0 || idx_atacante >= num_territorios) {
            printf("Indice de atacante invalido.\n");
            while(getchar() != '\n'); 
            continue;
        }

        printf("Digite o INDICE do Territorio DEFENSOR (0 a %d): ", num_territorios - 1);
        if (scanf("%d", &idx_defensor) != 1 || idx_defensor < 0 || idx_defensor >= num_territorios) {
            printf("Indice de defensor invalido.\n");
            while(getchar() != '\n');
            continue;
        }
        
        if (idx_atacante == idx_defensor) {
            printf("Um territorio nao pode atacar a si mesmo.\n");
            continue;
        }

        // ATAQUE
        atacar(&mapa[idx_atacante], &mapa[idx_defensor]);
        
        // VERIFICAÇÃO DE VITÓRIA (Exibição condicional)
        if (verificar_missao(missao_jogador, mapa, num_territorios)) {
            printf("\n\n#####################################################\n");
            printf("#               !!! MISSAO CUMPRIDA !!!             #\n");
            printf("#                 VOCÊ VENCEU O JOGO!               #\n");
            printf("#####################################################\n");
            break; // Sai do loop
        }
        
        // Pergunta se deseja continuar
        printf("\nDeseja realizar outro ataque? (s/n): ");
        while(getchar() != '\n'); 
        scanf(" %c", &continuar);
        
    } while (continuar == 's' || continuar == 'S');
    
    // LIBERAÇÃO DE MEMÓRIA
    liberar_memoria(mapa, missao_jogador);
    
    printf("\nPROGRAMA FINALIZADO.\n");
    return 0;
}