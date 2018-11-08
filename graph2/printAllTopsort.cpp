#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
vector<int>order;
int nod,edg,indeg[1000],visit[1000];
void solve()
{
    int i,j,u,v,flag=0;
    for(i=0;i<nod;i++)
    {
        if(indeg[i]==0 && visit[i]==0)
        {
            for(j=0;j<edge[i].size();j++)
            {
                v  = edge[i][j];
                indeg[v]--;
            }
            order.push_back(i);
            visit[i]=1;
            solve();
            visit[i]=0;
            order.erase(order.end()-1);
            for(j=0;j<edge[i].size();j++)
            {
                v  = edge[i][j];
                indeg[v]++;
            }
            flag=1;
        }
    }
    if(!flag)
    {
        for (int i = 0; i < order.size(); i++)
                cout <<order[i]<<" ";
        cout << endl;
    }
}
void topsort()
{
    memset(visit,0,sizeof(visit));
    solve();
}
int main()
{
    freopen("r.txt","r",stdin);
    int i,x,y;
    scanf("%d %d",&nod,&edg);
    while(edg--)
    {
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        //edge[y].push_back(x);
        indeg[y]++;
    }
    topsort();
    for(i=0;i<=nod;i++)
    {
        edge[i].clear();
    }
    return 0;
}
