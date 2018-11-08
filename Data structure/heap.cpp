#include<bits/stdc++.h>
using namespace std;
/// sajib && TOha

void inserting(int a[],int x)
{
   for(int i=x-1;i>0;)
   {
       if(a[i]>a[(i-1)/2])
       {
           swap(a[i],a[(i-1)/2]);
           i=(i-1)/2;
       }
       else
       {
           break;
       }
   }
}
void deleting(int x[],int i,int sz)
{
    if(2*i+1<sz)
    {
        if(x[(2*i)+1]>x[(2*i)+2])
        {
            swap(x[(2*i)+1],x[(2*i)+2]);
        }
        if(x[i]<x[2*i+2])
        {
            swap(x[i],x[2*i+2]);
            if(2*i+2<sz)
            {
                deleting(x,2*i+2,sz);
            }
        }
    }
}
void sortt(int a[],int n)
{
    int m=n;
    int b[1000];
    for(int i=0;i<=n;i++)
    {
        b[i]=a[i];
    }
    /*for(int i=0; i<=n; i++)
    {
        int x = b[0];
        swap(b[0],b[m]);
        deleting(b,0,m);
        m--;
        b[i]=x;
    }*/
    sort(b,b+n+1);
    for(int i=0;i<=n;i++)
        printf("%d ",b[i]);
    puts(" ");
}
void preorder(int a[],int i,int n)
{
    if(n>i) return;
    printf("%d ",a[n]);
    preorder(a,i,2*n+1);
    preorder(a,i,2*n+2);
}
void postorder(int a[],int i,int n)
{
    if(n>i) return;
    postorder(a,i,2*n+1);
    postorder(a,i,2*n+2);
    printf("%d ",a[n]);
}
void inorder(int a[],int i,int n)
{
    if(n>i) return;
    inorder(a,i,2*n+1);
    printf("%d ",a[n]);
    inorder(a,i,2*n+2);
}
void traverse(int a[],int id)
{
    puts("Inorder press 1");
    puts("Preorder press 2");
    puts("Postorderpress 3");
    int x;
    cin>>x;
    for(int i=0;i<=id;i++)
    {
        printf("%d ",a[i]);
    }
    puts(" ");
    if(x==1)
        inorder(a,id,0);
    else if(x==2)
        preorder(a,id,0);
    else if(x==3)
        postorder(a,id,0);
    puts(" ");

}
int main()
{
    int i,j,k,ch;
    int a[1000],id=0;
    while(1)
    {
        puts("Press 1 to insert");
        puts("Press 2 to delete");
        puts("Press 3 to traverse");
        puts("press 4 to Heapsort");
        puts("press 0 to exit");
        cin>>ch;
        if(ch==0)
            break;
        else if(ch==1)
        {
            int x,i;
            puts("Enter a value");
            cin>>x;
            a[id++]=x;
            inserting(a,id);
        }
        else if(ch==2)
        {
            swap(a[0],a[id-1]);
            deleting(a,0,id-1);
            id--;
        }

        else if(ch==3)
            traverse(a,id-1);
        else if(ch==4)
            sortt(a,id-1);
    }

}
