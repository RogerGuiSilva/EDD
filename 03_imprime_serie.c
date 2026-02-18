    #include <stdio.h>
    void imprimeSerie(int i,int j,int k){
    if(i <= j){
        printf("%d ", i);
        imprimeSerie(i+k,j,k);
         }
        }
        int main(){
        int i,j,k;
        scanf("%d %d %d",&i,&j,&k);
        imprimeSerie(i,j,k);
        return 0;
            }
