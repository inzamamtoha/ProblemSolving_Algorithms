#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n;
    cin>>n;
    set<int>a;
    set<int>:: iterator x;
       for(j=1;j<=n;j++)
        {
            cin>>k;
            a.insert(k);
        }
         int s= a.size();
            x=a.begin();
            for(j=0;j<s;j++,x++)
            {
                cout<<*x<<endl;
            }
    a.clear();
    return 0;
}
