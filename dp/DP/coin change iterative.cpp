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
int n,k,a[102],c[102],dp[109][10008];
int main()
{
   //freopen("test.cpp","r",stdin);
	//freopen("1.txt","w",stdout);
    int i,j,k,cs,t;
    si(t);
    for1(cs,t)
    {
    	sii(n,k);
    	for1(i,n)
    	{
    		si(a[i]);
    		c[i]=k/a[i];
    	}
    	mem(dp,0);
    	for(i=1;i<=n;i++)
		{
			dp[i][0]=1;
		}
    	for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				if(j-a[i]>=0)
					dp[i][j]=(dp[i-1][j]+dp[i][j-a[i]])%100000007;
				else
					dp[i][j]=dp[i-1][j];
			}
		}
    	printf("Case %d: %d\n",cs,dp[n][k]);

    }

    return 0;
}


