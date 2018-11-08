#include<bits/stdc++.h>
using namespace std;
int main()
{
    int high,low,mid,a[1000],i,j,k,n,c=1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    low=0;
    high =n-1;
    cout<<"Enter your Number: "<<endl;
    cin>>k;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==k)
        {
            cout<<"Found"<<endl;
            c=0;
            break;
        }
        else if(a[mid]<k)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(c==1)
    {
        cout<<"Not found!"<<endl;
    }
    return 0;
}
