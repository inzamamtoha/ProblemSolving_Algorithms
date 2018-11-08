#include<bits/stdc++.h>
#define N 99999999
#define LL long long int
using namespace std;/// totient phi finds  how many coprime 1 to n with n
vector<LL>pr;
int a[N];
void sieve()
{
    long long int i,j,k=0,limit;
    a[0]=a[1]=true;
    pr.push_back(2);
    limit=sqrt(N);
    for(i=4;i<=N;i=i+2)
    {
        a[i]=true;
    }
    for(i=3;i<=N;i=i+2)
    {
        if(a[i]==false)
        {
            pr.push_back(i);
            if(i<=limit)
            {
                for(j=i*i;j<=N;j=j+(i*2))
                {
                    a[j]=true;
                }
            }
        }
    }
}
/*
int phi(int n) {///At first generate primes by sieve
  int ret = n;
  for (int i = 0; i < pr.size(); i++)
    {
        if (n % pr[i] == 0) {
            ret -= ret / pr[i];
    }
  }
  return ret;
}
*/
int phi (int n)///without sieve another implementation of totient phi
{
  int ret = n;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      while (n % i == 0)
      {
        n /= i;
      }
      ret -= ret / i;
    }
  }
  // this case will happen if n is a prime number
  // in that case we won't find any prime that divides n
  // that's less or equal to sqrt(n)
  if (n > 1) ret -= ret / n;
  return ret;
}
int main()
{
    //sieve();
    int x;
    while(1)
    {
       cin>>x;
        cout<<phi(x)<<endl;;
    }
    return 0;
}
