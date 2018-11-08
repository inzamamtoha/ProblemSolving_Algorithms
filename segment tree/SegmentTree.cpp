#include<bits/stdc++.h>
using namespace std;
#define sz 1000
struct segment
{
   // int left;
   // int right;
    int value;
   // int lazy;
};
struct segment tree[sz*3];
int a[sz];
void build_tree(int node, int s,int e)
{
    if(s==e)
    {
        tree[node].value=a[s];
        return;
    }
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    build_tree(l,s,mid);
    build_tree(r,mid+1,e);
    tree[node].value=tree[l].value+tree[r].value;
    cout<<node<<" "<<tree[node].value<<endl;
}
void update_tree(int node,int s,int e,int id,int val)
{
    if(id<s || id>e)
        return;
    if(id==s && id==e)//id>=s && id<=e
    {
        tree[node].value = val;
        a[id] = val;
        return;
    }
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    update_tree(l,s,mid,id,val);
    update_tree(r,mid+1,e,id,val);
    tree[node].value=tree[l].value+tree[r].value;

}
int query_tree(int node,int s, int e,int i, int j)
{
    if(i>e || j<s)
        return 0 ;
    if(s>=i && e<=j)
        return tree[node].value;
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    int p1 = query_tree(l,s,mid,i,j);
    int p2 = query_tree(r,mid+1,e,i,j);
    return (p1+p2);

}
int main()
{
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build_tree(1,1,n);
    while(1)
    {
        puts("U");
        cin>>k>>j;
        //cout<<tree[i].value<<endl;
        update_tree(1,1,n,k,j);
         for(i=1;i<=n;i++)
        {
            cout<<a[i]<<" "<<tree[i].value<<endl;
        }
        puts("Q");
        cin>>k>>j;
        cout<<query_tree(1,1,n,k,j)<<endl;
    }
    return 0;
}
