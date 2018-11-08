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
#define N 100005
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
/*********************************************************************/

int tree[4*N], a[N],mx;

void build_tree(int node ,int s, int e)
{
    if(s==e)
    {
        tree[node] = s ;
        return ;
    }
    else
    {
        int l = 2*node;
        int r = 2*node+1;
        int mid =(s+e)/2;
        build_tree(l,s,mid);
        build_tree(r,mid+1,e);
        if(a[tree[l]]<=a[tree[r]])
            tree[node]=tree[l];
        else
            tree[node]=tree[r];
    }
}
int query_tree(int node,int s, int e,int i, int j)
{
    if(i>e || j<s)//out of segment
        return -1 ;
    if(s>=i && e<=j)//relevant segment
        return tree[node];
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    int p1 = query_tree(l,s,mid,i,j);
    int p2 = query_tree(r,mid+1,e,i,j);

    if(p1== -1)
        return tree[node]=p2;
    if(p2== -1)
        return tree[node]=p1;
    if(a[p1]<=a[p2])
        return tree[node]=p1;
    return tree[node]=p2;

}

int area(int s, int e,int n)
{
    if(s>e)
        return 0;
    if(s==e)
    {
        return a[s];
    }
    else
    {
        int id = query_tree(1,1,n,s,e);
        mx = max (area(s,id-1,n),area(id+1,e,n));
        return max(mx,a[id]*(e-s+1));
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
	//freopen("1.txt","w",stdout);
    int i,j,k,t,q,n,cs,la;
    si(t);
    for1(cs,t)
    {
        si(n);
        for1(k,n)
        {
            si(a[k]);
        }
        build_tree(1,1,n);

        printf("Case %d: %d\n",cs, area(1,n,n));
    }
    return 0;
}



