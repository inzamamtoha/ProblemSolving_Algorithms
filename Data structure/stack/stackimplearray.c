#include<stdio.h>
#define N 10000
char stk[N],tp;
int sz=0;
void push(char ch)
{
     if(sz==N)
    {
        puts("Eror:stack is full");
    }
    else
    {
        stk[sz]=ch;
        sz++;
        tp=stk[sz-1];
    }

}
void pop()
{
    if(sz==0)
    {
        puts("Eror:stack is empty");
    }
    else
    {
        stk[sz-1]=NULL;
        sz--;
        tp=stk[sz-1];
    }
}
int size()
{
    return sz;
}
char top()
{
    if(sz==0)
        puts("Empty");
    else
        return tp;
}
int main()
{
  int i=5;
  pop();
  push('5');
 printf("%c\n",top());
  return 0;
}
