#include<bits/stdc++.h>
using namespace std;
#define N 10000
#define INF INT_MAX
int v,e;
vector<int>cost[N];
int prev[1000];
int visit[1000];
int dt[1000],ft[1000],t=0;
 set<string>myset;
struct graph
{
    string x;
    string y;
    int m;
    int n;
};
vector<int>edge[N];
struct graph node[1000];
int parent[1000];
string fine(int x)
{
    set<string>::iterator it;
    int j;
    for(it=myset.begin(),j=1;it!=myset.end();it++,j++)
    {
        if(j==x)
            return (*it);
    }
}
int found(string x)
{
    set<string>::iterator it;
    int j;
    for(it=myset.begin(),j=1;it!=myset.end();it++,j++)
    {
        if(*it==x)
            return j;
    }
}
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
        cout<<fine(parent[destination])<<" "<<endl;
    }
}
void bfs(int source,int destination)
{
    int i,j,k,u;
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
    for(i=1;i<=v;i++)
    {
        printf("Node %s Level %d\n",fine(i).c_str(),distance[i]);
    }

}
int main()
{
    //freopen("2.txt","r",stdin);
    int i,j=0;
    string a,b;
    cin>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;

        //cin>>c;
        node[i].x=a;
        node[i].y=b;
        myset.insert(a);
        myset.insert(b);
        //edge[x].push_back(y);
        //edge[y].push_back(x);//for undirected graph
        //cost[x].push_back(c);
        //cost[y].push_back(c);
    }
    v=myset.size();
    for(i=0;i<e;i++)
    {
        node[i].m=found(node[i].x);
        node[i].n=found(node[i].y);
        edge[node[i].m].push_back(node[i].n);
        edge[node[i].n].push_back(node[i].m);
    }
   int xx=found("a");
   int yy=found("j");
    bfs(xx,yy);
    //print_path(xx,yy);
    return 0;
}

