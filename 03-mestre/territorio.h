#ifndef TERRITORIO_H
#define TERRITORIO_H

// Constantes para tamanhos máximos de strings
#define TAM_MAX_NOME 30
#define TAM_MAX_COR 10
#define TAM_MAX_MISSAO 150 //Tamanho máximo para a descrição da missão

// Estrutura para representar um Território
typedef struct {
    char nome[TAM_MAX_NOME];
    char cor[TAM_MAX_COR];
    int tropas;
} Territorio;

#endif /