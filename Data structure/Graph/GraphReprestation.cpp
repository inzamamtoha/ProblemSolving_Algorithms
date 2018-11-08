#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e,x,y,i,j;
    cin>>v>>e;
    vector<int>edge[N];
    vector<int>cost[N];
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        //cin>>c;
        edge[x].push_back(y);
        edge[y].push_back(x);//for undirected graph
        //cost[x].push_back(c);
        //cost[y].push_back(c);
    }
    for(i=1;i<=n;i++)
    {
        printf(" %d has %d degree\n",i,edge[i].size());
    }
    return 0;

}
