#include <stdio.h>
#include <stdlib.h>
int main(void) {
    //Input
    int input[200];
    int size = 0;
    do {
        scanf("%d",&input[size]);
        size ++;
    } while (getchar()!='\n');

    // Sort
    for (int i=1; i<size; i++) {
        int temp = input[i];
        int j=i;
        while (j>0 && input[j-1]>temp) {
            input[j] = input[j-1];
            j--;
        }
        input[j] = temp;
    }

    // Merge
    int *L = input;
    int *R = &input[size-1];
    int *Ans = malloc(size * sizeof(int));
    int Ans_size = 0;
    while (R-L >= 0) {
        Ans[Ans_size++] = *L;
        if (R!=L)
            Ans[Ans_size++] = *R;
        L++; R--;
    }

    // Print
    for (int i=0; i<Ans_size; i++) {
        printf("%d ",Ans[i]);
    }
}