#include <stdio.h>
#include <math.h>

int main(void) {
    double pi = atan2(1,0);
    int r,h;
    scanf("%d %d",&r,&h);
    double V = pi * pow(r,2) * h;
    double S = 2 * pi * r * h;
    printf("V:%lf\nS:%lf\n",V,S);
}