#include "stdio.h"
#include "stdbool.h"
#include "math.h"

int main(void) {
    long long n;
    scanf("%lld",&n);
    int num[20], num_n=0;
    int times[20] = {0};
    long long n_temp = n;
    for (int i=2; i<=n_temp; i++) {
        bool isPrime = !(n_temp%i);
        while (n_temp%i==0) { 
            n_temp/=i;
            times[num_n] += 1;
        }
        if (isPrime) {
            num[num_n] = i;
            num_n++;
        }
    }
    long long count = 1;
    for (int i=0; i<num_n; i++) {
        count *= pow(num[i],times[i])-pow(num[i],times[i]-1);
    }
    for (int i=0; i<num_n; i++) {
        printf("%d %d\n",num[i], times[i]);
    }
    printf("%lld",count);
}