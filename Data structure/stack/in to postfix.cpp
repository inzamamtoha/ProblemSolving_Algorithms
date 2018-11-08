#include<bits/stdc++.h>
using namespace std;///vul code
stack<char>box;
int main()
{
    int i,j=0,k,len;
    char a[100],b[100],ch,cg;
    cin>>a;///5*(6+2)-8/4
    len=strlen(a);
    //cout<<a<<endl;
    for(i=0;i<len;i++)
    {
        if(a[i]>=48&&a[i]<=47)
        {
            b[j++]=a[i];
        }
        else if(box.empty()||a[i]=='(')
        {
            box.push(a[i]);
        }
        else if(a[i]==')')
        {
            ch=box.top();
            while(ch!='(')
            {
                b[j++]=ch;
                box.pop();
                ch=box.top();
            }
            box.pop();
        }
        else if(a[i]=='+'||a[i]=='-')
        {
            ch=box.top();
            if(ch=='*'||ch=='/')
            {
                b[j++]=ch;
                box.pop();
                box.push(a[i]);
            }
            else if(ch=='+'||ch=='-')
            {
                b[j++]=ch;
                box.pop();
                box.push(a[i]);
            }
        }
    }
    b[j]='\0';
    cout<<b<<endl;
    return 0;
}

