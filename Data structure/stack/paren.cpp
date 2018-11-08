#include<bits/stdc++.h>
using namespace std;
stack<char>st;
int main()
{
    int i,j,k,n,c=0;
    char a[100],ch;
    cin>>a;
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]=='['||a[i]=='('||a[i]=='{')
            {
                st.push(a[i]);
            }
        else if((a[i]==']'||a[i]==')'||a[i]=='}'))
        {
            ch=st.top();
            if(a[i]==']')
            {
                if(ch!='[')
                {
                    c=1;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(a[i]=='}')
            {
                if(ch!='{')
                {
                    c=1;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(a[i]==')')
            {
                if(ch!='(')
                {
                    c=1;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    int sz=st.size();
    if(c==1||sz!=0)
    {
        puts("Eror");
    }
    else
    {
        puts("Right");
    }
    return 0;
}

