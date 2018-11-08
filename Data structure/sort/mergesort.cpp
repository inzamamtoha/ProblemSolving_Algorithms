#include<stdio.h>
int ii=0,jj=0,kk=0;

void merge(int arr[],int min,int mid,int max);
void mergesort(int arr[],int min,int max)
{
 int mid;
 //printf("suru :%d %d %d\n",min,max,mid);
 if(min<max)
 {
   mid=(min+max)/2;
  // printf("first %d: %d %d %d\n",++ii,min,max,mid);
  mergesort(arr,min,mid);
  //printf("second %d: %d %d %d\n",++jj,min,max,mid);
  mergesort(arr,mid+1,max);
  //printf("third %d: %d %d %d\n",++kk,min,max,mid);
  merge(arr,min,mid,max);
 }
 return;
}


void merge(int arr[],int min,int mid,int max)
{
  printf("first %d: %d %d %d\n",++ii,min,max,mid);
  int tmp[30];
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}
int main()
{
 int arr[30];
 int i,size;
 printf("Enter total no. of elements : ");
 scanf("%d",&size);
 for(i=0; i<size; i++)
 {
   scanf("%d",&arr[i]);
 }
 mergesort(arr,0,size-1);
 printf("\nAfter sorting: \n");
 for(i=0; i<size; i++)
        printf("%d ",arr[i]);
 return 0;
}
