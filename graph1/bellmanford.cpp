#include<bits/stdc++.h>
using namespace std;
#define MX 11000
struct node{
 int a,b,cost;
} edge[MX];
int nod,edg;
int BellmanFord() //n=node, m=edge
{
	 int cost[nod+9];
	 int negativeCycle = 0;

	 for(int i=0; i<nod; i++)
     {
         cost[i]=100000009;
     }
	  cost[0]=0;

	 for(int i=0; i<nod-1; i++)
     {
         for(int j=0; j<edg; j++)
         {
             if(cost[edge[j].b]>cost[edge[j].a]+edge[j].cost)
				cost[edge[j].b]=cost[edge[j].a]+edge[j].cost;
         }
     }
	 for(int i=0; i<edg; i++)
     {
        if(cost[edge[i].b]>cost[edge[i].a]+edge[i].cost)
        {
            negativeCycle=1;
        }
     }
	return negativeCycle;
}
int main()
{
	 int i,j,k;
	 scanf("%d %d",&nod,&edg);
	 for(int i=0; i<edg; i++)
		cin>>edge[i].a>>edge[i].b>>edge[i].cost;

	 if(BellmanFord()== 1)
        puts("Yes");
	 else
		puts("No");
	 return 0;
}

