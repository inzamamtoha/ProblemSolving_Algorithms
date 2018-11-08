#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
    int z;
};
bool compare(node lhs, node rhs)
{
    /*if(lhs.z==rhs.z)
    {
        if(lhs.y==rhs.y)
        {
            if(lhs.x>rhs.x)
                return lhs.x>rhs.x;
        }
        else
            return lhs.y<rhs.y;
    }
    else*/
        return lhs.z<rhs.z;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int i,j,k,l,m;
k    node a[100];
    for(i=0;i<3;i++)
    {
        cin>>a[i].x;
        cin>>a[i].y;
        cin>>a[i].z;
    }
    sort(a,a+3,compare);
    for(i=0;i<3;i++)
    {
        cout<<a[i].x<<" ";
        cout<<a[i].y<<" ";
        cout<<a[i].z<<" ";
        cout<<endl;
    }
    return 0;
}

