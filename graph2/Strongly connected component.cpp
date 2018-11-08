#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000],tredge[1000],components[1000];
vector<int>order;
int nod,edg,color[1000],dt[1000],ft[1000],tim = 0,visit[1000];
void dfs_visit(int u)
{
    color[u]=0;///gray
    tim =tim+1;
    dt[u]=tim;
    for(int i=0;i<edge[u].size();i++)
    {
        int v = edge[u][i];
        /*if(color[v]==0)
        {
            puts("Back Edge");
        }
        if(color[v]==1)
        {
            if(dt[u]>dt[v])
            {
                puts("Cross Edge");
            }
            else
                puts("Forward Edge");
        }*/
        if(color[v]== -1)
        {
            dfs_visit(v);///tree edge
        }
    }
    color[u]=1;///black
    order.push_back(u);
    tim =tim+1;
    ft[u]=tim;

}
void dfs_visit_2(int u,int cmpn)
{
    visit[u]=0;//gray
    components[cmpn].push_back(u);
    for(int i=0;i<tredge[u].size();i++)
    {
        int v = tredge[u][i];
        if(visit[v]==-1)//white
        {
            dfs_visit_2(v,cmpn);
        }
    }
    visit[u]=1;//black

}
void dfs()
{
    int i,j;
    for(i=0;i<=nod;i++)
    {
        color[i]=-1;///white
        dt[i]=-1;
        ft[i]= -1;
    }
    for(i=0;i<nod;i++)
    {
        if(color[i]== -1)
        {
            dfs_visit(i);
        }
    }
}
void transpose_graph()
{
    for(int i=0;i<nod;i++)
    {
        for(int j=0;j<edge[i].size();j++)
        {
            int v =edge[i][j];
            tredge[v].push_back(i);
            //printf("%d %d\n",v,i);
        }
    }
}
void find_SCC()
{
    int i,u,j,cn=0;
    dfs();
    reverse(order.begin(),order.end());///topsort
    transpose_graph();
    for(i=0;i<nod;i++)
    {
        visit[i]=-1;
    }
    for(i=0 ;i<order.size();i++)
    {
        u = order[i];
        if(visit[u]==-1)
        {
            dfs_visit_2(u,cn);
            cn++;
        }
    }
    for(i=0;i<cn;i++)
    {
        printf("%d : ",i+1);
        for(j=0;j<components[i].size();j++)
        {
            printf("%d ",components[i][j]);
        }
        printf("\n");
    }
}
int main()
{
   // freopen("1.txt","r",stdin);
    int i,x,y;
    scanf("%d %d",&nod,&edg);
    while(edg--)
    {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        //edge[y].push_back(x);
    }
    find_SCC();
    for(i=0;i<=nod;i++)
    {
        edge[i].clear();
    }
    return 0;
}
