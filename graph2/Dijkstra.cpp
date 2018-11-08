#include<bits/stdc++.h>
using namespace std;
#define N 108
#define INF INT_MAX
int nod,edg;
vector<int>edge[N];
vector<int>cost[N];
int parent[1000],dist[N];
struct graph
{
    int node;
    int cost;
    bool operator <(const graph & p)const
    {
        return cost>p.cost;
    }
}ed;
void dijkstra(int source )//all edge cost must be equal for applying BFS
{
    int i,j,k,u,ucost;
   // vector<int>dist(nod+1,INF);//memset distance array element to infinite
    //int dist[1000];
    for(i=0;i<=nod;i++)
	{
		dist[i]=INT_MAX;
	}
    priority_queue<graph>Q;
    dist[source]=0;
    parent[source]=0;
    ed.node=source;
    ed.cost=dist[source];
    Q.push(ed);
    while(!Q.empty())
    {
       struct graph X=Q.top();
        Q.pop();
        u=X.node;
        ucost=X.cost;
        //cout<<ucost<<endl;
        if(ucost!=dist[u])
        {
            continue;
        }
        for(i=0;i<edge[u].size();i++)
        {
            if(ucost+cost[u][i]<dist[edge[u][i]])
            {
                dist[edge[u][i]]=ucost+cost[u][i];
                ed.node=edge[u][i];
                ed.cost=dist[edge[u][i]];
                Q.push(ed);
                parent[edge[u][i]]=u;
            }
        }
    }
}
int main()//
{
    int i,j,x,y,c,t;
    scanf("%d",&t);
    for(int cs = 1;cs<=t;cs++)
	{
		scanf("%d %d",&nod,&edg);
		for(i=0;i<edg;i++)
		{
			scanf("%d %d %d",&x,&y,&c);
			edge[x].push_back(y);
			edge[y].push_back(x);//for undirected graph
			cost[x].push_back(c);
			cost[y].push_back(c);
		}
		dijkstra(1);
		if(dist[nod]== INT_MAX)
		{
			printf("Case %d: Impossible\n",cs);
		}
		else
		{
			printf("Case %d: %d\n",cs,dist[nod]);
		}
		for(i=0;i<=nod;i++)
		{
            edge[i].clear();
            cost[i].clear();
		}
	}
    return 0;
}


