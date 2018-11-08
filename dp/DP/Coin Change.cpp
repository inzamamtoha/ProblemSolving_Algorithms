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
int n,k,a[101],c[101],dp[55][1008];
int solve(int m,int w)
{
	if(w==0)
		return 1;
	if(m==0)
		return 0;
	if(dp[m][w]!=-1)
	{
		return dp[m][w];
	}
	int nibo=0,nibona=0,nibon=0;
	for(int i=1;i<=c[m];i++)
	{
		if(w-(i*a[m])>=0)
		{
			nibo=(nibo+solve(m-1,w-(i*a[m])))%100000007;
		}
	}

	nibona =(nibona + solve(m-1,w))%100000007;
	return dp[m][w]=(nibo+nibona)%100000007;
}

int main()
{
   // freopen("test.cpp","r",stdin);
	//freopen("1.txt","w",stdout);
    int i,j,k,cs,t;
    si(t);
    for1(cs,t)
    {
    	sii(n,k);
    	for1(i,n)
    	{
    		si(a[i]);
    	}
    	for1(i,n)
    	{
    		si(c[i]);
    	}
    	mem(dp,-1);
    	printf("Case %d: %d\n",cs,solve(n,k));

    }

    return 0;
}


