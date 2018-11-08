#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define pi acos(-1)
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define sf scanf
#define pf printf
#define LL long long int
using namespace std;
int main()
{
    //freopen("1.txt","r",stdin);
    list<int>q;
    int i,j,k;
    for(i=0;i<=4;i++)
    {
        cin>>k;
        q.push_front(k);
    }
    for(i=0;i<=4;i++)
    {
        cout<<q.front()<<endl;
        q.pop_front();
    }
    cout<<q.size()<<endl;
    return 0;
}

