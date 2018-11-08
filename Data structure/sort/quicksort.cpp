#include<bits/stdc++.h>
using namespace std;
int a[500],n,ii=0;

int partion(int left,int right)
{
    int i,p,pvt;
    p=left;
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
  for(int i=0;i<n;i++)
  {
      cout<<a[i]<<" ";
  }
  printf("\npivot index %d\n",p);
    return p;
}

void quicksort(int left ,int right)
{
    int pivot;
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
