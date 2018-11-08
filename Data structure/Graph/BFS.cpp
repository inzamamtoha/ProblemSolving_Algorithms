#include<bits/stdc++.h>
using namespace std;
#define N 10000
int v,e;
vector<int>edge[N];
vector<int>cost[N];
int parent[1000];
int que[N],frnt;
int sz=0;
void push(int ch)
{
     if(sz==N)
    {
        puts("Eror:queue is full");
    }
    else
    {
        que[sz]=ch;
        sz++;
    }
    frnt=que[0];
}
void pop()
{
    int i;
    if(sz==0)
    {
        puts("Eror:queue is empty");
    }
    else
    {
        for( i=0;i<=sz-1;i++)
        {
            que[i]=que[i+1];
        }
        sz--;
        if(sz==0)
            frnt=NULL;
    }
}
int sizee()
{
    return sz;
}
int froont()
{
    if(sz==0)
        puts("Empty");
    else
        return frnt;
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
        printf("%d ",parent[destination]);
    }
}
void bfs(int source ,int destination)//all edge cost must be equal for applying BFS
{
    int i,j,k,u;
     int distance[1000];
    memset(distance,-1,sizeof(distance));
    distance[source]=0;
    parent[source]=0;
    push(source);
    while(sz!=0)
    {
        u=froont();
        pop();
        for(i=0;i<edge[u].size();i++)
        {
            if(distance[edge[u][i]]==-1)
            {
                distance[edge[u][i]]=distance[u]+1;
                printf("Parent %d child %d\n",u,edge[u][i]);
                push(edge[u][i]);
                parent[edge[u][i]]=u;
            }
        }
    }
    for(i=1;i<=v;i++)
    {
        printf("Node %d Level %d\n",i,distance[i]);
    }
    cout<<"shortest distance: "<<distance[destination]<<endl;//shoretsest path distance
    cout<<"Shortest Path is: ";
    print_path(source,destination);//call recursive function

}
int main()//BFS works on undirected graph
{
    int i,j,x,y;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        //cin>>c;
        edge[x].push_back(y);
        edge[y].push_back(x);//for undirected graph
        //cost[x].push_back(c);
        //cost[y].push_back(c);
    }
    bfs(1,5);
    return 0;
}
