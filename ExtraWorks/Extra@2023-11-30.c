#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num) {
    if (num<2) return false;
    else if (num==2) return true;
    else {
        for (int i=2; i<=num/i+1; i++)
            if (!(num%i)) return false;
        return true;
    }
}

bool isSexyPrime(unsigned num) {
    return isPrime(num-6) || isPrime(num+6);
}
int main(void) {
    int input;
    scanf("%d",&input);
    if (isSexyPrime(input)) {
        printf("Yes\n");
        printf("%d\n",isPrime(input-6)?(input-6):(input+6));
    }
    else {
        printf("No\n");
        do {
            input++;
        } while (!isSexyPrime(input));
        printf("%d\n",input);
    }
}