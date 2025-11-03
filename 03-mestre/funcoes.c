#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Vetor de strings contendo as descrições das missões
char* MISSOES[] = {
    "Dominar 4 territorios no total.",                     
    "Ter mais de 10 tropas em um unico territorio.",       
    "Eliminar todas as tropas da cor Vermelha.",           
    "Conquistar o territorio Brasil (indice 0 no cadastro).", 
    "Dominar 6 territorios no total."                     
};
const int TOTAL_MISSOES = 5;


// Alocação dinâmica de territórios
Territorio* cadastrar_territorios(int num_territorios) {
    Territorio* mapa = (Territorio*)calloc(num_territorios, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro na alocacao de memoria para o mapa.\n");
        return NULL;
    }

    printf("\n--- INÍCIO DO CADASTRO ---\n");
    for (int i = 0; i < num_territorios; i++) {
        printf("\nCadastro do Territorio %d de %d:\n", i + 1, num_territorios);
        
        printf("Nome: ");
        scanf("%29s", (mapa + i)->nome);
        
        printf("Cor do exercito (Ex: Verde, Azul): ");
        scanf("%9s", (mapa + i)->cor);

        printf("Tropas (min 1): ");
        if (scanf("%d", &(mapa + i)->tropas) != 1 || (mapa + i)->tropas < 1) {
            printf("Valor invalido para tropas. Usando 1 por padrao.\n");
            (mapa + i)->tropas = 1;
        }

        while(getchar() != '\n');
    }
    printf("--- CADASTRO CONCLUIDO ---\n");
    return mapa;
}

// Exibição do mapa
void exibir_mapa(Territorio* mapa, int num_territorios) {
    printf("\n--------------------------------------\n");
    printf("  MAPA DE GUERRA ATUAL (Total: %d)\n", num_territorios);
    printf("--------------------------------------\n");

    for (int i = 0; i < num_territorios; i++) {
        printf("[%d] %s | Dono: %s | Tropas: %d\n", 
               i, (mapa + i)->nome, (mapa + i)->cor, (mapa + i)->tropas);
    }
    printf("--------------------------------------\n");
}

// Simulação de Ataque (Ponteiros e Passagem por Referência)
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\n[ERRO] Voce nao pode atacar um territorio da sua propria cor (%s).\n", atacante->cor);
        return;
    }
    
    if (atacante->tropas < 2) {
        printf("\n[ATAQUE INVALIDO] %s precisa de pelo menos 2 tropas para atacar.\n", atacante->nome);
        return;
    }

    int dado_ataque = (rand() % 6) + 1;
    int dado_defesa = (rand() % 6) + 1;

    printf("\n--- SIMULACAO DE ATAQUE ---\n");
    printf("ATACANTE (%s) dado: %d\n", atacante->nome, dado_ataque);
    printf("DEFENSOR (%s) dado: %d\n", defensor->nome, dado_defesa);
    
    if (dado_ataque > dado_defesa) {
        printf("\n[VITORIA DO ATAQUE] %s venceu a batalha!\n", atacante->nome);
        
        defensor->tropas -= 1;
        printf("%s perdeu 1 tropa. Tropas restantes: %d\n", defensor->nome, defensor->tropas);
        
        if (defensor->tropas == 0) {
            printf("\n[CONQUISTA] %s conquistou o territorio %s!\n", atacante->nome, defensor->nome);
            
            // Atualização de campos: transfere cor e metade das tropas
            strcpy(defensor->cor, atacante->cor);
            
            int tropas_a_mover = atacante->tropas / 2;
            if (tropas_a_mover < 1) tropas_a_mover = 1;

            atacante->tropas -= tropas_a_mover;
            defensor->tropas = tropas_a_mover;

            printf("  -> Novo dono: %s\n", defensor->cor);
            printf("  -> Tropas movidas: %d\n", tropas_a_mover);
        }
    } else {
        printf("\n[VITORIA DA DEFESA] %s defendeu com sucesso!\n", defensor->nome);
        atacante->tropas -= 1;
        printf("%s perdeu 1 tropa. Tropas restantes: %d\n", atacante->nome, atacante->tropas);
    }
}

// Sorteio da missão (Passagem por Referência)
void atribuir_missao(char* destino, char* missoes[], int totalMissoes) {
    int indice_sorteado = rand() % totalMissoes;
    strcpy(destino, missoes[indice_sorteado]);
}

// Exibe a missão (Passagem por Valor)
void exibir_missao(const char* missao_jogador) {
    printf("\n[SUA MISSAO ATUAL] Objetivo: %s\n", missao_jogador);
    printf("-----------------------------------------\n");
}

// Verificação da missão (Lógica de Condição de Vitória)
int verificar_missao(const char* missao, Territorio* mapa, int tamanho) {
    // Para simplificar, o jogador testado é o que tem a cor 'Verde'
    const char* cor_jogador_teste = "Verde"; 
    int count_jogador_territorios = 0;
    int max_tropas = 0;
    
    // Contagem de estatísticas atuais
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(mapa[i].cor, cor_jogador_teste) == 0) {
            count_jogador_territorios++;
        }
        if (mapa[i].tropas > max_tropas) {
            max_tropas = mapa[i].tropas;
        }
    }

    // LÓGICAS DE VERIFICAÇÃO (strstr para encontrar a missão no texto)
    
    // Dominar 4 territorios no total.
    if (strstr(missao, "Dominar 4 territorios no total") != NULL) {
        if (count_jogador_territorios >= 4) {
            return 1;
        }
    }
    
    //Dominar 6 territorios no total.
    if (strstr(missao, "Dominar 6 territorios no total") != NULL) {
        if (count_jogador_territorios >= 6) {
            return 1;
        }
    }

    //Ter mais de 10 tropas em um unico territorio.
    if (strstr(missao, "Ter mais de 10 tropas em um unico territorio") != NULL) {
        if (max_tropas > 10) {
            return 1;
        }
    }
    
    //Eliminar todas as tropas da cor Vermelha.
    if (strstr(missao, "Eliminar todas as tropas da cor Vermelha") != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Vermelha") == 0) {
                return 0; // Ainda há tropas Vermelhas
            }
        }
        return 1; // Nenhuma tropa Vermelha restante
    }
    
    //Conquistar o territorio Brasil (assumindo indice 0)
    if (strstr(missao, "Conquistar o territorio Brasil") != NULL) {
        if (tamanho > 0 && strcmp(mapa[0].cor, cor_jogador_teste) == 0) {
             return 1;
        }
    }

    return 0; // Missão não cumprida
}

// Liberação de Memória
void liberar_memoria(Territorio* mapa, char* missao_jogador) {
    if (mapa != NULL) {
        free(mapa);
        printf("\n[MEMORIA LIBERADA] Espaco do mapa liberado.\n");
    }
    
    if (missao_jogador != NULL) {
        free(missao_jogador);
        printf("[MEMORIA LIBERADA] Espaco da missao liberado.\n");
    }
}