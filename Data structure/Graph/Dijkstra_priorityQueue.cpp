#include<bits/stdc++.h>
using namespace std;
#define oo 1000000000000000
#define N 100100
#define lli long long int

vector<long long int>edge[N],cost[N];
long long int D[N],taken[N],n,parent[N];

struct data{
    long long int node,cost;
    data (lli c,lli d){
        node=c; cost=d;
    }
    bool operator <(const data & p) const{
        return cost > p.cost;
    }
};

lli dijkstra(lli srce,lli dest)
{
    taken[srce]=1;
    priority_queue<data>pq;
    pq.push(data(srce,0));
    D[srce]=0;
    while(!pq.empty()){
        data X=pq.top(); pq.pop();
        lli u=X.node;
        lli ucost=X.cost;
        for(lli i=0;i<edge[u].size();i++){
            lli v=edge[u][i];
            if(ucost+cost[u][i]<D[v]){
                D[v]=ucost+cost[u][i];
                pq.push(data(v,D[v]));
                parent[v]=u;
                taken[v]=1;
            }
        }
    }
    return D[dest];
}

void init(long long int n)
{
    for(long long int i=0;i<=n;i++){
        edge[i].clear();
        cost[i].clear();
        taken[i]=0;
        parent[i]=0;
        D[i]=oo;
    }
}

int main()
{
    long long int m,a,b,c,i;
    while(cin>>n>>m){
        init(n);
        //printf("%d %d\n",n,m);
        for(i=0;i<m;i++){
            //scanf("%lld%lld%lld",&a,&b,&c);
            cin>>a>>b>>c;
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        //printf("%d\n",dijkstra(1,n));
        long long int d=dijkstra(1,n);
        //printf("%lld\n",d);
        if(d==oo) printf("-1\n");
        else{
            long long int p=n;
            vector<long long int>path;
            while(p!=1){
                path.push_back(parent[p]);
                p=parent[p];
            }
            for(i=path.size()-1;i>-1;i--) cout<<path[i]<<" ";
            cout<<n<<"\n";
        }
    }
	return 0;
}
