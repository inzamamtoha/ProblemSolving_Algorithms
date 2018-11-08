#include<bits/stdc++.h>
#define x first
#define y second
#define MOD 1000000007
#define LL long long
using namespace std;
typedef pair<LL,LL> pii;

pii extendedEuclid(LL a,LL b)  /// returns x, y | ax + by = gcd(a,b)
{
      if(b == 0)
        return pii(1, 0);
      else
        {
            pii d = extendedEuclid(b, a % b);
            // cout<<d.x<<" "<<d.y<<endl;
            return pii(d.y, d.x - d.y * (a / b));//(y,x-y*(a/b))
        }
}

LL modularInverse(LL a, LL n)
{
      pii ret = extendedEuclid(a, n);
      return ((ret.x % n) + n) % n;
}

LL Bigmod(LL b,LL p)
{
    if(p==0)return 1;
    else if(p%2==1)return (b*Bigmod(b,p-1))%MOD;
    else if(p%2==0){
        LL carry = Bigmod(b,p/2);
        return (carry*carry)%MOD;
    }
}
int main()
{
    LL a,b,n;
    while(1)
    {
        cin>>a;
        n=MOD-2;
        cout<<modularInverse(a,n+2)<<endl;
        cout<<Bigmod(a,n)<<endl;
    }
    return 0;
}

