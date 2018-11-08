#include<bits/stdc++.h>
#define pb push_back
#define N 10000
using namespace std;
/*
#define white 1
#define gray 0
#define black -1
map<string,int>mymap;
map<string,int>:: iterator it;
vector<int>edge[10001];
LL color[40001],dt[40001],ft[40001],tmm;
void dfs_visit(int u)
{
    int v;
    color[u]=gray;
//    tm=tm+1;
//    dt[u]=tm;
    for(int i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(color[v]==white)
            dfs_visit(v);
        else if(color[v]==gray)
        {
            tmm=1;
            return ;
        }
    }
    color[u]=black;
   // tm= tm+1;
   // ft[u]=tm;
}
void dfs(int node)
{
    for(int i = 1; i<=node ;i++)
    {
        color[i]=white;
        dt[i]=INF;
        ft[i]=INF;
    }
    for(int i=1;i<=node;i++)
    {
        if(tmm==1)
        {
            return ;
        }
        if(color[i]==white)
            dfs_visit(i);
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    LL i,j,k,cas,t,n;
    char a[20],b[20];
    sl(t);
    for1(cas,t)
    {
        sl(n);
        k=1;
        while(n--)
        {
            scanf("%s %s",a,b);
            if(mymap[a]==0)
                mymap[a]=k++;
            if(mymap[b]==0)
                mymap[b]=k++;
            edge[mymap[a]].pub(mymap[b]);
        }
        tmm=0;
        dfs(k-1);

        if(tmm==1)
            printf("Case %lld: No\n",cas);
        else if(tmm==0)
            printf("Case %lld: Yes\n",cas);
        mymap.clear();
        for(i=1;i<k;i++)
            edge[i].clear();
    }
    return 0;
}
*/
vector<int>edge[N];
vector<int>cost[N];
int parent[1000];
 int visited[1000],distance[1000];
void dfs(int u)
{
    int len =edge[u].size();
    int v;
    for(int i=0;i<len;i++)
    {
        v = edge[u][i];
        if( ! visited[v] )
        {
            visited[v] = true;
            c++;
            dfs(v);
        }
    }
}

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
/*10 12//sample input
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
    dfs(7);
    return 0;
}

