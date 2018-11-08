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
#define N 100000009
#define MOD 100000009
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
using namespace std;

#define Max 10000000
vector<LL>pr;
int a[Max];
//map<LL,LL>a;
LL set_bit(LL n,LL position)
{
    n=n|(1<<position);
    return n;
}
bool check_bit(LL n,LL position)
{
    return n&(1<<position);
}
void bitwise_sieve()
{
    long long int i,j,limit;
    a[0]=set_bit(a[0],0);
    a[1]=set_bit(a[0],1);
    pr.push_back(2);
    limit=sqrt(N);
    for(i=4;i<=N;i=i+2)
    {
       a[i>>5]=set_bit(a[i>>5],i&31); //a[i/32]=set_bit(a[i/32],i%32);
    }
    for(i=3;i<=N;i=i+2)
    {
        if(check_bit(a[i/32],i%32)==false)
        {
            pr.push_back(i);
            if(i<=limit)
            {
                for(j=i*i;j<=N;j=j+(i*2))
                {
                   a[j>>5]=set_bit(a[j>>5],j&31); //a[j/32]=set_bit(a[j/32],j%32);
                }
            }
        }
    }
}
int check_prime(LL num)
{
   LL lim = sqrt(num)+1;
    for(int i=0;pr[i]<=lim;i++)
    {
        if(num%pr[i]==0)
        {
             pi(pr[i]);
           NL;
            return 0;
        }

    }
    return 1;
}
int main()
{
    bitwise_sieve();
    LL i,j,k,n,a[30],d,num=0,p;
    sl(n);
        if(check_prime(n))
           {
              puts("yes");
           }
           else
           {
               puts("no");
           }
    return 0;
}


