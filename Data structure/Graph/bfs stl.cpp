#include<bits/stdc++.h>
#define pb push_back
#define N 10000
using namespace std;

vector<int>edge[N];
vector<int>cost[N];
int parent[1000];

void bfs(int source,int destination)
{
    int i,j,k,u,v;
    int distance[1000];
    memset(distance,-1,sizeof(distance));
    queue <int> q;
    distance[source]=0;
    q.push(source);
    //printf("toha");
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<edge[u].size();i++)
        {
            if(distance[edge[u][i]]==-1)
            {
                   distance[edge[u][i]]=distance[u]+1;
                   parent[edge[u][i]] = u;
                   q.push(edge[u][i]);
            }

        }
    }
    cout<<"shortest distance: "<<distance[destination]<<endl;//shoretsest path distance
    cout<<"shortest path: ";
    cout<<destination<<" ";
    while(parent[destination]!=source && source!=destination)
    {
        int x = parent[destination];
        cout<<x<<" ";
        destination=x;
    }
    cout<<source<<endl;
}
/*10 12
1 2
1 3
1 4
2 6
4 7
3 7
3 8
8 5
5 10
6 10
7 9
9 10*/
int main()//graph store undirected && BFS && cost always 1
{
    freopen("1.txt","r",stdin);
    int i,j,x,y,n,e;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
        //cost[x].pb(1);
        //cost[y].pb(1);//undirected graph a cost always 1
    }
    /*for(j=1;j<=n;j++)
    {
        cout<<edge[j].size()<<" size"<<endl;
    }*/
    bfs(1,7);
    return 0;
}


