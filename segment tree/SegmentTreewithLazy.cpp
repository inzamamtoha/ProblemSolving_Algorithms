#include<bits/stdc++.h>
using namespace std;
#define sz 1000
struct segment
{
    int value;//or sum
    int prop;
};
struct segment tree[sz*3];
int a[sz];
void build_tree(int node, int s,int e)
{
    if(s==e)
    {
        tree[node].value=a[s];
        tree[node].prop=0;
        return;
    }
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    build_tree(l,s,mid);
    build_tree(r,mid+1,e);
    tree[node].value=tree[l].value+tree[r].value;
    tree[node].prop=tree[l].prop+tree[r].prop;
}
void update_tree(int node,int s,int e,int id,int val)
{
    if(id<s || id>e)//out of segment
        return;
    if(id==s && id==e)//id>=s && id<=e//relevant segment
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
void update_range(int node ,int s, int e, int i,int j,int val)
{
    if(i>e || j<s)//out of segment
        return ;
    if(s>=i && e<=j)//relevant segment
    {
        tree[node].value += ((e-s+1)*val); //(e-s+1)means how many leaf nodes of a node
        tree[node].prop += val;
        return;
    }
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    update_range(l,s,mid,i,j,val);
    update_range(r,mid+1,e,i,j,val);
    tree[node].value = tree[l].value + tree[r].value + (e-s+1)*tree[node].prop;
    //updating while upwards and add propagate value with left and right subtree

}
int query_tree(int node,int s, int e,int i, int j)
{
    if(i>e || j<s)//out of segment
        return 0 ;
    if(s>=i && e<=j)//relevant segment
        return tree[node].value;
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    int p1 = query_tree(l,s,mid,i,j);
    int p2 = query_tree(r,mid+1,e,i,j);
    return (p1+p2);

}
int query_range(int node , int s, int e, int i, int j, int carry = 0)
{
    if(i>e || j<s)//out of segment
        return 0 ;
    if(s>=i && e<=j)//relevant segment
        return tree[node].value + carry*(e-s+1);
    int l=2*node;
    int r=2*node+1;
    int mid=(s+e)/2;
    int p1 = query_range(l,s ,mid ,i,j,carry+tree[node].prop);
    int p2 = query_range(r,mid+1,e,i,j,carry+tree[node].prop);
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
            cout<<a[i]<<" "<<tree[i].value<<endl;
        }
        puts("Q");
        cin>>k>>j;
        cout<<query_range(1,1,n,k,j,0)<<endl;
    }
    return 0;
}

