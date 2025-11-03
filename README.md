# 🌍 EstruturaDeDados-WarC: Projeto de Simulação do Jogo War em C

## 🎯 Visão Geral do Projeto

Este projeto é uma implementação da base lógica do clássico jogo de estratégia **War** utilizando a linguagem **C**. O objetivo principal é aplicar e demonstrar o domínio de conceitos fundamentais de **Estruturas de Dados**, **Modularização** e **Gerenciamento de Memória** (alocação dinâmica e ponteiros).

---

## 🚀 Status do Desenvolvimento 

| Nível | Status | Conceitos Aplicados |
| :--- | :--- | :--- |
| **Novato** | ✅ Concluído | Definição de `structs` (`Territorio`), Vetor de `structs`, Entrada e Saída de Dados. |
| **Aventureiro** | 🚧 Em Andamento | 🚧 Em Andamento |
| **Mestre** | 🚧 Em Andamento | 🚧 Em Andamento |

---

## 🧱 Estrutura de Dados Utilizada

### `Territorio` (Struct)

O elemento central do mapa é a struct `Territorio`, definida para encapsular as informações necessárias:

```c
typedef struct {
    char nome[30];          // Nome geográfico do território.
    char cor[10];           // Cor do jogador que domina o território.
    int tropas;             // Quantidade de exércitos alocados.
} Territorio;