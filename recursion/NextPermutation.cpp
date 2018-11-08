#include<bits/stdc++.h>
using namespace std;
char ch[]={'1','2','3','4','5','6'};
vector<int>result;
int taken[20]={0};
int main()
{
    int i,j,s=0;
    int a[100];
    for(i=0;i<4;i++)
    {
        result.push_back(i+1);
    }
    do
    {
        for(i=0;i<result.size();i++)
        {
            printf("%d ",result[i]);
        }
        puts(" ");
    }while(next_permutation(result.begin(),result.end()));
    puts("toha");
    return 0;
}

