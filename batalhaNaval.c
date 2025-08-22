#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10
#define TAMANHONAVIO 3

int checarSeCabeNoTabuleiro(int i);
void exibirTabuleiro(int matriz[LINHAS][COLUNAS]);
void colocarNavioHorizontal(int navioHorizontal[2], int tabuleiro[LINHAS][COLUNAS]);
void colocarNavioVertical(int navioVertical[2], int tabuleiro[LINHAS][COLUNAS]);

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[LINHAS][COLUNAS];
    int navioHorizontal[2] = {1, 6};
    int navioVertical[2] = {2, 4};

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    colocarNavioHorizontal(navioHorizontal, tabuleiro);
    colocarNavioVertical(navioVertical, tabuleiro);
    exibirTabuleiro(tabuleiro);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}

void colocarNavioHorizontal(int navioHorizontal[2], int tabuleiro[10][10]){
    for (int i = 0; i < TAMANHONAVIO; i++)
    {
        if (!checarSeCabeNoTabuleiro(navioHorizontal[0] + i) || !checarSeCabeNoTabuleiro(navioHorizontal[1] + i))
        {
            printf("Navio horizontal viola os limites do tabuleiro");
            return;
        }
        else if(tabuleiro[navioHorizontal[0]][navioHorizontal[1] + i] == 3)
        {
            printf("Erro ao colocar navio horizontal: Está sobrepondo outro navio!");
            return;
        }
        else{
              tabuleiro[navioHorizontal[0]][navioHorizontal[1] + i] = 3;
        }
    }
}

void colocarNavioVertical(int navioVertical[2], int tabuleiro[10][10]){
     for (int i = 0; i < TAMANHONAVIO; i++)
     {
         if (!checarSeCabeNoTabuleiro(navioVertical[0] + i) || !checarSeCabeNoTabuleiro(navioVertical[1] + i))
        {
            printf("Navio vertical viola os limites do tabuleiro");
            return;
        }
        else if(tabuleiro[navioVertical[0]+i][navioVertical[1]] == 3)
        {
            printf("Erro ao colocar navio vertical: Está sobrepondo outro navio!");
            return;
        }
        else{
            tabuleiro[navioVertical[0]+i][navioVertical[1]] = 3;
        }
    }
}

void exibirTabuleiro(int tabuleiro[10][10])
{
    printf("\n====================== TABULEIRO NÍVEL NOVATO ======================\n\n");

    const char colunas[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Espaço antes de começar as colunas para alinhar com o tabuleiro no terminal
    printf("   ");

    // Exibição das letras representando as colunas
    for(int i = 0; i < COLUNAS; i++){
        printf("%c ", colunas[i]);
    }

    printf("\n");

    for (int i = 0; i < LINHAS; i++)
    {
        // Condicional apenas para adicionar, ou não, um espaço no começo das linhas, para alinhar as linhas 1 a 9 com a linha 10
        if (i < 9)
        {
            printf(" %d ", i + 1);
        }
        else
        {
            printf("%d ", i + 1);
        }

        for (int j = 0; j < COLUNAS; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int checarSeCabeNoTabuleiro(int i)
{
    if (i < 0 || i > 9)
    {
        return 0;
    }

    return 1;
}
