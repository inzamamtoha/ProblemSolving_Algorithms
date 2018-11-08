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
LL n,k,w[305],p[305],save[305][30005];
LL solve(LL id,LL wt)
{
    int nibo=0 ,nibona=0;
    if(wt==0 || id>n)
    {
        return 0;
    }
    else if(save[id][wt]!=-1)
    {
        return save[id][wt];
    }
    else if(wt-w[id]>=0)
    {
       nibo = solve(id+1,wt-w[id])+p[id];

    }
    nibona = solve(id+1,wt);
    return save[id][wt]= max(nibo,nibona);
}
int main()
{
    //freopen("test.cpp","r",stdin);
	//freopen("1.txt","w",stdout);
    LL i,j,l,t;
    sl(t);
    while(t--)
    {
        sll(n,k);
        for1(i,n)
        {
            sl(w[i]);
        }
        for1(i,n)
        {
            sl(p[i]);
        }
        mem(save,-1);
        pl(solve(1,k));
        NL;
    }
    return 0;
}





