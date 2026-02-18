#include <stdio.h>
void reca(int v[],int i,int f){
    if(i<=f){
        printf("%d ",v[i]);
        reca(v,i+1,f);
    }
}
            void recb(int v[],int i,int f){

                if(i<f) recb(v,i+1,f);
                printf("%d ",v[i]);

            }
    int main(){
        int v[10]={1,2,3,4,5,6,7,8,9,10};
        
        reca(v,0,9);

        printf("\n");
        recb(v,0,9);
        return 0;
    }