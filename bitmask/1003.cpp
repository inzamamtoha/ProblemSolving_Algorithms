#include<bits/stdc++.h>
#define pie acos(-1)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ss(st) scanf("%s",st)
#define sch(ch) scanf("%ch",&ch)
#define pi(a) printf("%d",a)
#define pii(a,b) printf("%d %d",a,b)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define pl(a) printf("%lld",a)
#define pll(a,b) printf("%lld %lld",a,b)
#define plll(a,b,c) printf("%lld %lld %lld",a,b,c)
#define ps(st) printf("%s",st)
#define pch(c) printf("%ch",c)
#define debug(n) printf("toha %d\n",n)
#define debug1(n) printf("saran %d\n",n)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define NL puts("")
#define SP printf(" ")
#define LL long long int
#define ULL unsigned long long int
#define N 1000007
#define MOD 100000009
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
using namespace std;
/*********************************************************************/
LL Bigmod(LL b,LL p)
{
    if(p==0)return 1;
    else if(p%2==1)return (b*Bigmod(b,p-1))%MOD;
    else if(p%2==0){
        LL carry = Bigmod(b,p/2);
        return (carry*carry)%MOD;
    }
}
#define white 1
#define gray 0
#define black -1
map<string,int>mymap;
map<string,int>:: iterator it;
vector<int>edge[10001];
LL color[40001],dt[40001],ft[40001],tmm;
void dfs_visit(int u)
{
    int v;
    color[u]=gray;
//    tm=tm+1;
//    dt[u]=tm;
    for(int i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(color[v]==white)
            dfs_visit(v);
        else if(color[v]==gray)
        {
            tmm=1;
            return ;
        }
    }
    color[u]=black;
   // tm= tm+1;
   // ft[u]=tm;
}
void dfs(int node)
{
    for(int i = 1; i<=node ;i++)
    {
        color[i]=white;
        dt[i]=INF;
        ft[i]=INF;
    }
    for(int i=1;i<=node;i++)
    {
        if(tmm==1)
        {
            return ;
        }
        if(color[i]==white)
            dfs_visit(i);
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    LL i,j,k,cas,t,n;
    char a[20],b[20];
    sl(t);
    for1(cas,t)
    {
        sl(n);
        k=1;
        while(n--)
        {
            scanf("%s %s",a,b);
            if(mymap[a]==0)
                mymap[a]=k++;
            if(mymap[b]==0)
                mymap[b]=k++;
            edge[mymap[a]].pub(mymap[b]);
        }
        tmm=0;
        dfs(k-1);

        if(tmm==1)
            printf("Case %lld: No\n",cas);
        else if(tmm==0)
            printf("Case %lld: Yes\n",cas);
        mymap.clear();
        for(i=1;i<k;i++)
            edge[i].clear();
    }
    return 0;
}

