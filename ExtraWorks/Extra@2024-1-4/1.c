#include <stdio.h>
#include <string.h>

int main(void) {
    int ans = 0;
    char input[100];
    gets(input);
    char *token = strtok(input," ");
    while (token!=NULL) {
        ans++;
        token = strtok(NULL," ");
    }
    printf("%d",ans);
}