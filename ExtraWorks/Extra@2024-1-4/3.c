#include <stdio.h>
#include <stdbool.h>

bool isLeap(int year) {
    return !(year%400) || year%100 && !(year%4);
}

int main(void) {
    int year,month,days_total;
    scanf("%d%d%d",&year,&month,&days_total);
    int Months[] = {
        31,28,31,30,31,30,31,31,30,31,30
    };
    for (int i=2010; i<year; i++) {
        days_total += 365 + isLeap(i);
    }
    for (int i=1; i<month; i++) {
        days_total += Months[i-1];
    }
    if (month>2)
        days_total += isLeap(year);
    printf("第%d天\n",days_total);
    if ((days_total-1)%5 < 3)
        printf("\t这个人今天打鱼\n");
    else
        printf("\t这个人今天晒网\n");
    return 0;
}