#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
set<int>apoint;
set<int>::iterator it;
int nod,edg,color[1000],dt[1000],ft[1000],tim = 0,prev[1000],low[1000],root;
void dfs_visit(int u)
{
    color[u]=0;///gray
    tim =tim+1;
    dt[u]=tim;
    low[u]=dt[u];
    int child=0;
    for(int i=0;i<edge[u].size();i++)
    {
        int v = edge[u][i];
        if(color[v]== -1)///tree edge
        {
            prev[v]= u;
            child++;
            dfs_visit(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dt[u]&& prev[u]!=-1)
            {
                apoint.insert(u);
            }
            if(child>1 && prev[u]== -1)
            {
                apoint.insert(u);
            }
        }
        if(color[v]==0 && prev[u]!=v )///back edge
        {
            low[u]=min(low[u],dt[v]);
        }
    }
    color[u]=1;///black
    tim =tim+1;
    ft[u]=tim;
}
void dfs()
{
    int i,j;
    for(i=0;i<=nod;i++)
    {
        color[i]=-1;///white
        dt[i]=-1;
        ft[i]= -1;
        prev[i]=-1;
        low[i]=-1;
    }
    root = 0;
    for(i=0;i<nod;i++)
    {
        if(color[i]== -1)
        {
            dfs_visit(i);
        }
    }
}
int main()
{
    int i,x,y;
    scanf("%d %d",&nod,&edg);
    while(edg--)
    {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs();
    for(it=apoint.begin();it!=apoint.end();it++)
    {
        printf("%d\n",*it);
    }
    for(i=0;i<=nod;i++)
        edge[i].clear();
    return 0;
}
