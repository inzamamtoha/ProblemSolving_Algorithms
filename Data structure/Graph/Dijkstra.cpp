#include<bits/stdc++.h>
using namespace std;
#define N 10000
#define INF INT_MAX
int v,e;
vector<int>edge[N];
vector<int>cost[N];
int parent[1000];
struct graph
{
    int node;
    int cost;
    bool operator <(const graph & p)const
    {
        return cost<p.cost;
    }
}ed;
void print_path(int source,int destination)
{
    if(source==destination)
        return;
    else if(parent[destination]==0)
    {
        puts("No Path -_-");
    }
    else
    {
        print_path(source,parent[destination]);
        printf("%d ",parent[destination]);
    }
}
void dijkstra(int source ,int destination)//all edge cost must be equal for applying BFS
{
    int i,j,k,u,ucost;
    vector<int>dist(v+1,INF);//memset distance array element to infinite
    //int dist[1000];
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
    cout<<"shortest distance: "<<dist[destination]<<endl;//shoretsest path distance
    cout<<"Shortest Path is: ";
    print_path(source,destination);//call recursive function

}
/*
4 4
1 3 5
1 2 2
3 4 3
2 3 1
*/
int main()//
{
    int i,j,x,y,c;

    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        cin>>c;
        edge[x].push_back(y);
        edge[y].push_back(x);//for undirected graph
        cost[x].push_back(c);
        cost[y].push_back(c);
    }
    dijkstra(1,4);
    return 0;
}

