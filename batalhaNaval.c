#include <stdio.h>

#define TAM 10 //define os dados do tabuleiro

void exibirTabuleiro(int tabuleiro[TAM][TAM])
{
    printf("\n=== TABULEIRO ===\n");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio(int tabuleiro[TAM][TAM], int x, int y, int tamanho, char orientacao)
{
    printf("\nCoordenadas do navio (%c):\n", orientacao);
    for (int i = 0; i < tamanho; i++)
    {
        if (orientacao == 'H')
        { // Horizontal
            if (y + i < TAM)
            {
                tabuleiro[x][y + i] = 1;
                printf("(%d, %d)\n", x, y + i);
            }
        }
        else if (orientacao == 'V')
        { // Vertical
            if (x + i < TAM)
            {
                tabuleiro[x + i][y] = 1;
                printf("(%d, %d)\n", x + i, y);
            }
        }
        else if (orientacao == 'D')
        { // Diagonal principal
            if (x + i < TAM && y + i < TAM)
            {
                tabuleiro[x + i][y + i] = 1;
                printf("(%d, %d)\n", x + i, y + i);
            }
        }
    }
}

int main()
{
    int tabuleiro[TAM][TAM] = {0};
    int x, y, tamanho;
    char orientacao;

    printf("=== BATALHA NAVAL ===\n");
    printf("O tabuleiro eh 10x10 (coordenadas de 0 a 9).\n");
    printf("Orientacoes: H = Horizontal, V = Vertical, D = Diagonal principal\n");

    // Posicionar 3 navios
    // Escolha o tamanho ds navios
    // Escolha a posição dos navios
    for (int n = 1; n <= 3; n++)
    {
        printf("\nDigite a coordenada inicial do navio %d (x y): ", n);
        scanf("%d %d", &x, &y);
        printf("Digite o tamanho do navio %d: ", n);
        scanf("%d", &tamanho);
        printf("Digite a orientacao do navio %d (H/V/D): ", n);
        scanf(" %c", &orientacao);

        posicionarNavio(tabuleiro, x, y, tamanho, orientacao);
    }

    // Mostrar tabuleiro completo
    exibirTabuleiro(tabuleiro);

    return 0;
}