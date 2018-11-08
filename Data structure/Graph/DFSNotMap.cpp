#include<bits/stdc++.h>
using namespace std;
#define N 10000
#define INF INT_MAX
int v,e;
vector<int>edge[N];
vector<int>cost[N];
int prev[1000];
int visit[1000];
int dt[1000],ft[1000],t=0;
void dfsVisit(int u)
{
    visit[u]=0;///gray
    t=t+1;
    dt[u]=t;

    for(int i=0;i<edge[u].size();i++)
    {
        // printf("%d %d\n",u,edge[u][i]);
        if(visit[edge[u][i]]== 0 && visit[u]==0)
        {
            printf("%d to %d has back edge\n",u,edge[u][i]);
        }
        if(visit[edge[u][i]]== 1 && visit[u]==0)
        {
            if(dt[u]<dt[edge[u][i]])
                printf("%d to %d has forward edge\n",u,edge[u][i]);
            else
                printf("%d to %d has cross edge\n",u,edge[u][i]);


        }
        if(visit[edge[u][i]]== -1 && visit[u]==0)///white
        {
            prev[edge[u][i]]=u;
            printf("%d to %d has tree edge\n",u,edge[u][i]);
            dfsVisit(edge[u][i]);
        }
    }
    visit[u]=1;///black
    t= t+1;
    ft[u]=t;
}
void dfs()
{
    memset(visit,-1,sizeof(visit));///white(-1),gray(0),black(1)
    memset(ft,-1,sizeof(ft));
    memset(dt,-1,sizeof(dt));
    /*for(int i=0;i<=v;i++)
    {
        visit[i]=-1;
        ft[i]=INF;
        dt[i]=INF;
        prev[i]=0;
    }*/
    for(int i=1;i<=v;i++)
    {
        if(visit[i]==-1)
        {
            dfsVisit(i);
        }
    }
}

int main()
{
   // freopen("1.txt","r",stdin);
    int i,j,x,y;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        //cin>>c;
        edge[x].push_back(y);
      // edge[y].push_back(x);//for undirected graph
        //cost[x].push_back(c);
        //cost[y].push_back(c);
    }
    dfs();
    /*while(1)
    {
        cin>>x;
        if(x==0)
            break;
        printf("discover %d  finish %d\n ",dt[x],ft[x]);
    }*/
    return 0;
}

