#include<iostream>
#include<cstdio>
#include<vector>
#define pb push_back
#define N 100000
using namespace std;
/*
6 8 //node-edge
1 2 //node1-node2
1 4
2 4
2 5
4 5
5 3
3 6
6 6
*/
int main()//graph store undirected
{
    int i,j,x,y,n,e;
    vector<int>edge[N];
    vector<int>cost[N];
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
        //cost[x].pb(1);
        //cost[y].pb(1);
    }
    for(i=1;i<=n;i++)
    {
        printf(" %d has %d degree\n",i,edge[i].size());
    }
    return 0;
}
