#include<stdio.h>
int NCR(int n, int r)
{
    if(r==1)return n;
    if(n==r)return 1;
    return NCR(n-1,r)+NCR(n-1,r-1);
}
int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    printf("%d\n",NCR(n,r));
    return 0;
}
