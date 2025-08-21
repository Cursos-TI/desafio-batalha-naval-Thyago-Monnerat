#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    printf("\n====================== TABULEIRO NÍVEL NOVATO ======================\n\n");
    const char colunas[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'} ;
    int tabuleiro[10][10];
    int navioX[2][3] = {{3}, {4,5,6}};
    int navioY[2][3] = {{7,8,9}, {2}};

    printf("   ");

    //printando as letras das colunas
    for(int i = 0; i < COLUNAS; i++){
        printf("%c ", colunas[i]);
    }

    printf("\n");

    //condição para adicionar um navio horizontalmente
    for(int i = 0; i < 3; i++){
        tabuleiro[navioX[0][0]][navioX[1][i]] = 3;
    }

    //condição para adicionar um navio verticalmente
    for(int i = 0; i < 3; i++){
        tabuleiro[navioY[0][i]][navioY[1][0]] = 3;
    }


    for(int i = 0; i < LINHAS; i++){
        //condicional apenas para adicionar, ou não, um espaço no começo das linhas, para alinhar as linhas 1 a 9 com a linha 10
        if(i < 9){
            printf(" %d ", i+1);
        }else{
            printf("%d ", i+1);
        }

        for(int j=0; j < COLUNAS; j++){
            //condição para popular o tabuleiro com 0's sem alterar os navios
            if(tabuleiro[i][j] != 3){
                tabuleiro[i][j] = 0;
            }
                
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

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
