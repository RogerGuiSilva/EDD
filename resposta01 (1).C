#include <stdio.h>

// Roger Guilherme Da Silva

int main () {
	
	float valorBruto[30],valorLiquido[30];
	int vaganaGaragem[30];
	int i;


 for(i = 0; i < 30; i++) {
        printf("Digite o valor do seu AP %d: ", i + 1);
        scanf("%f", &valorBruto[i]);
         printf("Digite o numero de vagas na sua garagem %d: ", i + 1);
        scanf("%d", &vaganaGaragem[i]);
    }


 	for(i = 0; i < 30; i++) {
 		if (vaganaGaragem[i] == 0 || vaganaGaragem[i]== 1)  {
 			valorLiquido[i] = valorBruto[i];
 	}
 	
 	else if (vaganaGaragem[i] == 2 || vaganaGaragem[i] ==3) {
 		valorLiquido[i] = valorBruto[i] *1.10;
	 }
	 
	 else{
	 	valorLiquido[i] = valorBruto[i] *1.20;
	 }
 }

 for (i=0; i< 30; i++) {
 	 printf ("apartamento %d:\n", i + 1);
 	 printf ("valor bruto: %.2f\n", valorBruto[i]);
 	 printf ("vagas na garagem: %d\n", vaganaGaragem[i]);
 	 printf ("valor liquido: %.2f\n\n", valorLiquido[i]);
 	
 }
}

