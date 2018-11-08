#include<bits/stdc++.h>
using namespace std;
int a[500],n,ii=0;
void merge(int low,int high,int mid)
{
    //printf("first %d: %d %d %d\n",++ii,low,high,mid);
    int i,j,k,l,m,p1,p2;
    int temp,tmp[500];
    p1=low;
    p2=mid+1;
    for(i=0;p1<=mid&&p2<=high;i++)
    {
        if(a[p1]<=a[p2])
        {
            tmp[i]=a[p1];
            p1++;
        }
        else
        {
            tmp[i]=a[p2];
            p2++;
        }
    }
    if(p1<=mid)
    {
        while(p1<=mid)
        {
            tmp[i]=a[p1];
            p1++;
            i++;
        }
    }
    else if(p2<=high)
    {
        while(p2<=high)
        {
            tmp[i]=a[p2];
            p2++;
            i++;
        }
     }
    for(k=low,j=0;k<=high;k++,j++)
    {
        a[k]=tmp[j];
    }


}
void mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,high,mid);
    }
    return ;
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
  mergesort(low,high);
  cout<<"After sorting:"<<endl;
  for(int i=0;i<n;i++)
  {
      cout<<a[i]<<" ";
  }
  return 0;
}
