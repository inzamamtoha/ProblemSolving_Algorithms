#include<stdio.h>
int i=0;
int sum(int a[],int n)
{
    if(n==0)return a[0];
    else
        return a[n]+sum(a,n-1);
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,-40};
    int size=10;
    printf("%d\n",sum(a,size-1));
}
