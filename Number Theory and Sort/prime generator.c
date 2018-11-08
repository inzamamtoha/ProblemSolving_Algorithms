#include<stdio.h>
#include<math.h>
int a[9999999];
main()
{
    int i,j,limit,n;
    scanf("%d",&n);
    limit=sqrt(n);
    a[0]=1;
    a[1]=1;
    for(i=4;i<=n;i+=2)
    {
        a[i]=1;
    }
    for(i=3;i<=(limit+1);i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=n;j+=(i*2))
            {
                a[j]=1;
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        if(a[i]==0)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}
