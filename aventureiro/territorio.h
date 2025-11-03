#ifndef TERRITORIO_H
#define TERRITORIO_H

// Constantes para tamanhos máximos de strings
#define TAM_MAX_NOME 30
#define TAM_MAX_COR 10

// Struct atualizada: utiliza a struct Territorio com os campos char nome[30], char cor[10], int tropas.
typedef struct {
    char nome[TAM_MAX_NOME];
    char cor[TAM_MAX_COR];
    int tropas;
} Territorio;

#endif 