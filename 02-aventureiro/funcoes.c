#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

// Alocação dinâmica de territórios: utiliza calloc para alocar memória
Territorio* cadastrar_territorios(int num_territorios) {
    // Aloca um vetor de Territorio com tamanho 'num_territorios'
    // Usa calloc para garantir que a memória seja inicializada com zeros
    Territorio* mapa = (Territorio*)calloc(num_territorios, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro na alocacao de memoria para o mapa.\n");
        return NULL;
    }

    printf("\n--- INÍCIO DO CADASTRO ---\n");
    for (int i = 0; i < num_territorios; i++) {
        printf("\nCadastro do Territorio %d de %d:\n", i + 1, num_territorios);

        // Uso de ponteiros: Acesso aos membros da struct via ponteiro
        // *(mapa + i) é o mesmo que mapa[i]
        
        printf("Nome: ");
        scanf("%29s", (mapa + i)->nome);
        
        printf("Cor do exercito (Jogador): ");
        scanf("%9s", (mapa + i)->cor);

        printf("Tropas (min 1): ");
        if (scanf("%d", &(mapa + i)->tropas) != 1 || (mapa + i)->tropas < 1) {
            printf("Valor invalido para tropas. Usando 1 por padrao.\n");
            (mapa + i)->tropas = 1;
        }

        while(getchar() != '\n'); // Limpa buffer
    }
    printf("--- CADASTRO CONCLUIDO ---\n");
    return mapa;
}

// Implementação: Exibição
void exibir_mapa(Territorio* mapa, int num_territorios) {
    printf("\n---------------------------------------\n");
    printf("  MAPA DE GUERRA ATUAL (Total: %d)\n", num_territorios);
    printf("---------------------------------------\n");

    for (int i = 0; i < num_territorios; i++) {
        // Exibição pós-ataque: o sistema deve exibir os dados atualizados
        printf("[%d] %s | Dono: %s | Tropas: %d\n", 
               i, (mapa + i)->nome, (mapa + i)->cor, (mapa + i)->tropas);
    }
    printf("---------------------------------------\n");
}


// IMPLEMENTAÇÃO: Simulação de Ataque

// Função de ataque: utiliza rand() para simular dados de batalha
void atacar(Territorio* atacante, Territorio* defensor) {
    // Valida as escolhas de ataque para que o jogador não ataque um território da própria cor.
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\n[ERRO] Voce nao pode atacar um territorio da sua propria cor (%s).\n", atacante->cor);
        return;
    }
    
    // O atacante precisa de pelo menos 2 tropas para atacar (1 para atacar, 1 fica)
    if (atacante->tropas < 2) {
        printf("\n[ATAQUE INVALIDO] %s precisa de pelo menos 2 tropas para atacar.\n", atacante->nome);
        return;
    }

    // Gerar um dado aleatório para o atacante e o defensor (1 a 6)
    int dado_ataque = (rand() % 6) + 1;
    int dado_defesa = (rand() % 6) + 1;

    printf("\n--- SIMULACAO DE ATAQUE ---\n");
    printf("ATACANTE (%s) dado: %d\n", atacante->nome, dado_ataque);
    printf("DEFENSOR (%s) dado: %d\n", defensor->nome, dado_defesa);
    
    if (dado_ataque > dado_defesa) {
        // ATACANTE VENCE
        printf("\n[VITORIA DO ATAQUE] %s venceu a batalha!\n", atacante->nome);
        
        // Atualização de dados: se o defensor perder, ele perde 1 tropa.
        defensor->tropas -= 1;
        printf("%s perdeu 1 tropa. Tropas restantes: %d\n", defensor->nome, defensor->tropas);
        
        // Se as tropas do defensor chegarem a zero: Ocorre a Conquista!
        if (defensor->tropas == 0) {
            printf("\n[CONQUISTA] %s conquistou o territorio %s!\n", atacante->nome, defensor->nome);
            
            // Atualização de dados: o território defensor deve mudar de dono (cor do exército)
            strcpy(defensor->cor, atacante->cor);
            
            // Atualização dos campos: transfira metade das tropas (mínimo de 1)
            int tropas_a_mover = atacante->tropas / 2;
            if (tropas_a_mover < 1) tropas_a_mover = 1;

            atacante->tropas -= tropas_a_mover;
            defensor->tropas = tropas_a_mover; // O novo dono começa com as tropas movidas

            printf("  -> Novo dono: %s\n", defensor->cor);
            printf("  -> Tropas movidas: %d\n", tropas_a_mover);
        }
    } else {
        // DEFENSOR VENCE (ou empata)
        printf("\n[VITORIA DA DEFESA] %s defendeu com sucesso!\n", defensor->nome);
        
        // Se o atacante perder: perde uma tropa.
        atacante->tropas -= 1;
        printf("%s perdeu 1 tropa. Tropas restantes: %d\n", atacante->nome, atacante->tropas);
    }
    
    // Verifica se algum território perdeu todas as tropas no processo
    if (atacante->tropas == 0) {
        printf("\n[ALERTA] %s ficou sem tropas!\n", atacante->nome);
    }
}


// IMPLEMENTAÇÃO: Gerenciamento de Memória


// Gerenciamento de memória: toda memória alocada dinamicamente deve ser liberada 
void liberar_memoria(Territorio* mapa) {
    if (mapa != NULL) {
        free(mapa);
        printf("\n[MEMORIA LIBERADA] Espaco do mapa liberado com sucesso.\n");
    }
}