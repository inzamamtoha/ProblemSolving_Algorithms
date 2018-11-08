#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,k;
    double u,v,s,temp;
    puts("Enter u & v & s:");
    cin>>u>>v>>s;
    if(u<v)
    {
        temp=u;
        u=v;
        v=temp;
    }
    double low =0.0,high,mid,m,n;
    high = s;
    while(high-low>=0.0000000001)
    {
        mid=(double)(high+low)/2.0;
       //cout<<mid<<" "<<low<<" "<<high<<endl;
        m=(double)mid/v;
        n=(double)(s-mid)/u;
        if(m==n)
        {
            break;
        }
        else if(m<n)
        {
            low=mid;
        }
        else
        {
            high = mid;
        }
    }
    printf("%lf\n",mid);
    main();
    return 0;
}


