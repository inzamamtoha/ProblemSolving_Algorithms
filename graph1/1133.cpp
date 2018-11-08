#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[102],i,j,k,t,x,y,temp,n,m,b[102];
    char c1,c2;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        for(int l=0;l<m;l++)
        {
            cin>>c1;
            char ch = getchar();
            if(c1=='S')
            {
                scanf("%d",&x);
                for(j=0;j<n;j++)
                {
                    a[j]=a[j]+x;
                }
            }
            else if(c1=='M')
            {
                scanf("%d",&x);
                for(j=0;j<n;j++)
                {
                    a[j]=a[j]*x;
                }
            }
            else if(c1=='D')
            {
                scanf("%d",&x);
                for(j=0;j<n;j++)
                {
                    a[j]=a[j]/x;
                }
            }
            else if(c1=='R')
            {
                for(j=0;j<n;j++)
                {
                    b[j]=a[j];
                }

                for(j=0,k=n-1;j<n;j++,k--)
                {
                    a[j]=b[k];
                }
            }
            else if(c1=='P')
            {
                scanf("%d%d",&x,&y);
                temp=a[x];
                a[x]=a[y];
                a[y]=temp;
            }
        }
        printf("Case %d:\n",i);
        for(j=0;j<n;j++)
        {
            printf("%d",a[j]);
            if(j==n-1)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }

    }
    return 0;
}

