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
    int u,v,cst;
};
struct node temp,tp;
vector<node>edge;
int nod,edg,parent[N];
bool compare(const node l,const node r)
{
    return l.cst<r.cst;
}
int find_par(int n)
{
    if(parent[n]== n)
    {
        return n;
    }
    else
    {
        return parent[n]=find_par(parent[n]);
    }
}
LL mst_kruskal()
{
    int i,j,u,v,cnt=0;
    for(i=0;i<=nod;i++)
    {
        parent[i]=i;
    }
    int sz = edge.size();
    LL sm=0;
    for(i=0;i<sz;i++)
    {
        u = find_par(edge[i].u);
        v = find_par(edge[i].v);
        if(u!=v)
        {
            parent[v]=u;
            sm += edge[i].cst;
            cnt++;
        }
        if(cnt==(nod-1))
		{
			return sm;
		}
    }
}
int main()
{
   // freopen("1.cpp","r",stdin);
	//freopen("1.txt","w",stdout);
	int t,cs,i,j,k,x,y,c,source;
	sii(nod,edg);
	for0(i,edg)
	{
		siii(x,y,c);
		temp.u=x;
		temp.v=y;
		temp.cst=c;
		edge.push_back(temp);
	}
	sort(edge.begin(),edge.end(),compare);
	LL ans = mst_kruskal();
	pl(ans);
	NL;
	edge.clear();
    return 0;
}



