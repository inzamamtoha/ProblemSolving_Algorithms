#include<bits/stdc++.h>
using namespace std;
#define mx 1000
int nod,edg;
int L[mx];///level
int Tab[mx][22];///sparse table
int Prnt[mx];///parent
vector<int>edge[mx];
int color[mx];
void dfs_visit(int par,int u,int lev)
{
	int i,v,j,k;
	color[u]=0;
	L[u]=lev;
	if(lev==0)
		Prnt[u]=-1;
	else
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
			if(Tab[i][j-1] != -1)
			{
		/// 2^16 th parent of a node is 2^8 th parent of 2^8 parent of that node
				Tab[i][j] = Tab[Tab[i][j-1]][j-1];
			}
		}
	}
}
int query_lca(int p,int q)
{
	int i,j,k,level=1;
	if(L[p]<L[q])
	{
		swap(p,q);///now p is greater than q
	}
	while(1)///find the level of p
	{
		i=level+1;
		if((1<<i)>L[p])
			break;
		level++;
	}
	for(i=level;i>=0;i--)///p go to same level of q
	{
		if(L[p]-(1<<i)>=L[q])
		{
			p=Tab[p][i];
		}
	}
	if (p==q)///p and q is same node
	{
		return p;
	}
	for (i =level; i >= 0; i--)///p and q different node & find lca
	{
		if (Tab[p][i] != -1 && Tab[p][i] != Tab[q][i])
		{
			p = Tab[p][i];
			q = Tab[q][i];
		}
	}
      return Prnt[p];
}
int main()
{
	//freopen("test.cpp","r",stdin);
    int i,j,k,m,n,x,y;
	cin>>nod>>edg;


	for(i=0;i<edg;i++)
	{
		cin>>x>>y;
		edge[x].push_back(y);
		//edge[y].push_back(x);
	}
	dfs();
	build_lca();

	cout<<query_lca(5,6)<<endl;
	for(i=0;i<nod;i++)
	{
		edge[i].clear();
	}
    return 0;
}
