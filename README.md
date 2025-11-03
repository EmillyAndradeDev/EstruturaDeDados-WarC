# 🌍 EstruturaDeDados-WarC: Projeto de Simulação do Jogo War em C

## 🎯 Visão Geral do Projeto

Este projeto é uma implementação da base lógica do clássico jogo de estratégia **War** utilizando a linguagem **C**. O objetivo principal é aplicar e demonstrar o domínio de conceitos fundamentais de **Estruturas de Dados**, **Modularização** e **Gerenciamento de Memória** (alocação dinâmica e ponteiros).

---

## 🚀 Status do Desenvolvimento 

| Nível | Status | Conceitos Aplicados |
| :--- | :--- | :--- |
| **Novato** | ✅ Concluído | Definição de `structs` (`Territorio`), Vetor de `structs`, Entrada e Saída de Dados. |
| **Aventureiro** | ✅ Concluído | **Alocação Dinâmica** (`calloc`, `free`), **Modularização**, **Ponteiros** (Passagem por Referência), **Lógica de Ataque** (simulação `rand()`). |
| **Mestre** | ✅ Concluído | **Missões Estratégicas** (Alocação Dinâmica, Sorteio, Verificação), **Condição de Vitória**, **Gerenciamento Completo de Memória**. |

---

## ✨ Funcionalidades por Nível

### ✅ Nível Novato

O Nível Novato estabeleceu a base de dados do jogo, focando na organização linear da informação.

* **Definição da Estrutura:** Criação da `struct Territorio` para agrupar dados relacionados (nome, cor, tropas).
* **Armazenamento Estático:** Uso de um vetor de `structs` para cadastrar uma quantidade fixa de territórios.
* **Interface Básica:** Funções de entrada de dados via terminal (`scanf`) e exibição formatada.

### ✅ Nível Aventureiro

O Nível Aventureiro implementou o núcleo do jogo de War, focando em arquitetura e gerenciamento de memória.

* **Mapa Dinâmico:** O número de territórios é definido pelo usuário no início e alocado com `calloc`, garantindo flexibilidade.
* **Ataque Simulado:** Função `atacar()` que simula a rolagem de um dado (1-6) e atualiza as tropas dos territórios **atacante** e **defensor** por meio do uso de **ponteiros** (passagem por referência).
* **Gerenciamento de Memória:** Implementação da função `liberar_memoria()` e uso de `free` ao final do programa.
* **Modularização:** Código separado em `main.c`, `funcoes.c` e arquivos `.h` para melhor organização e manutenibilidade.

### ✅ Nível Mestre

O Nível Mestre introduziu a camada estratégica das missões, culminando na condição de vitória e finalização do jogo.

* **Missões Estratégicas:**
    * **Vetor de Missões:** Definição de um conjunto de missões pré-definidas.
    * **Sorteio Dinâmico:** `atribuir_missao()` sorteia e aloca dinamicamente uma missão para o jogador.
    * **Verificação de Vitória:** `verificar_missao()` avalia o cumprimento do objetivo do jogador.
* **Condição de Vitória:** O jogo verifica a missão a cada turno e declara o vencedor.
* **Gerenciamento Completo de Memória:** A função `liberar_memoria()` gerencia a desalocação do mapa e da missão.
* **Passagem por Valor e Referência:** Uso adequado de ponteiros para manipulação eficiente de dados.

---
## 📁 Estrutura do Projeto (Modularização)

O projeto é organizado em diretórios por nível de complexidade e usa a modularização, separando definições (`.h`) das implementações (`.c`).

```
projeto-war-c/
├── README.md
├── 01-novato/
│   ├── novato_war.c
│   └── war_cadastro.exe
├── 02-aventureiro/
│   ├── funcoes.c
│   ├── funcoes.h
│   ├── main.c
│   ├── territorio.h
│   └── war_aventureiro.exe
└── 03-mestre/
    ├── funcoes.c
    ├── funcoes.h
    ├── main.c
    └── territorio.h
```
---

## ⚙️ Como Compilar e Executar (Nível Novato)

O Nível Novato utiliza um único arquivo, sem modularização.

### 1. Abra o Terminal Integrado no VS Code e navegue até a pasta **```novato```**/:

```bash
cd novato
```

### 2. Compilação do Código

Compile o arquivo único ```novato_war.c```:

```bash
gcc novato_war.c -o war_cadastro
```

### 3. Execução

Execute o programa:

```bash
./war_cadastro.exe
```
O programa solicitará o cadastro de 5 territórios e exibirá a lista.

---

## ⚙️ Como Compilar e Executar (Nível Aventureiro)

Para rodar o projeto, é necessário ter o compilador **GCC** instalado no sistema. O projeto do Nível Aventureiro utiliza modularização (`.c` e `.h`), exigindo que todos os arquivos de implementação sejam compilados juntos.

### 1. Navegação no Terminal

Abra o Terminal Integrado no VS Code e navegue até a pasta **`aventureiro/`**:

```bash
cd aventureiro
```

### 2. Compilação do Código 

Compile todos os arquivos de código-fonte (```main.c``` e ```funcoes.c```) usando o GCC. Isso criará o executável **```war_aventureiro.exe```**.

```bash
gcc main.c funcoes.c -o war_aventureiro
```

### 3. Execução do Programa

Execute o arquivo compilado no terminal:

```bash
./war_aventureiro.exe
```

### 4. Interação

O programa irá solicitar:

    - O número total de territórios a serem cadastrados (mínimo 2).

    - Os dados de nome, cor e tropas para cada território.

    - Repetidamente, os índices do território atacante e defensor para simular as batalhas.

---

## ⚙️ Como Compilar e Executar (Nível Mestre)

O Nível Mestre adiciona missões e condição de vitória, exigindo a compilação de todos os arquivos de implementação.

### 1. Navegação no Terminal

Abra o Terminal Integrado no VS Code e navegue até a nova pasta **`mestre/`**:

```bash
cd mestre
```

### 2. Compilação do Código

Compile todos os arquivos de código-fonte (```main.c``` e ```funcoes.c```). Isso criará o executável **```war_mestre.exe```**.

```bash
gcc main.c funcoes.c -o war_mestre
```

### 3. Execução e Interação

Execute o programa:

```bash
./war_mestre.exe
```

O programa fará o sorteio da missão de vitória no início e, ao final de cada ataque, verificará se você cumpriu o objetivo para declarar o vencedor.