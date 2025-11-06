//Roger Guilherme Da Silva
#include <stdio.h>
#include <string.h>

#define MAXFAB 4
#define MAXVEI 3

struct veiculo {
    char modelo[20];
    int cota;
};

int main()
{
    struct veiculo veiculos[MAXVEI];
    char fabricas[MAXFAB][20];
    int producao[MAXVEI][MAXFAB];
    int lin, col;

    printf("Sistema de Gerenciamento Volksgawen\n");

    printf("\nCadastro dos %d Veiculos\n", MAXVEI);
    for (lin = 0; lin < MAXVEI; lin++)
    {
        printf("\nDigite o modelo do veiculo %d: ", lin + 1);
        fgets(veiculos[lin].modelo, 20, stdin);
        veiculos[lin].modelo[strcspn(veiculos[lin].modelo, "\n")] = 0;

        printf("Digite a cota minima para o modelo %s: ", veiculos[lin].modelo);
        scanf("%d", &veiculos[lin].cota);

        fflush(stdin);
    }
    printf("\nVeiculos cadastrados\n");

    printf("\nCadastro das %d Fabricas\n", MAXFAB);
    for (col = 0; col < MAXFAB; col++)
    {
        printf("\nDigite o nome da cidade da fabrica %d: ", col + 1);
        fgets(fabricas[col], 20, stdin);
        fabricas[col][strcspn(fabricas[col], "\n")] = 0;
    }
    printf("\nFabricas cadatradas\n");

    printf("\nCadastro da Producao Anual\n");
    for (lin = 0; lin < MAXVEI; lin++)
    {
        printf("\nVeiculo: %s (Cota Minima: %d)\n", veiculos[lin].modelo, veiculos[lin].cota);
        for (col = 0; col < MAXFAB; col++)
        {
            do
            {
                printf("\t-> Producao em %s: ", fabricas[col]);
                scanf("%i", &producao[lin][col]);

                fflush(stdin);

                if (producao[lin][col] < 0)
                {
                    printf("\tValor invalido\n");
                }
            } while (producao[lin][col] < 0);
        }
    }
    printf("\nProducao cadastrada!\n");

   
    printf("   RELATORIO FINAL DE PRODUCAO ANUAL\n");
   

    for (col = 0; col < MAXFAB; col++)
    {
        printf("\nFabrica: %s\n", fabricas[col]);
        for (lin = 0; lin < MAXVEI; lin++)
        {
            printf("%-10s | Producao: %5i | Meta: %5i | ",
                   veiculos[lin].modelo,
                   producao[lin][col],
                   veiculos[lin].cota);

            if (producao[lin][col] >= veiculos[lin].cota)
            {
                printf("META ATINGIDA!\n");
            }
            else
            {
                printf("NAO ATINGIU A META (Faltaram %i)\n",
                       veiculos[lin].cota - producao[lin][col]);
            }
        }
    }

    printf("\nFIM\n");

    return 0;
}

