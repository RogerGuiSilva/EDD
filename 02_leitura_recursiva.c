#include <stdio.h>
void leitura(){
     int n;
      scanf("%d",&n);
      if(n >= 0){
        printf("%d\n", n);
         leitura();
    }
}
    int main(){
        leitura();
      return 0;
}
