#include<bits/stdc++.h>
#define N 99999999
#define LL long long int
using namespace std;
vector<LL>pr;
int a[N];
void sieve()
{
    long long int i,j,k=0,limit;
    a[0]=a[1]=true;
    pr.push_back(2);
    limit=sqrt(N);
    for(i=4;i<=N;i=i+2)
    {
        a[i]=true;
    }
    for(i=3;i<=N;i=i+2)
    {
        if(a[i]==false)
        {
            pr.push_back(i);
            if(i<=limit)
            {
                for(j=i*i;j<=N;j=j+(i*2))
                {
                    a[j]=true;
                }
            }
        }
    }
}
int main()
{
    sieve();
    return 0;
}

