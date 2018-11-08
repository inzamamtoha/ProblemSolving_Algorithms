#include<bits/stdc++.h>
using namespace std;
char a[100];
int palindrome(int low,int high)
{
    if(low>high)
    {
        return 1;
    }
    else if (a[low]!=a[high])
    {
        return 0;
    }
    return palindrome(low+1,high-1);
}
int main()
{
    cin>>a;
    int l = strlen(a)-1;
    int x = palindrome(0,l);
    if(x)
    {
         puts("Palindrome");
    }
    else
    {
        puts("NOt palindrome");
    }
    main();
}
