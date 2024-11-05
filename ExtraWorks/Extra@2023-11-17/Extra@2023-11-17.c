#include <stdio.h>

int main(void) {
    int n;
    int nums[100] = {0};
    int order[333] = {0}, order_size = 0;
    int count = 0;
    int i;
    int input;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &input);
        if (nums[input-1]++ == 0)
            order[order_size++] = input;
    }
    for (i=0; i<order_size; i++)
        if (nums[order[i]-1]>=3) {
            printf("%d ",order[i]);
            count++;
        }
    if (!count)
        printf("No");
}