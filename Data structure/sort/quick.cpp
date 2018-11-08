#include <stdio.h>

int median(int a, int b, int c)
{
    if(a>b)
    {
        if(a>c)
        {
            if(b>c)
            return b;
            else
            return c;
        }
    }
    else
    {
        if(b>c)
        {
            if(c>a)
            return c;
            else
            return a;
        }
    }
}

int quick_sort(int arr[100],int low,int high)
{
    int mid,pivot,j,temp,i,med;
    mid = (low+high)/2;
    if(low<high)
    {
        med=median(arr[low],arr[mid],arr[high]);
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
        i=low;
        j=high;

///partiontioning
    while(i<j)
    {
        while(arr[i]<=arr[pivot])
        {
            i++;
        }
        while(arr[j]>arr[pivot])
        {
            j--;
        }
        if(i<j)
        {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[pivot];
    arr[pivot]=arr[j];
    arr[j]=temp;
    quick_sort(arr,low,j-1);
    quick_sort(arr,j+1,high);
  }
}



int main()
{
  int arr[100],n,i,temp1;

  printf("Enter the size of array\n");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(i=0; i<n; i++)
    scanf("%d",&arr[i]);
  if(n==0)

      printf("There is no sorted element\n");
  else if(n==1)
       printf("there is only one element.The element is %d",arr[i]);
  else if(n==2)
       {
         if (arr[0]>arr[1])
         {
             temp1=arr[0];
             arr[0]=arr[1];
             arr[1]=temp1;

             printf("The Sorted Array\n");
             for(i=0;i<n;i++)
             printf("%d\n",arr[i]);
         }
         else{
           printf("The Sorted Array\n");
          for(i=0;i<n;i++)
             printf("%d\n",arr[i]);
         }
       }



   else if (n==3)
            {
                int a,b,c,max,min,mid;
                a=arr[0];
                b=arr[1];
                c=arr[2];

                if(a>b&&a>c)
                {
                    max=a;
                    if(b>c)
                    {
                        mid=b;
                        min=c;
                    }
                    else
                    {
                        mid=c;
                        min=b;
                    }
                }
                else if (b>a&&b>c)
                {
                    max=b;
                    if(a>c)
                    {
                        mid=a;
                        min=c;
                    }
                    else
                    {
                        mid=c;
                        min=a;
                    }
                }
                else if (c>a&&c>b)
                {
                    max=c;
                    if(a>b)
                    {
                        mid=a;
                        min=b;
                    }
                    else
                    {
                        mid=b;
                        min=a;
                    }
                }
                else if (a==b==c)
                {
                    max=mid=min=a=b=c;
                }
                printf("The sorted element is:%d\n%d\n%d\n",min,mid,max);

            }
  else{
    quick_sort(arr,0,n-1);
  printf("Sorted array:\n");
  for(i=0; i<n; i++)
    printf("%d\n",arr[i]);
  }


  return 0;
}
