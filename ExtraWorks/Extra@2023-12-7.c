#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int deleteRepeatedNumber(int [], int n);
int main()
{
    int a[20] = {1, 1, 3, 3, 5, 5, 5, 4, 4, 1, 1, 5, 5, 10, 6, 6, 8, 9, 10, 10};
    int count = deleteRepeatedNumber(a,20);
    printf("%d\n",count);
    for (int i=0; i<20; i++) printf("%d ",a[i]);
}
int deleteRepeatedNumber(int *data,int n)
{
    int number_num = 0;
    int *Number_Appeared = malloc(n*sizeof(int));
    for (int i=0; i<n; i++) {
        bool appeared = false;
        for (int j=0; j<number_num; j++)
            if (Number_Appeared[j]==data[i]) appeared = true;
        if (!appeared)
            Number_Appeared[number_num++] = data[i];
    }
    for (int i=0; i<number_num; i++) data[i] = Number_Appeared[i];
    for (int i=number_num; i<n; i++) data[i] = 0;
    free(Number_Appeared);
    return n - number_num;
}