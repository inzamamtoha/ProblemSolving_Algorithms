#include<bits/stdc++.h>
using namespace std;
struct pqueue
{
    int pr;
    int tm;
    char name[100];
};
struct pqueue heap[1000],heap_copy[1000];
void balancingAfterInsert(struct pqueue a[],int sz)
{
    if(sz>=0&&((sz-1)/2)>=0)
    {
        if(a[sz].pr<a[(sz-1)/2].pr)///build min heap
        {
            swap(a[sz],a[(sz-1)/2]);
            balancingAfterInsert(a,(sz-1)/2);
        }
        else if(a[sz].pr==a[(sz-1)/2].pr)///build min heap
        {
            if(a[sz].tm<a[(sz-1)/2].tm){
                    swap(a[sz],a[(sz-1)/2]);
                    balancingAfterInsert(a,(sz-1)/2);
            }
        }
    }
}
void balancingAfterDelete(struct pqueue a[],int i,int sz)
{
    if((2*i+1)<=sz)
    {
        if(a[(2*i+1)].pr>a[(2*i+2)].pr&&(2*i+2)<=sz)
        {
            if(a[i].pr>a[(2*i+2)].pr){
                swap(a[i],a[(2*i+2)]);
                balancingAfterDelete(a,2*i+2,sz);
            }
            else if(a[i].pr==a[(2*i+2)].pr){
                if(a[i].tm>a[(2*i+2)].tm)
                {
                    swap(a[i],a[(2*i+2)]);
                    balancingAfterDelete(a,2*i+2,sz);
                }
            }
        }
        else
        {
            if(a[i].pr>a[(2*i+1)].pr){
                swap(a[i],a[(2*i+1)]);
                balancingAfterDelete(a,2*i+1,sz);
            }
            else if(a[i].pr==a[(2*i+1)].pr){
                if(a[i].tm>a[(2*i+1)].tm)
                {
                    swap(a[i],a[(2*i+1)]);
                    balancingAfterDelete(a,2*i+1,sz);
                }
            }
        }
    }
}
void heapsort(struct pqueue a[],int sz)
{
    int i,n;
    n=sz;
    for(i=0;i<=sz;i++)
        heap_copy[i]=a[i];
    for(i=0;i<=n;i++)
    {
        //printf("%d ",a[0]);
        heap_copy[i]=a[0];
        swap(a[0],a[sz]);
        sz--;
        balancingAfterDelete(a,0,sz);
    }
    for(i=0;i<=sz;i++)
        a[i]=heap_copy[i];
    puts("");
}
int main()
{
    int ch,sz=0,x=0;
    while(1)
    {
        puts("Press 1 to Enqueue");
        puts("Press 2 to Dequeue");
        puts("Press 3 to Display");
        puts("Press 0 to Exit");
        cin>>ch;
        if(ch==0)
        {
            break;
        }
        else if(ch==1)
        {
            puts("Enter priority and Data");
            scanf("%d %s",&heap[sz].pr,&heap[sz].name);
            heap[sz].tm=x+1;
            balancingAfterInsert(heap,sz);
            heapsort(heap,sz);
            sz++;
            x++;
        }
        else if(ch==2)
        {

        }
        else if(ch==3)
        {
            for(int i=0;i<sz;i++)
                printf("%s %d time %d\n",heap[i].name,heap[i].pr,heap[i].tm);
        }
    }
    return 0;
}
