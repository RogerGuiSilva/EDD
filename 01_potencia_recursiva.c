#include <stdio.h>

int potencia(int base, int expoente){

    if(expoente == 0) return 1;

    return base * potencia(base, expoente-1);
}


int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n", potencia(x,y));
    return 0;
}
