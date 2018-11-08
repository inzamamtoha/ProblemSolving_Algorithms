#include<bits/stdc++.h>
#define pie acos(-1)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ss(st) scanf("%s",st)
#define sch(ch) scanf("%c",&ch)
#define pi(a) printf("%d",a)
#define pii(a,b) printf("%d %d",a,b)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define pl(a) printf("%lld",a)
#define pll(a,b) printf("%lld %lld",a,b)
#define plll(a,b,c) printf("%lld %lld %lld",a,b,c)
#define ps(st) printf("%s",st)
#define pch(c) printf("%c",c)
#define debug(n) printf("toha %d\n",n)
#define debug1(n) printf("saran %d\n",n)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define NL puts("")
#define SP printf(" ")
#define LL long long int
#define ULL unsigned long long int
#define N 5007
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
/********************************************************************/
struct node
{
	int nd,cst;
	node(){}
	node(int _nd,int _cst)
	{
		nd =_nd;
		cst = _cst;
	}
	bool operator < (const node & a)const
	{
		return cst>a.cst;
	}
};
struct node temp,tp;
vector<node>edge[N];
int nod,edg;
int dis[N],par[N];

void dijkstra(int source)
{
    int u,v,w,i,j;

    for(i=0;i<=nod;i++)
    {
		dis[i]=INF;
		par[i]=-1;
    }

    dis[source]=0;
    priority_queue<node>pq;
    pq.push(node(source,0));
    while(!pq.empty())
    {
		tp = pq.top();
		pq.pop();
        u = tp.nd;
        for(i=0;i<edge[u].size();i++)
        {
			v = edge[u][i].nd;
			w = edge[u][i].cst;
			if(dis[v] > dis[u]+w)
			{
				dis[v]=dis[u]+w;
				par[v]=u;
				pq.push(node(v,dis[v]));
			}

        }

    }
}
int main()
{
    //freopen("test.cpp","r",stdin);
	//freopen("1.txt","w",stdout);
	int t,cs,i,j,k,x,y,c;
	si(t);
	for1(cs,t)
	{
		sii(nod,edg);
		for0(i,edg)
		{
			siii(x,y,c);
			edge[x].pub(node(y,c));
			edge[y].pub(node(x,c));

		}
		dijkstra(1);
		if(dis[nod]==INF)
		{
			printf("Case %d: Impossible\n",cs);
		}
		else
		{
			printf("Case %d: %d\n",cs,dis[nod]);
		}
		for(i=0;i<=nod;i++)
		{
			edge[i].clear();
		}
	}
    return 0;
}

