#include <stdio.h>
#include <string.h>

int main(void) {
    char *name[4] = {"Java","Basical","windows","TurboC++"};
    int n = 4;
    for (int a = 0; a < n - 1; a++) {
        for (int b = a + 1; b < n; b++) {
            if (strcmp(name[a], name[b]) < 0) {
                char *temp = name[a];
                name[a] = name[b];
                name[b] = temp;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        printf("%s\n", name[i]);
    }
}