#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v;
    bool operator <(const node & p)const
    {
        if(u == p.u)
        {
            return v<=p.v;
        }
        else
            return u<p.u;
    }
}temp;
vector<int>edge[1000];
set<node>apoint;
set<node>::iterator it;
int nod,edg,color[1000],dt[1000],ft[1000],tim = 0,prev[1000],low[1000],root;
void dfs_visit(int u)
{
    color[u]=0;///gray
    tim =tim+1;
    dt[u]=tim;
    low[u]=dt[u];
    for(int i=0;i<edge[u].size();i++)
    {
        int v = edge[u][i];
        if(color[v]== -1)///tree edge
        {
            prev[v]= u;
            dfs_visit(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>dt[u] )
            {
                temp.u=u;
                temp.v=v;
                printf("%d %d\n",u,v);
                apoint.insert(temp);
            }
            /*if(low[v]<low[u])
            {
                low[u]=low[v];
            }*/
        }
        if(color[v]==0 && prev[u]!=v )///back edge
        {
           /* if(dt[v]<low[u])
            {
                low[u]=dt[v];
            }*/
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
    puts("toha");
    for(it=apoint.begin();it!=apoint.end();it++)
    {
        temp = *it;
        printf("%d %d\n",temp.u,temp.v);
    }
    for(i=0;i<=nod;i++)
    {
        edge[i].clear();
    }
    return 0;
}

