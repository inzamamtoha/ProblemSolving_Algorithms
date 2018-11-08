#include<stdio.h>
#include<string.h>
int palindrome(char s[],int low,int high)
{
        if(low>high)
        {
          return 1;
        }
        else if(s[low]!=s[high])
        {
           return 0;
        }

        return palindrome(s,low+1,high-1);
}
int main()
{
    char a[100];
    int n,x,len;
    scanf("%s",a);
    len=strlen(a);
    x=palindrome(a,0,len-1);
    if(x==1)
        puts("Palindrome");
    else
        puts("Not palindrome");
}

