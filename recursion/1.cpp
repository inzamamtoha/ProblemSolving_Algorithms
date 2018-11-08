#include<bits/stdc++.h>
#define pi acos(-1)
#define si(a) scanf("%d",&a);
#define sii(a,b) scanf("%d %d",&a,&b);
#define sf scanf
#define pf printf
#define LL long long int
#define N 10000007
using namespace std;
int main()
{
    //freopen("1.txt","r",stdin);
    int n,k,i,j,c,x;
    vector<LL>a;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]==a[j]&&i!=j)
            {
                a[j]--;
                if(a[j]<=0)
                    a[j]=0;
            }
        }
    }
    LL s=0;
     for(i=0;i<n;i++)
    {
        s=s+a[i];
    }
    cout<<s<<endl;
    //main();
    return 0;
}


