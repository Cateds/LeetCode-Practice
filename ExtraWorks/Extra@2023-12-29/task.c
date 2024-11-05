#include <stdio.h>

double function(int n) {
    int i;
    double a[10], t;
    a[0] = 1.0;
    i = 0;
    if (n > 1) {
        for (i = 1; i < n; i++) {
            a[i] = 1./(1+a[i-1]);
        }
    }
    return a[n-1];
}

// double function(int n)
// {
//     if (n==1)
//         return 1;
//     return 1/(1+function(n-1));
// }

int main(void) {
    printf("%f\n",function(5));
    return 0;
}