#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int lower(int a[],int x)
{
    int high,mid,low,i,j,k,index;
    index=-1;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x==a[mid])
        {
            index=mid;
            high=mid-1;
        }
        else if(a[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return index;
}
int upper(int a[],int x)
{
    int high,mid,low,i,j,k,index;
    index=-1;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x==a[mid])
        {
            index=mid;
            low=mid+1;
        }
        else if(x<a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return index;
}
main()
{
    int a[100001],mid,high,low,x,y,i,t,j,p,l,u;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n>>p;
        for(j=0;j<n;j++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        while(p--)
        {
            cin>>x>>y;
            l= lower(a,x);
            u=upper(a,y);
            cout<<l<<" "<<u<<endl;
        }

    }
    return 0;
}


