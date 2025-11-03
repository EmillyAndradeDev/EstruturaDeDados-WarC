#ifndef FUNCOES_H
#define FUNCOES_H

#include "territorio.h"

// função que aloca e preenche o mapa
// Retorna um ponteiro para o vetor de Territorio alocado
Territorio* cadastrar_territorios(int num_territorios);

// função de exibição do mapa
void exibir_mapa(Territorio* mapa, int num_territorios);

// função de ataque
// Simulação de ataques: recebe ponteiros para manipular os dados por referência
void atacar(Territorio* atacante, Territorio* defensor);

// função de liberação de memória
// Gerenciamento de memória: libera o espaço alocado
void liberar_memoria(Territorio* mapa);

#endif 