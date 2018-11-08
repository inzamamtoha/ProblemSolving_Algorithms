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
#define N 1000007
#define MOD 100000009
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
using namespace std;
/*********************************************************************/
LL Bigmod(LL b,LL p)
{
    if(p==0)return 1;
    else if(p%2==1)return (b*Bigmod(b,p-1))%MOD;
    else if(p%2==0){
        LL carry = Bigmod(b,p/2);
        return (carry*carry)%MOD;
    }
}
/********************************************************************/
struct node
{
	int x,y;
};
struct node aa,bb,cc,hh,src,temp;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int r,c;
char a[25][25];

int bfs(node src)
{
	int u,v,i,j;
	int dis[25][25];
	mem(dis,-1);
	queue<node>Q;
	Q.push(src);
	dis[src.x][src.y]=0;
	while(!Q.empty())
	{
		temp=Q.front();
		Q.pop();
		for(i=0;i<4;i++)
		{
			u = fx[i]+temp.x;
			v = fy[i]+temp.y;
			if((u>=0 && u<r)&&(v>=0 && v<c)&&(a[u][v]!='#')&&(a[u][v]!='m')&&dis[u][v]==-1)
			{
				dis[u][v]=dis[temp.x][temp.y]+1;
				src.x=u;
				src.y=v;
				Q.push(src);
			}
		}
	}
	return dis[hh.x][hh.y];

}
int main()
{
   // freopen("test.cpp","r",stdin);
	//freopen("1.txt","w",stdout);
	int i,j,t,cs,x,y,w;
	si(t);
	for1(cs,t)
	{
		sii(r,c);
		for0(i,r)
		{
			ss(a[i]);
		}
		for0(i,r)
		{
			for0(j,c)
			{
				if(a[i][j]=='a')
				{
					aa.x=i;
					aa.y=j;
				}
				else if(a[i][j]=='b')
				{
					bb.x=i;
					bb.y=j;
				}
				else if(a[i][j]=='h')
				{
					hh.x=i;
					hh.y=j;
				}
				else if(a[i][j]=='c')
				{
					cc.x=i;
					cc.y=j;
				}
			}
		}
		//cout<<bfs(aa)<<endl;
		//cout<<bfs(bb)<<endl;
		//cout<<bfs(cc)<<endl;
		int	ans = max(bfs(aa),max(bfs(bb),bfs(cc)));
		printf("Case %d: %d\n",cs,ans);
	}
    return 0;
}












