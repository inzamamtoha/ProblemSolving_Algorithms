#include<bits/stdc++.h>

using namespace std;
main()
{
    int mid,high,low,x,n,i,index;
    int a[10]={2,3,1,6,9,4,7,8,2,4};
    sort(a,a+10);
        index=-1;
    low=0;
    high=10-1;
    cin>>x;
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
    cout<<low<<endl;
    return 0;
}

