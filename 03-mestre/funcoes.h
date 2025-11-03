#ifndef FUNCOES_H
#define FUNCOES_H

#include "territorio.h"

Territorio* cadastrar_territorios(int num_territorios);
void exibir_mapa(Territorio* mapa, int num_territorios);
void atacar(Territorio* atacante, Territorio* defensor);

// Atribui uma missão sorteada ao ponteiro destino (passagem por referência)
void atribuir_missao(char* destino, char* missoes[], int totalMissoes);

// Verifica se a missão foi cumprida (Condição de Vitória)
// Recebe a missão por valor (const char*) e o mapa por referência (Territorio*)
int verificar_missao(const char* missao, Territorio* mapa, int tamanho);

// Exibe a missão de um jogador
void exibir_missao(const char* missao_jogador);

// Libera toda a memória alocada dinamicamente (Territórios E Missão)
void liberar_memoria(Territorio* mapa, char* missao_jogador);

#endif