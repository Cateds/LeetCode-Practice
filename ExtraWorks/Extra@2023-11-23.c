#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int skipNumber[3] = {0};
    int n; scanf("%d",&n);
    for (int i=0; i<=n; i++) {
        bool needSkip = !(i%7);
        for (int j=i; j!=0; j/=10) 
            needSkip = needSkip || j%10==7;
        if (needSkip) skipNumber[(i-1)%3]++;
    }
    printf("%d %d %d",skipNumber[0],skipNumber[1],skipNumber[2]);
    return 0;
}