#include <stdio.h>
void conta(int v[],int i,int *p,int *im){
    if(i<0) return;
    if(v[i]%2==0) (*p)++;
    else (*im)++;
    conta(v,i-1,p,im);
}
int main(){
    int v[10]={1,2,3,4,5,6,7,8,9,10};
    int p=0,im=0;
    conta(v,9,&p,&im);
    printf("%d %d", p, im);
    return 0;
}
