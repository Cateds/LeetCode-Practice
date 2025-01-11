#include <stdio.h>

int main(void) {
    FILE *fp = fopen("test.txt","r");
    while (!feof(fp)) {
        char str[10];
        fgets(str,sizeof(str),fp);
        printf("%s",str);
    }
}