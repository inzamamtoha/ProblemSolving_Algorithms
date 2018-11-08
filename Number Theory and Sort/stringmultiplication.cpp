#include<bits/stdc++.h>
#include<string.h>
using namespace std;
char *multiply(char a[],char b[])
{
  int i,j,k,length;
  length=strlen(a)+strlen(b);//total length
  char result[length];
  memset(result,'0',sizeof(result));
  int num,last_pos_i,last_pos_j,last_pos_k;
  last_pos_i=length-1;
  for(i=strlen(a)-1;i>=0;i--)
  {
      last_pos_j=last_pos_i;
      for(j=strlen(b)-1;j>=0;j--)
      {
        num = (b[j]-48)*(a[i]-48);
        last_pos_k=last_pos_j;
        while(num!=0)
        {
            num=num+(result[last_pos_k]-48);
            result[last_pos_k]=num%10+48;
            num=num/10;
            last_pos_k--;
        }
        last_pos_j--;
      }
      last_pos_i--;
  }

  result[length]='\0';
  char res[length];
  int flag=1;
  for(i=0,j=0;i<length;i++)
  {
      if(result[i]=='0'&&flag)
      {
        continue;
      }
      else
      {
          flag=0;
          res[j++]=result[i];
      }
  }
  res[j]='\0';
  if(j==0)
    return "0";
  else
    return res;
}
char *integer_to_string(int num)
{
    int i,j,d;
    d=log10(num)+1;
    char a[d];
    for(i=d-1;i>=0;i--)
    {
        a[i]=num%10+48;
        num=num/10;
    }
    return a;
}

int main()
{
    char a[100], b[1000];
    int n;
    while(scanf("%d",&n)==1)
    {
        char fact[100000]="1";
        for(int i=1;i<=n;i++)
        {
            strcpy(a,integer_to_string(i));

            strcpy(fact,multiply(fact,a));
        }
        puts(fact);
    }

    return 0;
}
