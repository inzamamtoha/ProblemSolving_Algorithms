#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n;
    puts("Enter a number:");
    cin>>n;
    double low =0.0,high,mid;
    high = n;
    while(high-low>=0.0000001)
    {
        mid=(double)(high+low)/2.0;
       // cout<<mid<<" "<<low<<" "<<high<<endl;
        if(mid*mid==n)
        {
            break;
        }
        else if((mid*mid)<n)
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
