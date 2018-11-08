#include<stdio.h>
int i=0;
int sum(int n)
{
    if(n==1)return 1;
    else
        return n+sum(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",sum(n));
}

