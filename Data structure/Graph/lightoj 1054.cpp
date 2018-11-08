#include<bits/stdc++.h>
#define pie acos(-1)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ss(st) scanf("%s",st)
#define sch(ch) scanf("%ch",&ch)
#define pi(a) printf("%d",a)
#define pii(a,b) printf("%d %d",a,b)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define pl(a) printf("%lld",a)
#define pll(a,b) printf("%lld %lld",a,b)
#define plll(a,b,c) printf("%lld %lld %lld",a,b,c)
#define ps(st) printf("%s",st)
#define pch(c) printf("%ch",c)
#define debug(n) printf("toha %d\n",n)
#define debug1(n) printf("saran %d\n",n)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define NL puts("")
#define SP printf(" ")
#define LL long long int
#define N 5000007
#define MOD 1000000007
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
using namespace std;
/*********************************************************************/
LL n,m;
LL Bigmod(LL b,LL p)
{
    if(p==0)return 1;
    else if(p%2==1)return (b*Bigmod(b,p-1))%MOD;
    else if(p%2==0){
        LL carry = Bigmod(b,p/2);
        return (carry*carry)%MOD;
    }
}
vector<LL>pr;
int a[N];
void sieve()
{
    int i,j,limit=sqrt(N)+1;
    a[0]=a[1]=1;
    pr.push_back(2);
    for(i=4;i<=N;i=i+2)
    {
        a[i]=1;
    }
    for(i=3;i<=N;i=i+2)
    {
        if(a[i]==0)
        {
            pr.push_back(i);
            if(i<=limit)
            {
                for(j=i*i;j<=N;j=j+(i*2))
                {
                    a[j]=1;
                }
            }
        }
    }
}
LL divisor_sum(LL num)
{
    LL i,j,sum=1,exp;
    LL sq=sqrt(num)+1;
    for(i=0;pr[i]<=sq;i++)
    {
        exp=0;
        while(num%pr[i]==0)
        {
            exp++;
            num=num/pr[i];
        }
        exp=(exp*m)%MOD;
        sum=(sum*(Bigmod(pr[i],exp+1)-1)*(Bigmod(pr[i]-1,MOD-2)))%MOD;
        //sum=sum*((pow(pr[i],exp+1)-1)/(pr[i]-1));
        sq=sqrt(num)+1;

    }
    if(num>1)
    {
        //sum=sum*((pow(num,2)-1)/(num-1));
        exp=1;
        exp=(exp*m)%MOD;
         sum=(sum*(Bigmod(num,exp+1)-1)*(Bigmod(num-1,MOD-2)))%MOD;
        //sum=sum*((pow(num,2)-1)/(num-1));

    }
    return sum;
}
int main()
{
    //freopen("1.txt","r",stdin);
    sieve();
    LL t,s,p,i;
    sl(t);
    for1(i,t)
    {
        sll(n,m);
        //p=pow(n,m);
       // debug(p%MOD);
        printf("Case %lld: %lld\n",i,divisor_sum(n));
    }
    return 0;
}

