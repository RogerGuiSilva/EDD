#include <stdio.h>
void pesquisa(int v[],int x,int i){
    if(i<0){
        printf("Nao encontrado");
        return;
    }
    if(v[i]==x){
        printf("Encontrado");
        return;
    }
    pesquisa(v,x,i-1);
}
int main(){
    int v[5]={1,3,5,7,9};
    int x;
    scanf("%d",&x);
    pesquisa(v,x,4);
    return 0;
}
