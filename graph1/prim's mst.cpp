#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,cst;
    bool operator < (const node & m)const
    {
        return cst>m.cst;
    }
};
struct node temp,tp;
vector<node>edge[1000];
int nod,edg,take[1000],dis[1000];
void prim_mst(int source)
{
    int i,j,ans=0,v,w;
    for(i=0;i<=nod;i++)
    {
        dis[i]=INT_MAX;
        take[i]=0;
    }
    dis[source]=0;
    temp.u=source;
    temp.cst=0;
    priority_queue<node>pq;
    pq.push(temp);
    while(!pq.empty())
    {
        tp=pq.top();
        pq.pop();
        if(take[tp.u]==1)
        {
            continue;//already visited
        }
        take[tp.u]=1;
        ans += tp.cst;
        for(i=0;i<edge[tp.u].size();i++)
        {
            temp = edge[tp.u][i];
            v = temp.u;
            w = temp.cst;
            if(take[v]==1)
                continue;
            if(w<dis[v])
            {
                pq.push(temp);
                dis[v]=w;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("test.cpp","r",stdin);
    int i,j,x,y,w;
    cin>>nod>>edg;
    while(edg--)
    {
        cin>>x>>y>>w;
        temp.u=y;
        temp.cst=w;
        edge[x].push_back(temp);
        temp.u=x;
        temp.cst=w;
        edge[y].push_back(temp);
    }
    prim_mst(0);
    return 0;
}
