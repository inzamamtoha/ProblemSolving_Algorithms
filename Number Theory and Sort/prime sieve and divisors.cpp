#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define pi acos(-1)
#define FOR1(i,t) for(i=1;i<=t;i++)
#define FOR0(j,n) for(j=0;j<n;j++)
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define sf scanf
#define pf printf
#define N 1000001
using namespace std;
long long int a[N],d[N];
vector<long long int > pr;
void sie()
{
    long long int i,sum=0,j,lim=sqrt(N)+2;
    //memset(a,0,sizeof(long long int));
    a[1]=a[0]=1;
    pr.push_back(2);
    for(i=4;i<=N;i=i+2)
    {
        a[i]=1;
    }
    for(i=3;i<=N;i=i+2)
    {
        if(a[i]==0)
        {
            pr.push_back(i);
            if(i<=lim)
            {
                  for(j=i*i;j<=N;j=j+(i*2))
                  {
                      a[j]=1;
                      sum++;
                  }


            }
        }
        sum++;
    }
    //cout<<sum<<endl<<pr.size()<<endl;
}
long long int divisor(long long int num)
{
   long long int i,j,k;

    long long int numberOfDivisors = 1;
    for ( i= 0; pr[i]<= num; i++)
        {
            long long int exponent = 0;
                while (num % pr[i] == 0)
                    {
                        exponent++;
                        num /= pr[i];
                    }
            numberOfDivisors *= (exponent+1);
        }
   return numberOfDivisors;
}
/*long long int div(long long int n)
{
    long long ans=1,sqr,i,j,pw;
    sqr=sqrt(n);
    for(i=0;pr[i]<=sqr;i++)
    {
        pw=0;
        while(n%pr[i]==0)
        {
            pw++;
            n=n/pr[i];
        }
        ans=ans*((pw*2)+1);
        if(pw==1)
        {
            sqr=sqrt(n);
        }
    }
    if(n>1)
    {
        ans=ans*3;
    }
    if(ans==2)return 1;
    if(ans%2==0)return 0;
    if(a[ans]==0)return 1;
    return 0;//pari na bujhi na ai function

}*/
int main()
{
    //freopen("1.txt","r",stdin);
    long long int n,k,i,j,cnt,x,y,temp;
    sie();
    while(cin>>x>>y)
    {
        temp=0;
        for(i=x;i<=y;i++)
        {
            if(a[i]==0)
            {
                temp++;
            }
            else if(a[div(i)]==1)
                {
                    temp++;
                }
        }
        cout<<temp<<endl;
    }
    return 0;
}
