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
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define NL puts("")
#define LL long long int
#define N 1000007
#define MOD 100000009
#define pb(x) push_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
using namespace std;
/*********************************************************************/
struct node
{
    int x;
    int y;
    bool operator <(const node & p) const{
        if(y==p.y)
        {
            return x<p.x;
        }
        else
          return y< p.y;
    }
};
    /*bool cmp(const node l,const node r)
    {
        if(l.y==r.y)
            return l.x<r.x;
        else
            return l.y<r.y;
    }*/
int main()
{
    //freopen("1.txt","r",stdin);
    struct node a[100];
    int i,j,k;
    for0(i,5)
    {
        cin>>a[i].x;
        cin>>a[i].y;
    }
    //sort(a,a+n,cmp)
    sort(a,a+5);
    puts("After sorting: ");
    for0(i,5)
    {
        cout<<a[i].x<<" "<<a[i].y<<endl;
    }
    return 0;
}


