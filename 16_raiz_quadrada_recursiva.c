#include <stdio.h>
#include <math.h>
double raiz(double x,double r,double t){
    if(fabs(x - r*r) <= t) return r;
    return raiz(x, (x/r + r)/2, t);
}
int main(){
    double x;
    scanf("%lf",&x);
    printf("%.5lf", raiz(x,x/2,0.0001));
    return 0;
}
