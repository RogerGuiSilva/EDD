#include <stdio.h>
int triangular(int n){
    if(n==1) return 1;
    return n + triangular(n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d", triangular(n));
    return 0;
}
