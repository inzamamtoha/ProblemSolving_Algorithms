#include<bits/stdc++.h>
using namespace std;
#define N 10000
#define INF INT_MAX
int v,e;
vector<int>cost[N];
int prev[1000];
int visit[1000];
int dt[1000],ft[1000],t=0;
 set<string>myset;
struct graph
{
    string x;
    string y;
    int m;
    int n;
};
vector<int>edge[N];
struct graph node[1000];
string fine(int x)
{
    set<string>::iterator it;
    int j;
    for(it=myset.begin(),j=1;it!=myset.end();it++,j++)
    {
        if(j==x)
            return (*it);
    }
}
int found(string x)
{
    set<string>::iterator it;
    int j;
    for(it=myset.begin(),j=1;it!=myset.end();it++,j++)
    {
        if(*it==x)
            return j;
    }
}
void dfsVisit(int u)
{
    visit[u]=0;///gray
    t=t+1;
    dt[u]=t;

    for(int i=0;i<edge[u].size();i++)
    {
        // printf("%d %d\n",u,edge[u][i]);
        if(visit[edge[u][i]]== 0 && visit[u]==0)
        {
            printf("%s to %s has back edge\n",fine(u).c_str(),fine(edge[u][i]).c_str());
        }
        if(visit[edge[u][i]]== 1 && visit[u]==0)
        {
            if(dt[u]<dt[edge[u][i]])
                 printf("%s to %s has forward edge\n",fine(u).c_str(),fine(edge[u][i]).c_str());
            else
                 printf("%s to %s has cross edge\n",fine(u).c_str(),fine(edge[u][i]).c_str());


        }
        if(visit[edge[u][i]]== -1 && visit[u]==0)///white
        {
            prev[edge[u][i]]=u;
            printf("%s to %s has tree edge\n",fine(u).c_str(),fine(edge[u][i]).c_str());
           //cout<<fine(u)<<" "<<fine(edge[u][i])<<endl;

            dfsVisit(edge[u][i]);
        }
    }
    visit[u]=1;///black
    t= t+1;
    ft[u]=t;
}
void dfs()
{
    memset(visit,-1,sizeof(visit));///white(-1),gray(0),black(1)
    memset(ft,-1,sizeof(ft));
    memset(dt,-1,sizeof(dt));
    /*for(int i=0;i<=v;i++)
    {
        visit[i]=-1;
        ft[i]=INF;
        dt[i]=INF;
        prev[i]=0;
    }*/
    for(int i=1;i<=v;i++)
    {
        if(visit[i]==-1)
        {
            dfsVisit(i);
        }
    }
}
int main()
{
    freopen("2.txt","r",stdin);
    int i,j=0;
    string a,b;
    cin>>v>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;

        //cin>>c;
        node[i].x=a;
        node[i].y=b;
        myset.insert(a);
        myset.insert(b);
        //edge[x].push_back(y);
        //edge[y].push_back(x);//for undirected graph
        //cost[x].push_back(c);
        //cost[y].push_back(c);
    }
    for(i=0;i<e;i++)
    {
        node[i].m=found(node[i].x);
        node[i].n=found(node[i].y);
        edge[node[i].m].push_back(node[i].n);
    }

    dfs();
    /*while(1)
    {
        cin>>x;
        if(x==0)
            break;
        printf("discover %d  finish %d\n ",dt[x],ft[x]);
    }*/
    return 0;
}


