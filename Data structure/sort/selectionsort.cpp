#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],n,i,j,mn,id;
    puts("Enter total Number of element:");
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        mn=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[mn])
            {
                mn=j;
            }
        }
        swap(a[i],a[mn]);
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}


