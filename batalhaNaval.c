#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10
#define TAMANHONAVIO 3

void iniciarTabuleiro(int tabuleiro[LINHAS][COLUNAS]);

void mostrarTitulo(char titulo[30]);

int checarSeCabeNoTabuleiro(int i);
void exibirTabuleiro(int matriz[LINHAS][COLUNAS]);
void colocarNavioHorizontal(int navioHorizontal[2], int tabuleiro[LINHAS][COLUNAS]);
void colocarNavioVertical(int navioVertical[2], int tabuleiro[LINHAS][COLUNAS]);
void colocarNavioDiagonalPrincipal(int navioDiagonal[2], int tabuleiro[LINHAS][COLUNAS]);
void colocarNavioDiagonalSecundaria(int navioDiagonal[2], int tabuleiro[LINHAS][COLUNAS]);

void habilidadeCone(int posicaoInicial[2],int tabuleiro[LINHAS][COLUNAS]);
void habilidadeCruz(int posicaoCruz[2], int tabuleiro[LINHAS][COLUNAS]);
void habilidadeOcta(int posicaoOcta[2], int tabuleiro[LINHAS][COLUNAS]);

int main()
{
    int tabuleiro[LINHAS][COLUNAS];

    iniciarTabuleiro(tabuleiro);

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    mostrarTitulo("NÍVEL NOVATO");

    int navioHorizontal[2] = {1, 6};
    int navioVertical[2] = {2, 4};

    colocarNavioHorizontal(navioHorizontal, tabuleiro);
    colocarNavioVertical(navioVertical, tabuleiro);

    exibirTabuleiro(tabuleiro);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    //reiniciando tabuleiro
    iniciarTabuleiro(tabuleiro);

    mostrarTitulo("NÍVEL AVENTUREIRO");

    int navioDiagonalPrincipal[2] = {7, 7};
    int navioDiagonalSecundaria[2] = {7, 2};

    colocarNavioDiagonalPrincipal(navioDiagonalPrincipal, tabuleiro);
    colocarNavioDiagonalSecundaria(navioDiagonalSecundaria, tabuleiro);

    exibirTabuleiro(tabuleiro);

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    //reiniciando tabuleiro
    iniciarTabuleiro(tabuleiro);

    mostrarTitulo("HABILIDADE CONE");
    int posicaoCone[2] = {1, 7};
    habilidadeCone(posicaoCone, tabuleiro);
    exibirTabuleiro(tabuleiro);

    //reiniciando tabuleiro
    iniciarTabuleiro(tabuleiro);
    
    mostrarTitulo("HABILIDADE CRUZ");
    int posicaoCruz[2] = {7,7};
    habilidadeCruz(posicaoCruz, tabuleiro);
    exibirTabuleiro(tabuleiro);

    //reiniciando tabuleiro
    iniciarTabuleiro(tabuleiro);

    mostrarTitulo("HABILIDADE OCTAEDRO");
    int posicaoOcta[2] = {4, 2};
    habilidadeOcta(posicaoOcta, tabuleiro);
    exibirTabuleiro(tabuleiro);

    //reiniciando tabuleiro
    iniciarTabuleiro(tabuleiro);

    mostrarTitulo("FINAL");
    colocarNavioHorizontal(navioHorizontal, tabuleiro);
    colocarNavioVertical(navioVertical, tabuleiro);
    colocarNavioDiagonalPrincipal(navioDiagonalPrincipal, tabuleiro);
    colocarNavioDiagonalSecundaria(navioDiagonalSecundaria, tabuleiro);
    habilidadeCone(posicaoCone, tabuleiro);
    habilidadeCruz(posicaoCruz, tabuleiro);
    habilidadeOcta(posicaoOcta, tabuleiro);
    exibirTabuleiro(tabuleiro);

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

void colocarNavioHorizontal(int navioHorizontal[2], int tabuleiro[LINHAS][COLUNAS]){
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

void colocarNavioVertical(int navioVertical[2], int tabuleiro[LINHAS][COLUNAS]){
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

void colocarNavioDiagonalPrincipal(int navioDiagonal[2], int tabuleiro[LINHAS][COLUNAS]){
    for(int i = 0; i < TAMANHONAVIO; i++){
         if (!checarSeCabeNoTabuleiro(navioDiagonal[0] + i) || !checarSeCabeNoTabuleiro(navioDiagonal[1] + i))
        {
            printf("Navio diagonal principal viola os limites do tabuleiro");
            return;
        }
        else if(tabuleiro[navioDiagonal[0]+i][navioDiagonal[1]+i] == 3)
        {
            printf("Erro ao colocar navio diagonal principal: Está sobrepondo outro navio!");
            return;
        }else{
            tabuleiro[navioDiagonal[0]+i][navioDiagonal[1]+i] = 3;
        }
    }
}

void colocarNavioDiagonalSecundaria(int navioDiagonal[2], int tabuleiro[LINHAS][COLUNAS]){
    for(int i = 0; i < TAMANHONAVIO; i++){
         if (!checarSeCabeNoTabuleiro(navioDiagonal[0] + i) || !checarSeCabeNoTabuleiro(navioDiagonal[1] + i))
        {
            printf("Navio diagonal secundaria viola os limites do tabuleiro");
            return;
        }
        else if(tabuleiro[navioDiagonal[0]+i][navioDiagonal[1]-i] == 3)
        {
            printf("Erro ao colocar navio diagonal secundaria: Está sobrepondo outro navio!");
            return;
        }else{
            tabuleiro[navioDiagonal[0]+i][navioDiagonal[1]-i] = 3;
        }
    }
}   

void habilidadeCone(int posicaoInicial[2], int tabuleiro[LINHAS][COLUNAS])
{
    for(int i = 0; i < 3; i++){
        if (!checarSeCabeNoTabuleiro(posicaoInicial[0] + i) || !checarSeCabeNoTabuleiro(posicaoInicial[1] + i) || !checarSeCabeNoTabuleiro(posicaoInicial[1] + (i-2)))
        {
            printf("Habilidade Cone é maior que o tabuleiro");
            return;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (j >= posicaoInicial[1] - i && j <= posicaoInicial[1] + i)
            {
                tabuleiro[posicaoInicial[0] + i][j] = 1;
            }
        }
    }
}

void habilidadeCruz(int posicaoCentral[2], int tabuleiro[LINHAS][COLUNAS]){
    for(int i = 0; i < 5; i++){
        if (!checarSeCabeNoTabuleiro(posicaoCentral[0] + (i-2)) || !checarSeCabeNoTabuleiro(posicaoCentral[1] + (i-2)))
        {
            printf("Habilidade Cruz é maior que o tabuleiro");
            return;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[posicaoCentral[0] + (i-2)][posicaoCentral[1]] = 1;
            if(j >= posicaoCentral[1] - 2){
                tabuleiro[posicaoCentral[0]][posicaoCentral[1] + (i-2)] = 1;
            }
        }
    }
}

void habilidadeOcta(int posicaoCentral[2], int tabuleiro[LINHAS][COLUNAS]){
    for(int i = 0; i < 5; i++){
        if (!checarSeCabeNoTabuleiro(posicaoCentral[0] + (i-2)) || !checarSeCabeNoTabuleiro(posicaoCentral[1] + (i-2)))
        {
            printf("Habilidade Octaedro é maior que o tabuleiro");
            return;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[posicaoCentral[0] + (i-2)][posicaoCentral[1]] = 1;
            if(j >= posicaoCentral[1] - 2){
                tabuleiro[posicaoCentral[0]][posicaoCentral[1] + (i-2)] = 1;
            }
            if(j >= posicaoCentral[1] - 1 && j <= posicaoCentral[1] + 1){
                if(i > 0 && i < 4){
                    tabuleiro[posicaoCentral[0] + (i-2)][j] = 1;
                }
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS])
{
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

void iniciarTabuleiro(int tabuleiro[LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = 0;
        }
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

void mostrarTitulo(char titulo[30]){
    printf("\n\n");

    for(int i = 0; i < 20; i++){
        printf("/");
    }

    printf(" TABULEIRO %s ", titulo);
    
    for(int i = 0; i < 20; i++){
        printf("/");
    }
    
    printf("\n\n");
}