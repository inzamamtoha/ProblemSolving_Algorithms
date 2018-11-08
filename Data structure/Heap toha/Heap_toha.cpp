#include<bits/stdc++.h>
using namespace std;
///parent (i-1)/2,child 2i+1,2i+2
void balancingAfterInsert(int a[],int sz)
{
    if(sz>=0)
    {
        if(a[sz]>a[(sz-1)/2])///build max heap
        {
            swap(a[sz],a[(sz-1)/2]);
            balancingAfterInsert(a,(sz-1)/2);
        }
    }
}
void traverse(int a[],int sz)
{
    for(int i=0;i<sz;i++)
        printf("%d ",a[i]);
    puts("");
}
void balancingAfterDelete(int a[],int i,int sz)
{
    if((2*i+1)<=sz)
    {
        if(a[(2*i+1)]<a[(2*i+2)]&&(2*i+2)<=sz)
        {
            if(a[i]<a[(2*i+2)]){
                swap(a[i],a[(2*i+2)]);
                balancingAfterDelete(a,2*i+2,sz);
            }
        }
        else
        {
            if(a[i]<a[(2*i+1)]){
                swap(a[i],a[(2*i+1)]);
                balancingAfterDelete(a,2*i+1,sz);
            }
        }
    }
}
void deleting(int a[],int sz)
{
    swap(a[0],a[sz]);
    sz--;
    balancingAfterDelete(a,0,sz);
}
void preorder(int a[],int i,int sz)
{
    if(i<=sz)
    {
        printf("%d ",a[i]);
        preorder(a,2*i+1,sz);
        preorder(a,2*i+2,sz);
    }
}
void inorder(int a[],int i,int sz)
{
    if(i<=sz)
    {
        inorder(a,2*i+1,sz);
        printf("%d ",a[i]);
        inorder(a,2*i+2,sz);
    }
}
void postorder(int a[],int i,int sz)
{
    if(i<=sz)
    {
        postorder(a,2*i+1,sz);
        postorder(a,2*i+2,sz);
        printf("%d ",a[i]);
    }
}
void heapsort(int a[],int sz)
{
    int b[1000],i,n;
    n=sz;
    for(i=0;i<=sz;i++)
        b[i]=a[i];
    for(i=0;i<=n;i++)
    {
        printf("%d ",b[0]);
        swap(b[0],b[sz]);
        sz--;
        balancingAfterDelete(b,0,sz);
    }
    puts("");
}
int main()
{
    int heap[1000],i,j,k,l,ch,sz=0,x;
    while(1)
    {
        puts("Press 1 to insert");
        puts("Press 2 to delete");
        puts("Press 3 to traverse");
        puts("Press 4 to Preorder traverse");
        puts("Press 5 to Inorder traverse");
        puts("Press 6 to Postorder traverse");
        puts("press 7 to Heapsort");
        puts("press 0 to exit");
        cin>>ch;
        if(ch==0)
            break;
        else if(ch==1){
            cin>>x;
            heap[sz]=x;
            balancingAfterInsert(heap,sz);///creating max heap
            sz++;
            traverse(heap,sz);
        }
        else if(ch==2){
            if(sz==0)
            {
                 continue;
            }
            deleting(heap,sz-1);
            sz--;
            traverse(heap,sz);
        }
        else if(ch==3){
            traverse(heap,sz);
        }
        else if(ch==4){
            preorder(heap,0,sz-1);
            puts("");
        }
        else if(ch==5){
            inorder(heap,0,sz-1);
            puts("");
        }
        else if(ch==6){
            postorder(heap,0,sz-1);
            puts("");
        }
        else if(ch==7)
            heapsort(heap,sz-1);
    }
    return 0;
}
