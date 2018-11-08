#include<bits/stdc++.h>
#define pie acos(-1)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ss(st) scanf("%s",st)
#define sch(ch) scanf("%c",&ch)
#define pi(a) printf("%d",a)
#define pii(a,b) printf("%d %d",a,b)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define pl(a) printf("%lld",a)
#define pll(a,b) printf("%lld %lld",a,b)
#define plll(a,b,c) printf("%lld %lld %lld",a,b,c)
#define ps(st) printf("%s",st)
#define pch(c) printf("%c",c)
#define debug(n) printf("toha %d\n",n)
#define debug1(n) printf("saran %d\n",n)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define NL puts("")
#define SP printf(" ")
#define LL long long int
#define ULL unsigned long long int
#define N 100006
#define MOD 100000009
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
using namespace std;
/*********************************************************************/
int a[102][102],nod,edg,dis[109][109],par[109][109];
void find_path(int i, int j)
{
	if(i==j)
	{
		return;
	}
	else
	{

		return find_path(par[i][j],j);
		printf("%d\n",i);
	}
}
int main()
{
	//freopen("test.cpp","r",stdin);
	int i,j,k,x,y,c;
	sii(nod,edg);
	mem(a,-1);
	for0(i,edg)
	{
		siii(x,y,c);
		if(a[x][y]!=-1 && c<a[x][y])
		{
			a[x][y]=c;
			a[y][x]=c;
		}
		else if(a[x][y]== -1)
		{
			a[x][y]=c;
			a[y][x]=c;
		}

	}
	for(i=0;i<=nod;i++)
	{
		for(j=0;j<=nod;j++)
		{
			if(a[i][j]== -1)
			{
				dis[i][j]= MOD;
			}
			else
			{
				dis[i][j]=a[i][j];
				dis[j][i]=a[i][j];
			}
			par[i][j]=j;
		}
	}
	for0(k,nod)
	{
		for0(i,nod)
		{
			for0(j,nod)
			{
				if(dis[i][j]>(dis[i][k]+dis[k][j]))
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					par[i][j]=par[i][k];
				}
			}
		}
	}
	for0(i,nod)
	{
		for(j=i+1;j<nod;j++)
		{
			if(dis[i][j]== MOD)
				printf("%d to %d: No Path\n",i,j);
			else
				printf("%d to %d: %d\n",i,j,dis[i][j]);
		}
	}
	find_path(1,3);
	return 0;
}



