#include<stdio.h>
#define N 10000
int que[N],frnt;
int sz=0;
void push(char ch)
{
     if(sz==N)
    {
        puts("Eror:queue is full");
    }
    else
    {
        que[sz]=ch;
        sz++;
    }
    frnt=que[0];
}
void pop()
{
    int i;
    if(sz==0)
    {
        puts("Eror:queue is empty");
    }
    else
    {
        for( i=0;i<=sz-1;i++)
        {
            que[i]=que[i+1];
        }
        sz--;
        if(sz==0)
            frnt=NULL;
    }
}
int size()
{
    return sz;
}
int front()
{
    if(sz==0)
        puts("Empty");
    else
        return frnt;
}
int main()
{
  int i=5;
   push('5');
   printf("%c\n",front());
   push('2');
   pop();
   push('4');
   printf("%d\n",size());
  return 0;
}

