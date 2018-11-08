#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
};
bool compare(node lhs, node rhs)
{
    if(lhs.y==rhs.y)
    {
        if(lhs.x>rhs.x)
        {
            return lhs.x>rhs.x;
        }
    }
    else
        return lhs.y<rhs.y;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int i,j,k,l,m;
    node a[100];
    for(i=0;i<3;i++)
    {
        cin>>a[i].x;
        cin>>a[i].y;
    }
    sort(a,a+3,compare);
    for(i=0;i<3;i++)
    {
        cout<<a[i].x<<" ";
        cout<<a[i].y<<" ";
        cout<<endl;
    }
    return 0;
}
