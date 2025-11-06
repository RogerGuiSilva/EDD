#include <stdio.h>
#include <string.h>

#define NUM_JOGADORES 35
#define NUM_CAMPEONATOS 2
#define NUM_CRITERIOS 5

int main() {
	
    char nomes[NUM_JOGADORES][50];
    
    int desempenho[NUM_CAMPEONATOS][NUM_JOGADORES][NUM_CRITERIOS];
    
    char* nomes_campeonatos[NUM_CAMPEONATOS] = {"Campeonato Brasileiro", "Copa do Brasil"};
    char* criterios[NUM_CRITERIOS] = {"Gols Marcados", "Passes Certos", "Passes Errados", "Desarmes", "Assistências"};

    
    printf("Digite os nomes dos 35 jogadores:\n");
    
    for (int i = 0; i < NUM_JOGADORES; i++) {
    	
        printf("Jogador %d: ", i + 1);
        
        fgets(nomes[i], 50, stdin);
        
        nomes[i][strcspn(nomes[i], "\n")] = '\0'; 
    }

    
    for (int camp = 0; camp < NUM_CAMPEONATOS; camp++) {
    	
        printf("\n--- %s ---\n", nomes_campeonatos[camp]);
        
        for (int i = 0; i < NUM_JOGADORES; i++) {
            printf("\nDesempenho do jogador %s:\n", nomes[i]);
            
            for (int crit = 0; crit < NUM_CRITERIOS; crit++) {
            	
                printf("%s: ", criterios[crit]);
                
                scanf("%d", &desempenho[camp][i][crit]);
            }
        }
    }

    
    for (int camp = 0; camp < NUM_CAMPEONATOS; camp++) {
    	
        printf("\nRELATÓRIO - %s\n", nomes_campeonatos[camp]);
        
        for (int i = 0; i < NUM_JOGADORES; i++) {
        	
            printf("\nJogador: %s\n", nomes[i]);
            
            for (int crit = 0; crit < NUM_CRITERIOS; crit++) {
            	
                printf("%s: %d\n", criterios[crit], desempenho[camp][i][crit]);
            }
        }
    }

    return 0;
}

