#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
#define pii pair<int,int>p
int fx[]={1,-1,0,0};//direction array
int fy[]={0,0,1,-1};//direction array
int cell[100][100];//cell[x][y] if -1 then it is blocked
int des[100][100],vis[100][100];
int row,col;


void bfs_2D(int sx,int sy)//source node is [sx][sy]
{
    int i,j,k;
   memset(vis,0,sizeof(vis));
   vis[sx][sy]=1;
    queue<pii>q;
   q.push(pii(sx,sy));
   while(!q.empty)
   {
       pii top=q.front());
       q.pop();
       for(k=0;k<4;k++)
       {
        int tx=top.uu+fx[k];
        int ty=top.vv+fy[k]; //Neighbor cell [tx][ty]
        if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0) //Check if the neighbor is valid and not visited before.
        {
            vis[tx][ty]=1;
            d[tx][ty]=d[top.uu][top.vv]+1;
            q.push(pii(tx,ty)); //Pushing a new pair in the queue
        }
       }

   }
}

