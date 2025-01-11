#include <stdio.h>
#include <math.h>

int main(void) {
    int x,y,n;
    scanf("%d %d %d",&x,&y,&n);
    int max = pow(10,n);
    int count = 1;
    for (int i=0; i<y; i++) {
        count *= x;
        count %= max;
    }
    int capacity=0;
    for (int i=count; i!=0; i/=10)
        capacity++;
    for (int i=0; i<n-capacity; i++)
        putchar('0');
    printf("%d",count);
}