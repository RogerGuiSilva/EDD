#include <stdio.h>
#include <string.h>
typedef struct{
    char nome[50];
    float n1,n2,n3;
}Aluno;

void imprime(Aluno a[],int i,int total){
    if(i==total) return;
    float m=(a[i].n1+a[i].n2+a[i].n3)/3;
    if(m>6) printf("%s %.2f\n", a[i].nome, m);
    imprime(a,i+1,total);
}

int main(){
    Aluno a[3]={{"Ana",7,8,6},{"Joao",5,4,6},{"Maria",9,8,9}};
    imprime(a,0,3);
    return 0;
}
