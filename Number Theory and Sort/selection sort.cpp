#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define pi acos(-1)
#define sf scanf
#define pf printf
#define ll long long int
using namespace std;
int main()
{
    //freopen("1.txt","r",stdin);
    int a[100],n,i,j,temp;
    puts("How many numbers please enter");
    sf("%d",&n);
    for(i=0;i<n;i++)
    {
        sf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp= a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    puts("After sorting: ");
    for(i=0;i<n;i++)
    {
        pf("%d ",a[i]);
    }
    return 0;
}

