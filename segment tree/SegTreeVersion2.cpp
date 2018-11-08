#include<bits/stdc++.h>
using namespace std;
#define sz 1000
int tree[sz*3],lazy[sz*3];
int a[sz];

void build_tree(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build_tree(2*node, start, mid);
        // Recurse on the right child
        build_tree(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update_range(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(node*2, start, mid, l, r, val);        // Updating left child
    update_range(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

int query_range(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = query_range(node*2, start, mid, l, r);         // Query left child
    int p2 = query_range(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
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
