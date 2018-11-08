#include<stdio.h>
int num,mid;
int binary_search(int a[],int low,int high)
{
    if(low>high)return 0;
    else
    {
        mid=(low+high)/2;
        if(a[mid]<num)
            return binary_search(a,mid+1,high);
        else if(a[mid]==num)
            return 1;
        else
            return binary_search(a,low,mid-1);
    }
}
int main()
{
    int a[10]={2,3,7,8,12,34,56,77,87,88};
    int low=0, high=10,x;
    scanf("%d",&num);
    x=binary_search(a,low,high-1);
     if(x==1)
        puts("Found");
    else
        puts("Not FOund");
}
