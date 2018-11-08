#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,k,n;
    puts("Enter two number k & n :");
    cin>>k>>n;

    double low =0.0,high,mid,j;
    high = n;
    while(high-low>=0.0000000001)
    {
        mid=(double)(high+low)/2.0;
       //cout<<mid<<" "<<low<<" "<<high<<endl;
       j=pow(mid,k);
        if(j==n)
        {
            break;
        }
        else if(j<n)
        {
            low=mid;
        }
        else
        {
            high = mid;
        }
    }
    printf("%lf\n",mid);
    return 0;
}
