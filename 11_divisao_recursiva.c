#include <stdio.h>
int divi(int x,int y){
    if(y==0) return -1;
    if(x<y) return 0;
    return 1 + divi(x-y,y);
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d\n", divi(x,y));
    return 0;
}
