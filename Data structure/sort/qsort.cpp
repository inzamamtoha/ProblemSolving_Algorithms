#include<bits/stdc++.h>
using namespace std;
int a[500],n,ii=0;

int median(int a1, int b, int c)
{
    if(a[a1]>a[b])
    {
        if(a[a1]>a[c])
        {
            if(a[b]>a[c])
            return b;
            else
            return c;
        }
    }
    else
    {
        if(a[b]>a[c])
        {
            if(a[c]>a[a1])
            return c;
            else
            return a1;
        }
    }
}

int partion(int left,int right)
{
    int i,p,pvt,mid;
    p=left;
    mid=(left+right)/2;
    printf("\nmid %d %d\n",mid,a[mid]);
    med=median(a[left],a[mid],a[right]);
        if(med==arr[low])
          {
              pivot=low;
          }
        if(med==arr[mid])
          {
              pivot=mid;
          }
          if(med==arr[high])
          {
              pivot=high;
          }
    swap(a[mid],a[left]);
    pvt=a[left];
    for(i=left+1;i<=right;i++)
    {
        if(a[i]<=pvt)
        {
            p++;
            //printf("a[%d] = %d. a[%d] = %d\n",i,a[i],p,a[p]);
            swap(a[i],a[p]);
        }
    }
    swap(a[left],a[p]);
 /* for(int i=0;i<n;i++)
  {
      cout<<a[i]<<" ";
  }
  printf("\npivot %d\n",p);*/
    return p;
}

void quicksort(int left ,int right)
{
    int pivot;
    /*if(right-left==1)
    {

    }
    else if(right -left==2)
    {

    }*/
    if(left<right)
    {
        pivot=partion(left,right);
        quicksort(left,pivot-1);
        quicksort(pivot+1,right);
    }
}

int main()
{
  cout<<"Enter the number"<<endl;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  int low=0,high=n-1;
  quicksort(low,high);
  cout<<"After sorting:"<<endl;
  for(int i=0;i<n;i++)
  {
      cout<<a[i]<<" ";
  }
  return 0;
}

