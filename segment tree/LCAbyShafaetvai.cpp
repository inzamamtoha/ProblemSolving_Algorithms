#include<bits/stdc++.h>
using namespace std;
#define mx 100002
int L[mx]; //level
int P[mx][22]; //sparse table
int T[mx]; //parent
vector<int>g[mx];
void dfs(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q) //N= total node
  {
      int tmp, log, i;

      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

        log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

void lca_init(int N)
  {
      memset (P,-1,sizeof(P));
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];
    //  P[0][0]=-1;
      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }

int main(void)
{
	g[0].push_back(1);
	g[0].push_back(2);
	g[2].push_back(3);
	g[2].push_back(4);
	dfs(0, 0, 0);
	lca_init(5);
//	for(int i=0;i<5;i++)
//		{
//			for(int j=0;j<4;j++)
//			{
//				printf("%d ",P[i][j]);
//			}
//		puts(" ");
//		}
	printf( "%d\n", lca_query(5,4,1) );
	return 0;
}
