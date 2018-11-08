#include<bits/stdc++.h>
using namespace std;
//assume element is 5
int par[6];
void makeset(int n)
{
    par[n]=n;
}
int find_cr(int n)
{
    if(par[n]==n)return n;
    else
    {
      par[n]=find_cr(par[n]);//DP
      return par[n];  //if i only write return find_cr(par[n]);time complexity o(n)
    }
}
void want_frnd(int a, int b)
{
    int u,v;
    u = find_cr(a);
    v = find_cr(b);
    if(u==v)
        cout<<"they are already friend"<<endl;
    else
        par[u]=v;//or par[v]=u;
}

int main()
{
    int i,j,k,n=5;
    for(i=1;i<=5;i++)//assume total element 5
        makeset(i);
    while(1)
    {
        cin>>j>>k;
        want_frnd(j,k);
    }
}
