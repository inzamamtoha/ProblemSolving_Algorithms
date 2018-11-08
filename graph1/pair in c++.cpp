#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    pair<string,int>p1("toha",85);
    pair<int,int>p2;
    p2=make_pair(12,2);
    cout<<p1.first<<endl;
    cout<<p1.second<<endl;
    cout<<p2.first<<endl;
    cout<<p2.second<<endl;
    return 0;

}
