#include<bits/stdc++.h>
#define LL long long
#define N 100007
using namespace std;
/*
//vector<LL>pr;
int pr[sz],sze=0;
int a[N];
void sieve()
{
    int i,j,limit=sqrt(N)+1;
    a[0]=a[1]=1;
    //pr.push_back(2);
    pr[sze++]=2;
    for(i=4;i<=N;i=i+2)
    {
        a[i]=1;
    }
    for(i=3;i<=N;i=i+2)
    {
        if(a[i]==0)
        {
            //pr.push_back(i);
            pr[sze++]=i;
            if(i<=limit)
            {
                for(j=i*i;j<=N;j=j+(i*2))
                {
                    a[j]=1;
                }
            }
        }
    }
}
*/
vector<LL>pr;
int a[N];
void sieve()
{
    int i,j,limit=sqrt(N)+1;
    a[0]=a[1]=1;
    pr.push_back(2);
    for(i=4;i<=N;i=i+2)
    {
        a[i]=1;
    }
    for(i=3;i<=N;i=i+2)
    {
        if(a[i]==0)
        {
            pr.push_back(i);
            if(i<=limit)
            {
                for(j=i*i;j<=N;j=j+(i*2))
                {
                    a[j]=1;
                }
            }
        }
    }
}
LL divisor_count(LL num)
{
    int i,j,cnt=1,exp;
   int sq=sqrt(num)+1;
    for(i=0;pr[i]<=sq;i++)
    {
        exp=0;
        while(num%pr[i]==0)
        {
            exp++;
            num=num/pr[i];
        }
        cnt=cnt*(exp+1);
         sq=sqrt(num)+1;
    }
    if(num>1)
    {
        cnt=cnt*2;
    }
    return cnt;
}
int main()
{
    sieve();
    int n,m=100,i=0;
    while(1)
    {
        cin>>n;
        cout<<divisor_count(n)<<endl;
    }
}
