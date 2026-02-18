#include <stdio.h>
void binario(int n){
    if(n>0){
        binario(n/2);
        printf("%d", n%2);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    binario(n);
    return 0;
}
