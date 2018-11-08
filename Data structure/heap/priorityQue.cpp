#include <bits/stdc++.h>
using namespace std;
///sajib
struct priorityQueue{
    int value;
    int appearance;
};
void insert(struct priorityQueue x[],int i)
{
    if(i>0)
    {
        if(x[i].value>x[(i-1)/2].value)
        {
            swap(x[i],x[(i-1)/2]);
            insert(x,(i-1)/2);
        }
    }
}
void dlt(struct priorityQueue x[],int i,int sz)
{
    if(2*i+1<sz)
    {
        if(x[(2*i)+1].value>x[(2*i)+2].value)
        {
            swap(x[(2*i)+1],x[(2*i)+2]);
        }
        else if(x[2*i+1].value==x[2*i+2].value)
        {
            if(x[2*i+1].appearance<x[2*i+2].appearance)
            {
                swap(x[2*i+1],x[2*i+2]);
            }
        }
        if(x[i].value<x[2*i+2].value)
        {
            swap(x[i],x[2*i+2]);
            if(2*i+2<sz)
            {
                dlt(x,2*i+2,sz);
            }
        }
        else if(x[i].value==x[2*i+2].value)
        {
            if(x[i].appearance>x[2*i+2].appearance)
            {
                swap(x[i],x[2*i+2]);
                if(2*i+2<sz)
                {
                    dlt(x,2*i+2,sz);
                }
            }
        }
    }
}
void traverse(struct priorityQueue x[],int i,int sz)
{
    printf("%d %d\n",x[i].value,x[i].appearance);
    if(2*i+1<=sz)
    {
        traverse(x,2*i+1,sz);
    }
    if(2*i+2<=sz)
    {
        traverse(x,2*i+2,sz);
    }
}
int main()
{
    struct priorityQueue x[100];
    int sz=0,count[10000],i,n;
    memset(count,0,sizeof(count));
    while(1)
    {
        int choice;
        printf("enter your choice\n");
        printf("press 1 to insert\n");
        printf("press 2 to delete\n");
        printf("press 3 to traverse\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            scanf("%d",&n);
            x[sz].value=n;
            x[sz].appearance=count[n]+1;
            count[n]=count[n]+1;
            insert(x,sz);
            sz++;
            for(i=0;i<=sz-1;i++)
            {
                printf("%d %d\n",x[i].value,x[i].appearance);
            }
            printf("\n");
        }
        if(choice==2)
        {
            swap(x[sz-1],x[0]);
            /*for(i=0;i<=sz-1;i++)
            {
                printf("%d %d\n",x[i].value,x[i].appearance);
            }
            printf("\n");*/
            sz--;
            dlt(x,0,sz-1);
            for(i=0;i<=sz-1;i++)
            {
                printf("%d %d\n",x[i].value,x[i].appearance);
            }
            printf("\n");
        }
        if(choice==3)
        {
            traverse(x,0,sz-1);
        }
    }
}
