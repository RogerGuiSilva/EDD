//Roger Guilherme Da Silva
// CV3096611
#include <stdio.h>

int main() {
    int matriz[4][4];      
    int LN;                 
    int totalLN = 0;        
    int CL;                 
    int totalCL = 0;        

    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    
    printf("\nMatriz:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 4; i++) {
        LN = 1; 
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] != 0) {
                LN = 0;  
            }
        }
        if (LN == 1) {
            totalLN++;  
        }
    }

    
    for (int j = 0; j < 4; j++) {
        CL = 1; 
        for (int i = 0; i < 4; i++) {
            if (matriz[i][j] != 0) {
                CL = 0;  
            }
        }
        if (CL == 1) {
            totalCL++;
        }
    }
    printf("\nLinhas nulas: %d\n", totalLN);
    printf("Colunas nulas: %d\n", totalCL);

    return 0;
}

