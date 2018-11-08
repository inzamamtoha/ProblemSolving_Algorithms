#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

pii extendedEuclid(int a, int b)  /// returns x, y | ax + by = gcd(a,b)
{
  if(b == 0)
    return pii(1, 0);
  else
    {
        pii d = extendedEuclid(b, a % b);
         cout<<d.x<<" "<<d.y<<endl;
        return pii(d.y, d.x - d.y * (a / b));//(y,x-y*(a/b))
   }
}
int main()
{
    int a,b;
    while(1)
    {
        cin>>a>>b;
        pii ans=extendedEuclid(a,b);
        cout<<ans.x<<" "<<ans.y<<endl;
    }
    return 0;
}
