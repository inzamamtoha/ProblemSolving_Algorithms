#include<stdio.h>
struct pel
{
    int pr;
    char s[100];
    int time;
};
void Delete(int b,int i,struct pel a[])
{
    int j;
    for(j=b; j<i;)
    {
        if(a[j].pr>a[2*j].pr)
        {
            if((2*j)>=i) return;
            struct pel tmp;
            tmp=a[2*j];
            a[2*j]=a[j];
            a[j]=tmp;
            j=j*2;
        }
        else if(a[j].pr>a[(2*j)+1].pr)
        {
            if((2*j)+1>=i) return;
            struct pel tmp;
            tmp=a[(2*j)+1];
            a[(2*j)+1]=a[j];
            a[j]=tmp;
            j=1+(2*j);
        }
        else
        {
            Delete(2*j,i,a);
            Delete((2*j)+1,i,a);
        }
        return;
    }

}
void heapsort(int i,struct pel a[])
{
    int k,tmp,j;
    struct pel b[100];
    for(k=i,tmp=1; k>=1; tmp++)
    {
        b[tmp]=a[1];
        a[1]=a[k-1];
        a[k-1].pr=-1;
        k--;
        for(j=k; j!=0; j=j/2)
        {
            Delete(1,k,a);
        }
    }
    for(k=1; k<=i; k++)
    {
        a[k]=b[k];
    }
}
int insert(int i,int t,struct pel a[])
{
    int k,v;
    printf("Enter priority and data respectively\n");
    scanf("%d %s",&a[i].pr,&a[i].s);
    a[i].time=t+1;
    for(v=i; v>=1; v=v/2)
    {
        for(k=i; k>1; k=k/2)
        {
            if(a[k/2].pr>a[k].pr || ((a[k/2].pr==a[k].pr) && (a[k/2].time>a[k].time)))
            {
                struct pel tmp=a[k/2];
                a[k/2]=a[k];
                a[k]=tmp;
            }

        }
    }
    i++;
    heapsort(i,a);
    return i;
}
main()
{
    struct pel a[100];
    int t=0;
    int i=1,j,top,n,k=0,tmp;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&n);
        if(n==1)
        {
            i=insert(i,t,a);
            t++;
        }
        else if(n==2)
        {
            if(i<=0)
            {
                printf("Empty queue");
                return;
            }
            else
            {
                printf("%s has been dequeued\n",a[1].s);
                a[1]=a[i-1];
                i--;
                for(j=i; j!=0; j=j/2)
                {
                    Delete(1,i,a);
                }
            }
        }
        else if(n==3)
        {
            for(j=1; j<i; j++)
                printf("%s\n",a[j].s);
        }
        else if(n==4)
        {
            return 0;
        }
    }
}

