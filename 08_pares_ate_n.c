#include <stdio.h>
void pares(int n){
    if(n>0) pares(n-2);
    printf("%d ",n);
}
int main(){
    int n;
    scanf("%d",&n);
    pares(n);
    return 0;
}
