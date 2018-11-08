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
#define N 1000007
#define MOD 100000009
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
using namespace std;
/*********************************************************************/
/********************************************************************/
#define mx 100007
int nod,edg;
int L[mx];///level
int Tab[mx][22];///sparse table
int Prnt[mx];///parent
int val[mx];
vector<int>edge[mx];
int color[mx];
void dfs_visit(int par,int u,int lev)
{
	int i,v,j,k;
	color[u]=0;
	L[u]=lev;
	Prnt[u]=par;
	for(i=0;i<edge[u].size();i++)
	{
		v=edge[u][i];
		if(color[v] == -1)
		{
			dfs_visit(u,v,lev+1);
		}

	}
	color[u]=1;
}
void dfs()
{
	int i,j,k;
	memset(color,-1,sizeof(color));
	dfs_visit(0,0,0);///(par,node,level)

}
void build_lca()
{
	int i,j,k;
	memset(Tab,-1,sizeof(Tab));
	for(i=0;i<nod;i++)
	{
		Tab[i][0]=Prnt[i];
	}
	for(j=1;(1<<j)<nod ;j++)
	{
		for(i=0;i<nod;i++)
		{
			if(Tab[i][j] != -1)
			{
		/// 2^16 th parent of a node is 2^8 th parent of 2^8 parent of that node
				Tab[i][j] = Tab[Tab[i][j-1]][j-1];
			}
		}
	}
}
int query_lca(int p,int v)
{
	int i,j,k,level=1;
	while(1)///find the level of p
	{
		i=level+1;
		if((1<<i)>L[p])
			break;
		level++;
	}
//	for(i=level;i>=0;i--)///p go to same level of q
//	{
//		if(L[p]-(1<<i)>=L[q])
//		{
//			p=Tab[p][i];
//		}
//	}
	for (i = level; i >= 0; i--)///p and q different node & find lca
	{
		if (Tab[p][i]!=-1 && val[Tab[p][i]]>=v )
		{
			return 67;
		}
	}
	return p;
}
int main()
{
	freopen("test.cpp","r",stdin);
    int i,j,k,m,n,x,y,t,cs,qry,v;
    si(t);
    for1(cs,t)
    {
		sii(nod,qry);
		edg=nod-1;
		val[0]=1;
		for(i=1;i<=edg;i++)
		{
			sii(x,y);
			edge[x].push_back(i);
			val[i]=y;
			//edge[y].push_back(x);
		}
		dfs();
		build_lca();
		printf("Case %d:\n",cs);
		pi(query_lca(5,2));
			NL;
//		while(qry--)
//		{
//			sii(k,v);
//			pi(query_lca(k,v));
//			NL;
//		}
    }
    return 0;
}


