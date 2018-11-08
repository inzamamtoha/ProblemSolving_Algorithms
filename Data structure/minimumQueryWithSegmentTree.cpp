#include <bits/stdc++.h>
#include <math.h>
using namespace std;
vector <int> pk[100];
int maxx=1000000;
int segmentTreeSaver[100];
int segmentTreeSaverSize;
int segmentTreeMaker(int x[],int lo,int hi,int iter,int pos)/*this function save the tree
where 2*position+1 give left child and 2*position+2 give right child*/
{
    if(hi==lo)
    {
        segmentTreeSaver[pos]=x[lo];
        return x[lo];
    }
    else
    {
        int mid=(hi+lo)/2;
        int s=min(segmentTreeMaker(x,mid+1,hi,iter+1,2*pos+2),segmentTreeMaker(x,lo,mid,iter+1,2*pos+1));
        segmentTreeSaver[pos]=min(segmentTreeSaver[(2*pos)+1],segmentTreeSaver[(2*pos)+2]);
        return s;
    }
}
int gettingTheMinimum(int qLow,int qHigh,int lo,int hi,int pos)/*this fuction is the challenging function where we
judge our query that what minimum value our query return*/
{
    if(qLow<=lo&&qHigh>=hi)
    {
        return segmentTreeSaver[pos];
    }
    if(qLow>hi||qHigh<lo)
    {
        return maxx;
    }
    int mid=(hi+lo)/2;
    return min(gettingTheMinimum(qLow,qHigh,lo,mid,(2*pos)+1),gettingTheMinimum(qLow,qHigh,mid+1,hi,(2*pos)+2));
}
int main()
{
    int x[100],n,queryNumber,startingIndex,endingIndex;/*here x[] is the array where input array will be saved*/
    double extra;
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&x[i]);
    }
    extra=ceil(log2(n));
    segmentTreeSaverSize=(pow(2,(int)extra+1))-1;
    int res=segmentTreeMaker(x,0,n-1,0,0);
    for(int i=0;i<segmentTreeSaverSize;i++)
    {
        printf("%d ",segmentTreeSaver[i]);
    }
    printf("\n");
    scanf("%d",&queryNumber);
    for(int i=0;i<=queryNumber-1;i++)
    {
        scanf("%d %d",&startingIndex,&endingIndex);
        printf("%d\n",gettingTheMinimum(startingIndex,endingIndex,0,n-1,0));
    }
    return 0;
}
