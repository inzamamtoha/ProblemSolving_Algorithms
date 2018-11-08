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
/********************************************************************/
int tree[3*N],lazy[3*N],a[N];
void build_tree(int node ,int s, int e)
{
    if(s==e)
    {
        tree[node]=a[s];
        lazy[node]=0;
        return;
    }
    else
    {
        int l = 2*node;
        int r = 2*node+1;
        int mid =(s+e)/2;

        build_tree(l,s,mid);
        build_tree(r,mid+1,e);

        tree[node] = tree[l] + tree[r];
        lazy[node] = lazy[l] + lazy[r];
    }
}
void lazy_update(int node, int s, int e)
{
    if(lazy[node]!=0)
    {
        tree[node] += (e-s+1)*lazy[node];
        if(s!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
void update_tree(int node,int s, int e,int id,int val)
{
    if( s==e)
    {
        a[s] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (s+e)/2;
        if(id>=s && id<=mid)
            update_tree(2*node,s,mid,id,val);
        else
            update_tree(2*node+1,mid+1,e,id,val);

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update_range(int node, int s, int e, int i, int j, int val)
{
    lazy_update(node,s,e);
    if(i>e || j<s || s>e)
        return;
    if(s>=i && e<=j)
    {
        tree[node]+=(e-s+1)*val;
        if(s!=e)
        {
            lazy[2*node]+= val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    int mid = (s + e) / 2;
    update_range(node*2, s, mid, i, j, val);        // Updating left child
    update_range(node*2 + 1, mid + 1, e, i, j, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query_tree(int node,int s, int e,int i, int j)
{
    if(i>e || j<s)//out of segment
        return 0 ;
    if(s>=i && e<=j)//relevant segment
        return tree[node];
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    int p1 = query_tree(l,s,mid,i,j);
    int p2 = query_tree(r,mid+1,e,i,j);
    return (p1+p2);

}
int query_range(int node,int s,int e,int i,int j)
{
    if(i>e || j<s || s>e)
        return 0;
    lazy_update(node,s,e);

    if(s>=i && e<=j)
        return tree[node];
    int mid = (s+e)/2;
    int p1 = query_range(2*node,s,mid,i,j);
    int p2 = query_range(2*node+1,mid+1,e,i,j);
    return (p1+p2);
}
int main()
{
    int i,j,k,n,val;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build_tree(1,1,n);
    while(1)
    {
        puts("U");
        cin>>k>>j>>val;
        //cout<<tree[i].value<<endl;
        update_range(1,1,n,k,j,val);
         for(i=1;i<=n;i++)
        {
            cout<<a[i]<<" "<<tree[i]<<endl;
        }
        puts("Q");
        cin>>k>>j;
        cout<<query_range(1,1,n,k,j)<<endl;
    }
    return 0;
}



