#include<bits/stdc++.h>
using namespace std;
vector<int>edge[3000];
int dis[1000],par[1000],nd,ed;
void print_path(int n, int d)
{
    if(par[n] == n)
    {
        printf("%d",n);
        if(d!=0)
        {
             printf(" ");
        }
    }
    else{
        print_path(par[n],d+1);
        printf("%d",n);
        if(d!=0)
        {
             printf(" ");
        }
       // par.push_back(n);
    }
}
void bfs(int source)
{
    int i,j,u,v;
    for(i=0;i<nd;i++)
    {
        dis[i]=-1;
        par[i]=-1;
        sort(edge[i].begin(),edge[i].end());
    }
    par[0] = 0;
    dis[source]=0;
    queue<int>Q;
    Q.push(source);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(i=0;i<edge[u].size();i++)
        {
            v = edge[u][i];
            if(dis[v]==-1)
            {
                dis[v]= dis[u]+1;
                par[v] = u;
                Q.push(v);
            }
        }
    }
}
int main()
{
    int i,j,x,y;
    cin>>nd>>ed;
    while(ed--)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    bfs(0);
    for(i=0;i<nd;i++)
    {
        printf("%d: ",i);
        if(dis[i]!= -1){
            print_path(i,0);
        }
        else
            printf("Not Reachable");
        printf("\n");
    }
    return 0;
}

