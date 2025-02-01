#include <math.h>
#include <stdio.h>

long gcd(long a, long b) {
    while (b) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long lcm(long a, long b) {
    if (a * b)
        return a * b / gcd(a, b);
    else
        return 0;
}

int main(void) {
    long long length = 343720 * 2, width = 233333 * 2;
    long long dx = 15, dy = 17;
    long long step = lcm(length, dx) / dx;
    printf("step:\t%lld\n", step * dx);
    for (long long i = step; true; i += step) {
        if (i * dy % width)
            continue;
        printf("t:\t\t%lld\n", i);
        printf("length:\t%.2f\n", i * sqrt(dx * dx + dy * dy));
        break;
    }
}
