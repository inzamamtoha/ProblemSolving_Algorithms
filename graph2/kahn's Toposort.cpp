#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
vector<int>order;
int nod,edg,indeg[1000],visit[1000];
void topsort_kahn()
{
    int i,u,v,j,cnt=0;
    memset(visit,0,sizeof(visit));
    queue<int>Q;
    for(i=0;i<nod;i++)
    {
        if(indeg[i]==0)
            Q.push(i);
    }
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        visit[u]=1;
        order.push_back(u);
        cnt++;
        for(i=0;i<edge[u].size();i++)
        {
            v=edge[u][i];
            indeg[v]--;
            if(indeg[v]==0)
            {
                Q.push(v);
            }
        }
    }
    if(cnt!=nod)
    {
        puts("Cycle");
    }
    else
    {
        for(i=0;i<order.size();i++)
        {
            printf("%d ",order[i]);
        }
        puts("");
    }

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
    topsort_kahn();
    for(i=0;i<=nod;i++)
    {
        edge[i].clear();
    }
    return 0;
}
