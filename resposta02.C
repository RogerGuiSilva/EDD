//Roger Guilherme Da Silva
// CV3096611
#include <stdio.h>

int main() {
    int r;
    int matriz[10][10];
    int i, j;

    printf("Digite o tamanho: ");
    scanf("%d", &r);

    printf("Digite os elementos:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < r; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int somaLinha, somaColuna, somaDiagonal1 = 0, somaDiagonal2 = 0;
    int magico = 1;
    int somaReferencia = 0;
    for(j = 0; j < r; j++) {
        somaReferencia += matriz[0][j];
    }
    for(i = 0; i < r; i++) {
        somaLinha = 0;
        for(j = 0; j < r; j++) {
            somaLinha += matriz[i][j];
        }
        if(somaLinha != somaReferencia) {
            magico = 0;
        }
    }
    for(j = 0; j < r; j++) {
        somaColuna = 0;
        for(i = 0; i < r; i++) {
            somaColuna += matriz[i][j];
        }
        if(somaColuna != somaReferencia) {
            magico = 0;
        }
    }
    for(i = 0; i < r; i++) {
        somaDiagonal1 += matriz[i][i];
        somaDiagonal2 += matriz[i][r - 1 - i];
    }
    if(somaDiagonal1 != somaReferencia || somaDiagonal2 != somaReferencia) {
        magico = 0;
    }
    if(magico) {
        printf("É um quadrado mágico!\n");
    } else {
        printf("Não é um quadrado mágico.\n");
    }

    return 0;
}

