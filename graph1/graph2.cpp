#include<iostream>
#include<cstdio>
#include<vector>
#define pb push_back
#define N 10000
using namespace std;
/*
6 8
1 2
1 4
2 4
2 5
4 5
5 3
3 6
6 6
*/
int main()//graph store directed
{
    int i,j,x,y,n,e;
    vector<int>indeg[N];
    vector<int>outdeg[N];
    vector<int>cost[N];
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>x>>y;
         outdeg[x].push_back(y);
         indeg[y].push_back(x);
        //cost[x].pb(1);
        //cost[y].pb(1);

    }
    for(i=1;i<=n;i++)
    {
        printf(" %d has %d indegree & %d outdegree\n",i,indeg[i].size(),outdeg[i].size());
    }
    return 0;
}

