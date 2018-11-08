#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define pi acos(-1)
#define sf scanf
#define pf printf
#define ll long long int
using namespace std;
float abs_val(float x)
{
    if(x<0)
    {
        x=-x;
    }
    return x;
}
float sqr_root(float a)
{
    float limit =0.00001;
    float x=1.0;
    int i=0;
    while(abs_val(x*x-a)>=limit)
    {
        x=(x+a/x)/2.0;
        i++;
    }
    printf(" loop %d\n",i);
    return(x);
}
int main()
{
    //freopen("1.txt","r",stdin);
    float n;
    scanf("%f",&n);
    printf("%f\n",sqr_root(n));
    main();
    return 0;
}
