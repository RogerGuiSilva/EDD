#include <stdio.h>
void maiorMenor(int v[],int i,int *maior,int *menor){
    if(i==0){
        *maior=*menor=v[0];
        return;
    }
    maiorMenor(v,i-1,maior,menor);
    if(v[i]>*maior) *maior=v[i];
    if(v[i]<*menor) *menor=v[i];
}
int main(){
    int v[10]={12,45,2,89,33,7,21,90,1,56};
    int maior,menor;
    maiorMenor(v,9,&maior,&menor);
    printf("%d %d", maior, menor);
    return 0;
}
