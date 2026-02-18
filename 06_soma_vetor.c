#include <stdio.h>
    int soma(int v[],int i,int f){
    if(i==f) return v[f];
    return v[i] + soma(v,i+1,f);
}
int main(){
    int v[10]={1,2,3,4,5,6,7,8,9,10};
        printf("%d\n", soma(v,0,9));
        return 0;
}
