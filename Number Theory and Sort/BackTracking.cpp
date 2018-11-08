#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if(n==1)return 1;
    else
        return n+sum(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<pow(5,3)<<endl;
    cout<<sum(n);
    return 0;
}
