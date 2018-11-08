#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
vector<int>order;
int nod,edg,color[1000],dt[1000],ft[1000],tim = 0;
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
void dfs()
{
    int i,j;
    for(i=0;i<=nod;i++)
    {
        color[i]=-1;///white
        dt[i]=-1;
        ft[i]= -1;
        //sort(edge[i].begin(),edge[i].end());
    }
    for(i=1;i<=nod;i++)
    {
        if(color[i]== -1)
        {
            dfs_visit(i);
        }
    }
}
void topsort()
{
    reverse(order.begin(),order.end());
    for(int i=0;i<nod;i++)
    {
        printf("%d",order[i]);
        if(i<nod-1)
        {
               printf(" ");
        }
    }
    printf("\n");
}
int main()
{
    int i,x,y;
    while(scanf("%d %d",&nod,&edg)==2)
    {
        if(nod==0 && edg ==0)
        {
            break;
        }
        while(edg--)
        {
            scanf("%d %d",&x,&y);
            edge[x].push_back(y);
            //edge[y].push_back(x);
        }
        dfs();
        topsort();
        for(i=0;i<=nod;i++)
        {
            edge[i].clear();
        }
    }
    return 0;
}

