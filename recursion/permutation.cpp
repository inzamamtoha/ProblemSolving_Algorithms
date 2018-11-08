#include<bits/stdc++.h>
using namespace std;
char ch[]={'0','1','2','3','4','5'};
vector<char>result;
int taken[20]={0},flag=1;
void permutation()
{
    int i;
    if(result.size()==4)
    {
        for(i=0;i<result.size();i++)
        {
            printf("%c ",result[i]);
        }
        puts(" ");
        return ;
    }
    for(i=1;i<=4;i++)
    {

        if(taken[i]==0 && flag)
        {
            taken[i]=i;
            result.push_back(ch[i]);
            permutation();
            taken[i]=0;result.pop_back();
        }
    }

}
int main()
{
    permutation();
}
