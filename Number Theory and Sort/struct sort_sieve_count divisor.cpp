#include<bits/stdc++.h>
using namespace std;
int a[1001];
vector<int>pr;
int N=1000;
struct node
{
    int x;
    int y,z;
};
void sieve()
{

    a[0]=a[1]=1;
    pr.push_back(2);
    for(int i=4;i<=N;i=i+2)
    {
        a[i]=1;
    }
    for(int i=3;i<=N;i=i+2)
    {
        if(a[i]==0)
        {
            pr.push_back(i);
            for(int j=i*i;j<=N;j=j+(i*2))
            {
                a[j]=1;
            }
        }
    }
}
int cnt_divsr(int n)
{
    int i,j,k;
    int cnt=1,exp;
    for(i=0;pr[i]<=n;i++)
    {
        exp=0;
        while(n%pr[i]==0)
        {
           exp++;
           n=n/pr[i];
        }
        cnt=cnt*(exp+1);
    }
    return cnt;
}
bool compare(node lhs,node rhs)
{
    if(lhs.y==rhs.y)
    {
        return lhs.x>rhs.x;
    }
    else
        return lhs.y<rhs.y;
}
int main()
{
    int i,j,k,t,n,m=1,cnt=0;
    node div[1001];
    scanf("%d",&t);
    sieve();
    for(i=1;i<=1000;i++)
    {
        if(a[i]==0)
        {
            div[i-1].x=i;
            div[i-1].y=2;
        }
        else
        {
            div[i-1].x=i;
            div[i-1].y=cnt_divsr(i);
        }
    }
    sort(div,div+1000,compare);

    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",i,div[n-1]);

    }
    return 0;

}


