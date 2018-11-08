#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
    int z;
};
bool compare(const node lhs,const node rhs)
{
        return lhs.z<rhs.z;
}
vector<node>bag;
int main()
{
    //freopen("1.txt","r",stdin);
    int i,j,k,l,n,e;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        node dhor;
        dhor.x=u;
        dhor.y=v;
        dhor.z=w;
        bag.push_back(dhor);
    }
    sort(bag.begin(),bag.end(),compare);
    for(i=0;i<e;i++)
    {
        cout<<bag[i].x<<" ";
        cout<<bag[i].y<<" ";
        cout<<bag[i].z<<" "<<endl;
    }
    return 0;
}


