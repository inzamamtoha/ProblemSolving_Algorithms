#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
/*********************************************************************/
int graph[101][101];
int path [101][101];
/*
4 6
4 1 20
4 3 8
3 2 5
2 3 2
1 2 3
2 1 2
*/
void find_path(int u ,int v)
{
    printf("%d ",path[u][v]);
    while(u!=v)
    {
        printf("%d ",path[u][v]);
        u++;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int v,e,x,y,c;
    int i,j,k,l;
    for(i=0;i<=100;i++)
    {
        for(j=0;j<=100;j++)
        {
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=1e8;

            path[i][j]=j;
        }
    }

    cin>>v>>e;
    for(i=1;i<=e;i++)//input in adjacency matrix
    {
        cin>>x>>y>>c;
        graph[x][y]=c;
    }
    //floyed warshall begins
    for(k=1;k<=v;k++)
    {
        for(i=1;i<=v;i++)
        {
            for(j=1;j<=v;j++)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                    path[i][j]=path[i][k];
                }
            }
        }
    }
    while(1)
    {
        cin>>x>>y;
        if(graph[x][y]!=1e8)
        {
            printf("%d\n",graph[x][y]);
            find_path(i,j);
        }
    }
    return 0;
}


