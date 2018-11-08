#include <bits/stdc++.h>
using namespace std;
/// NOboni
int b[10000];
void balancinginsert(int a[],int index)
{
    if(index==1)
        return;
    if(a[index/2]<a[index])
    {
        swap(a[index/2],a[index]);
        //printf("%d %d\n",a[index],a[index/2]);
        balancinginsert(a,index/2);
    }
}

void insertion(int a[],int index,int data)
{
    a[index]=data;
    //i++;
    balancinginsert(a,index);
}
void balancingafterdelete(int a[],int i,int n)
{
    if(2*n>i && 2*n+1>i)
        return;
    if(2*n+1<=i)
    {
        if(a[2*n+1]>a[2*n] && a[2*n+1]>a[n])
        {
            swap(a[2*n+1],a[n]);
            balancingafterdelete(a,i,2*n+1);
        }
        else if(a[2*n]>a[2*n+1] && a[2*n]>a[n])
        {
            swap(a[2*n],a[n]);
            balancingafterdelete(a,i,2*n);
        }
    }
    else if(2*n<=i)
    {
        if(a[2*n]>a[n])
        {
            swap(a[2*n],a[n]);
            balancingafterdelete(a,i,2*n);
        }

    }
}

int Delete(int a[],int i)
{
    int b=a[1];
    a[1]=a[i];
    //a[i]=NULL;
    i--;
    balancingafterdelete(a,i,1);
    return b;

}
void sortt(int a[],int n)
{
    int m=n;
    for(int i=1; i<=n; i++)
    {
        int x= Delete(a,m);
        m--;
        b[i]=x;
    }
    for(int i=n;i>0;i--)
        printf("%d ",b[i]);
}
void preordertraverse(int a[],int i,int n)
{
    if(n>i) return;
    printf("%d",a[n]);
    preordertraverse(a,i,2*n);
    preordertraverse(a,i,2*n+1);
}
void postordertraverse(int a[],int i,int n)
{
    if(n>i) return;
    postordertraverse(a,i,2*n);
    postordertraverse(a,i,2*n+1);
    printf("%d",a[n]);
}
void inordertraverse(int a[],int i,int n)
{
    if(n>i) return;
    inordertraverse(a,i,2*n);
    printf("%d ",a[n]);
    inordertraverse(a,i,2*n+1);
}
main()
{
    int i=0,a[1000],n=1,v,j,k;
   while(1)
    {
        printf("1.Insert\n2.Delete\n3.Sort\n4.Preorder\n5.Postoreder\n6.Inorder\n7.Exit\n");
        scanf("%d",&j);
        if(j==1)
        {
            scanf("%d",&v);
            i++;
            insertion(a,i,v);
        }
        else if(j==2)
        {
            Delete(a,i);
            i--;
        }
        else if(j==3)
        {
            sortt(a,i);
            printf("\n");
        }
        else if(j==4)
        {
           preordertraverse(a,i,1);
           printf("\n");
        }
        else if(j==5)
        {
            cout<<i<<endl;
            postordertraverse(a,i,1);
            printf("\n");
        }
        else if(j==6)
        {
            inordertraverse(a,i,1);
            printf("\n");
        }
        else if(j==7)
            return 0;

    }
}
