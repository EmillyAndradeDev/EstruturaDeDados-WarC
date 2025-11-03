#include <stdio.h>
#include <string.h> 

typedef struct
{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Definindo a constante para o número de territórios
#define NUM_TERRITORIOS 5

int main()
{
    // Vetor com capacidade para armazenar 5 estruturas do tipo Territorio
    Territorio mapa_de_guerra[NUM_TERRITORIOS];
    int i;

    // Títulos claros
    printf("---------------------------------------------------\n");
    printf("  PROJETO WAR - NOVATO: CADASTRO DE TERRITORIOS  \n");
    printf("---------------------------------------------------\n");

    for (i = 0; i < NUM_TERRITORIOS; i++)
    {
        printf("\n--- Cadastro do Territorio %d de %d ---\n", i + 1, NUM_TERRITORIOS);

        // ENTRADA do NOME
        // Orientação sobre o limite de caracteres.
        printf("Digite o NOME do territorio (maximo 29 caracteres): ");
        if (scanf("%29s", mapa_de_guerra[i].nome) != 1)
        {
            printf("Erro na leitura do nome.\n");
            return 1;
        }

        // ENTRADA da COR
        printf("Digite a COR do exercito (maximo 9 caracteres): ");
        if (scanf("%9s", mapa_de_guerra[i].cor) != 1)
        {
            printf("Erro na leitura da cor.\n");
            return 1;
        }

        // ENTRADA da QUANTIDADE de tropas
        printf("Digite o NUMERO de tropas (inteiro): ");
        if (scanf("%d", &mapa_de_guerra[i].tropas) != 1)
        {
            printf("Erro na leitura das tropas.\n");
            return 1;
        }

        // Limpa o buffer de entrada
        while (getchar() != '\n')
            ;
    }

    printf("\n---------------------------------------------------\n");
    printf("  MAPA DE GUERRA: DADOS DOS TERRITORIOS CADASTRADOS \n");
    printf("---------------------------------------------------\n");

    // 'for' para percorrer o vetor e exibir os dados de cada Territorio
    for (i = 0; i < NUM_TERRITORIOS; i++)
    {
        printf("\n[%d] TERRITORIO: %s\n", i + 1, mapa_de_guerra[i].nome);
        printf("    -> Exercito: %s\n", mapa_de_guerra[i].cor);
        printf("    -> Tropas: %d\n", mapa_de_guerra[i].tropas);
    }

    printf("\n--- FIM DO CADASTRO ---\n");

    return 0;
}