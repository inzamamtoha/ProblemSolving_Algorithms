#include<bits/stdc++.h>
using namespace std;
int B[100],n,sz,mp;
void counting_sort(int A[], int k, int n)
{
    int j,i;
    int C[k+1]={0};
    for (j = 1; j <= n; j++)
    {// keep A[j] in C[A[j]]
        A[j]=A[j]+mp;//mapping
        C[A[j]] ++;
        //printf("%d\n",A[j]);

    }
    for (i = 1; i <=sz; i++)
    {// cumulative sum
        C[i] = C[i] + C[i-1];
       // printf("%d\n",C[i]);
    }
    for (j = n; j >= 1; j--)	// put the sorted array in B
    {
        A[j]= A[j]-mp;//mapping to real value
        int id =A[j]+mp;
        B[C[id]] = A[j];
        C[id]--;
    }
  cout<<"After sorting:"<<endl;
  for(int i=1;i<=n;i++)
  {
      cout<<B[i]<<" ";
  }
}
int main()
{
    int a[100];
    int mx,mn;
  cout<<"Enter the number"<<endl;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
      if(i==1)
      {
          mx=a[i];
          mn=a[i];
      }
      else
      {
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
      }
  }
    sz=mx-mn+1;
    mp=sz-mx;
   // printf("%d %d\n",sz,mp);
  counting_sort(a,sz,n);
  return 0;
}

