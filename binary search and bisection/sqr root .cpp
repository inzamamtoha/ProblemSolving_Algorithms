#include<bits/stdc++.h>
using namespace std;
double mysqrt(double a)
{
    double low,high,mid,x,y;
    int i,j,k;
    low=0.0;
    high=a;
    while(high-low>.00001)
    {
      mid=(double) (low+high)/2.0;
      if((mid*mid)==a)
      {
          break;
      }
      else if((mid*mid)>a)
      {
        high=mid;
      }
      else if((mid*mid)<a)
      {
          low=mid;
      }
    }
    return mid;
}
int main()
{
    double a;
    cin>>a;
    cout<<mysqrt(a)<<endl;
    return 0;
}
