#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],n,i,j,num,id=0;
    puts("Enter total Number of element:");
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>num;
        if(i==0)
            a[i]=num;
        else
        {
            a[i]=num;
            for(j=i;j>0;j--)
            {
               if(a[j]<a[j-1])
               {
                 swap(a[j],a[j-1]);
               }
               else
               {
                   break;
               }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

