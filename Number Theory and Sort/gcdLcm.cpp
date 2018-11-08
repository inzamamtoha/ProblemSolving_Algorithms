#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);
}
int lcm(int a,int b)
{
    return(a/gcd(a,b))*b;
}
int main()
{
    int a,b;
    while(1)
    {
        cin>>a>>b;
        cout<<gcd(a,b)<<" "<<lcm(a,b)<<endl;
    }
}

