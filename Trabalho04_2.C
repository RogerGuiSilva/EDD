//Roger Guilherme da Silva
#include <stdio.h>
#include <string.h>

#define ALUNOS 35
#define DISCIPLINAS 6

int main() {
	
    char alunos[ALUNOS][50];   
	      
    char disciplinas[DISCIPLINAS][50]; 
    
    float notas[ALUNOS+1][DISCIPLINAS+1]; 
    
    int i, j;

   
    printf("cadastro do %d aluno:\n", ALUNOS);
    
    	for(i = 0; i < ALUNOS; i++) {
    		
        printf("digite o nome do aluno %d: ", i+1);
        
        scanf(" %[^\n]", alunos[i]); 
}

   
    printf("\ncadastro das %d disciplinas:\n", DISCIPLINAS);
    for(i = 0; i < DISCIPLINAS; i++) {
        int repetido;
        
        do 
		{
            repetido = 0;
            printf("digite a disciplina %d: ", i+1);
            scanf(" %[^\n]", disciplinas[i]);

           
            for(j = 0; j < i; j++)
			 {
               			 if(strcmp(disciplinas[i], disciplinas[j]) == 0)
							 {
               			 	
                    printf("voce ja escreveu essa disciplina.\n");
                    repetido = 1;
}

}

			} while(repetido);
}

    
    for(i = 0; i < ALUNOS; i++) {
    	
       		 printf("\nNotas do aluno %s:\n", alunos[i]);
        for(j = 0; j < DISCIPLINAS; j++)
        
		 {
            printf("digite a nota em %s: ", disciplinas[j]);
         scanf("%f", &notas[i][j]);
}

}

   
    for(i = 0; i < ALUNOS; i++)
	 {
        float soma = 0;
        for(j = 0; j < DISCIPLINAS; j++) {
            soma += notas[i][j];
}
        notas[i][DISCIPLINAS] = soma / DISCIPLINAS; 
}


    for(j = 0; j < DISCIPLINAS; j++) {
    	
        float soma = 0;
        
        for(i = 0; i < ALUNOS; i++) {
        	
            soma += notas[i][j];
        }
        notas[ALUNOS][j] = soma / ALUNOS; 
}

    
    printf("\Relatorio final\n");
    
    printf("%-15s", "Aluno");
    for(j = 0; j < DISCIPLINAS; j++) {
    	
        printf("%-10s", disciplinas[j]);
}
    printf("media\n");

    for(i = 0; i < ALUNOS; i++) {
    	
        printf("%-15s", alunos[i]);
        
        for(j = 0; j <= DISCIPLINAS; j++) {
        	
            printf("%-10.2f", notas[i][j]);
        }
        printf("\n");
}

   
   
    printf("%-15s", "medias");
    
    
    for(j = 0; j < DISCIPLINAS; j++) {
    	
        printf("%-10.2f", notas[ALUNOS][j]);
}
    printf("\n");

    return 0;
}

