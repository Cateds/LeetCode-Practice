#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *compress(char *src);
int main()
{
    char src[100];
    scanf("%s", src);

    char *ps = compress(src);

    puts(ps);
    return 0;
}

char * compress(char *src) {
    int length = strlen(src);
    char *Ans = malloc(length*sizeof(char));
    char *ptr = Ans;
    int count = 1;
    for (int i=1; i<length; i++)
        if (src[i]==src[i-1])
            count++;
        else {
            *(ptr++) = src[i-1];
            if (count > 1) {
                char num[2] = {0};
                int i=-1;
                for (int n=count; n!=0; n/=10)
                    num[++i] = n%10;
                for (; i>=0; i--)
                    *(ptr++) = num[i] + '0';
            }
            count = 1;
        }
    *(ptr++) = src[length-1];
    if (count > 1) {
        char num[2] = {0};
        int i=-1;
        for (int n=count; n!=0; n/=10)
            num[++i] = n%10;
        for (; i>=0; i--)
            *(ptr++) = num[i] + '0';
    }
    *ptr = '\0';
    return Ans;
}