#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define xx first
#define yy second
#define eps 1e-9
#define i64 long long
#define MX 5005

typedef pair<int,int> pii;

struct node{
	int u,w;
	node(){}
	node(int _u,int _w){
		u=_u;w=_w;
	}
	bool operator <(const node &a)const{
		return w>a.w;
	}
};

vector<node> adj[MX];
int d[MX][2];

int dijkstra(int st,int ed){
	priority_queue<node> q;
	node u,v;
	int i,sz;
	memset(d,1,sizeof(d));
	d[1][0]=0;
	q.push(node(1,0));
	while(!q.empty()){
		u=q.top();q.pop();
		sz=adj[u.u].size();
		for(i=0;i<sz;i++){
			v.u=adj[u.u][i].u;
			v.w=adj[u.u][i].w+u.w;
			if(d[v.u][0]>v.w){
				d[v.u][1]=d[v.u][0];
				d[v.u][0]=v.w;
				q.push(v);
			}
			else if(d[v.u][1]>v.w && v.w>d[v.u][0]){
				d[v.u][1]=v.w;
				q.push(v);
			}
		}
	}
	return d[ed][1];
}

int main(){
   freopen("test.cpp","r",stdin);
	int cs,n,m,i,u,v,w,t=1;
	scanf("%d",&cs);
	while(cs--){
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)adj[i].clear();
		while(m--){
			scanf("%d %d %d",&u,&v,&w);
			adj[u].pb(node(v,w));
			adj[v].pb(node(u,w));
		}
		printf("Case %d: %d\n",t++,dijkstra(1,n));
	}
	return 0;
}



