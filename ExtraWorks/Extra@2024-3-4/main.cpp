#include<stdio.h>

int main () {
    int a,b,c,d,e,m1,m2,m,n1,n2,n ;
    printf("请输入要判断的五个不同数字：\n");
    scanf("%d,%d,%d,%d,%d",&a,&b,&c,&d,&e);
    if (a>b) {
        if (c>a){
            m1=c, n1=b;
        }
        else if (b>c){
            m1=a, n1=c;
        }
        else if (a>c && c>b){
            m1=a,n1=b;
        }
    }
    else {
        if (c>b){
            m1=c; n1=a;
        }
        else if (a>c){
            m1=b, n1=c;
        }
        else if (a<c && c<b) {
            m1=b, n1=a;
        }
    }
    if (d>e) {
        m2=d, n2=e;
    }
    else {
        m2=e, n2=d;
    }
    if (m1>m2) {
        m=m1;
    }
    else {
        m=m2;
    }
    if (n1<n2) {
        n=n1;
    }
    else {
        n=n2;
    }
    printf("这组数的最大值为：%d\n最小值为：%d",m,n);
    return 0;
}