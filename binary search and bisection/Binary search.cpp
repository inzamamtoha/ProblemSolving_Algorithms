#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[10],mid,high,low,x,i;
    for(i=0;i<4;i++)
    {
        cin>>a[i];
    }
    sort(a,a+i);
    high=4-1;
    low=0;
    mid=(low+high)/2;
    puts("Enter a number to search");
    cin>>x;
    while(low<=high)
    {
        if(a[mid]<x)
        {
            low=mid+1;
        }
        else if(a[mid]==x)
        {
            puts("found");
            break;
        }
        else
        {
            high=mid-1;
        }
        mid=(low+high)/2;
    }
    if(low>high)puts("Not Found");
    return 0;
}
