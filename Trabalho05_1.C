//Roger Guilherme Da Silva
#include <stdio.h>
#include <string.h>

#define MAX 5

struct jogador
{
    char nome[30];
    int pontuacao;
};
typedef struct jogador Jogador;

int main()
{
    Jogador jogadores[MAX];
    char resultado[MAX][MAX];
    int lin, col, valor, maiorPontuacao;

    for(lin = 0; lin < MAX; lin++)
    {
        do
        {
            printf("\nDigite o nome do jogador %d: ", lin + 1);

            fflush(stdin);

            fgets(jogadores[lin].nome, sizeof(jogadores[lin].nome), stdin);
            jogadores[lin].nome[strcspn(jogadores[lin].nome, "\n")] = '\0';

            if (strlen(jogadores[lin].nome) < 3) {
                printf("O nome precisa ter pelo menos uns 3 caracteres.\n");
            }
        }
        while(strlen(jogadores[lin].nome) < 3);

        jogadores[lin].pontuacao = 0;
    }

    for(lin = 0; lin < MAX; lin++)
    {
        for(col = 0; col < MAX; col++)
        {
            if(lin < col)
            {
                printf("\nPartida entre %s e %s: ", jogadores[lin].nome, jogadores[col].nome);
                printf("\n\t1) Vitoria de %s", jogadores[lin].nome);
                printf("\n\t2) Empate");
                printf("\n\t3) Vitoria de %s", jogadores[col].nome);

                do
                {
                    printf("\nDigite 1, 2 ou 3: ");
                    scanf("%d", &valor);

                    fflush(stdin);
                }
                while(valor != 1 && valor != 2 && valor != 3);

                switch(valor)
                {
                    case 1:
                        resultado[lin][col] = 'V';
                        resultado[col][lin] = 'D';
                        break;
                    case 2:
                        resultado[lin][col] = 'E';
                        resultado[col][lin] = 'E';
                        break;
                    case 3:
                        resultado[lin][col] = 'D';
                        resultado[col][lin] = 'V';
                        break;
                }
            }
            else if(lin == col)
            {
                resultado[lin][col] = 'x';
            }
        }
    }

    maiorPontuacao = 0;
    printf("\n\n--- Pontuacao Final ---\n");
    for(lin = 0; lin < MAX; lin++)
    {
        jogadores[lin].pontuacao = 0;

        for(col = 0; col < MAX; col++)
        {
            if(lin != col)
            {
                if(resultado[lin][col] == 'V')      jogadores[lin].pontuacao += 10;
                else if(resultado[lin][col] == 'E') jogadores[lin].pontuacao += 5;
                else                                jogadores[lin].pontuacao += 1;
            }
        }
        printf("Pontos de %s: %d\n", jogadores[lin].nome, jogadores[lin].pontuacao);

        if(lin == 0 || jogadores[lin].pontuacao > maiorPontuacao)
        {
            maiorPontuacao = jogadores[lin].pontuacao;
        }
    }

    printf("\n----------------------------------\n");
    printf("Campeão!!!!!:\n");
    for(lin = 0; lin < MAX; lin++)
    {
        if(jogadores[lin].pontuacao == maiorPontuacao)
        {
            printf(">>> %s com %d pontos!\n", jogadores[lin].nome, maiorPontuacao);
        }
    }
    printf("----------------------------------\n");

    return 0;
}
