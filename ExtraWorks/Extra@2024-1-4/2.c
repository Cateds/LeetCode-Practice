#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int input[200];
    int size = 0;
    do {
        scanf("%d",&input[size]);
        size ++;
    } while (getchar()!='\n');
    int buffer[200];
    int buffer_size = 0;
    for (int i=0; i<size; i++) {
        if (input[i]!=1) {
            buffer[buffer_size] = input[i];
            buffer_size++;
        }
        else {
            if (i < size-2 && input[i+1]==2 && input[i+2]==3) {
                i += 2;
            }
            else {
                buffer[buffer_size] = input[i];
                buffer_size ++;
            }
        }
    }
    for (int i=0; i<buffer_size; i++) {
        printf("%d ",buffer[i]);
    }
    for (int i=buffer_size; i<size; i++) {
        printf("0 ");
    }
}
