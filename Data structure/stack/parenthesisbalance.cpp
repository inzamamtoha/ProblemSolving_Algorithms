#include<bits/stdc++.h>
using namespace std;
int sz=0;
struct Node
{
	char Value;
	struct Node *Next;
};

struct Node *Head, *LL, *Temp,*Tail,*pot,*pot_n,*love;//Globally Declared node type struct pointer
void Create_A_Node(char V)
{
	Temp = (struct Node *)malloc(sizeof(struct Node));//Dynamic memory allocation

	if(!Temp)
	{
		printf("Something Wrong with Node Creation\n");
		exit(0);
	}
	else
	{
		Temp->Value = V;//assign value
		Temp->Next = NULL;//assign NULL
	}
}
void Free_A_Node(struct Node *A_Node)
{
	free(A_Node);//memory free
}
void push(char x)
{

    //printf("\nEnter a number: ");
    //cin>>x;
    LL=Head;
    if(sz==0)
    {
        Create_A_Node(x);
        Head=Temp;
    }
    else
	{
		while(LL->Next) // LL will traverse till the end of the Linked List or the Node that has Null in it's next
		{
			LL = LL->Next;
		}

		Create_A_Node(x); // Calling this function with V and the new Node will be created as Temp;
		LL->Next = Temp;
	}
    sz++;
}
void pop()
{
    LL = Head;
    if(sz==0)
    {
        //puts("No element in stack");
    }
    else if(sz==1)
    {
        Free_A_Node(Head);
        Free_A_Node(LL);
        sz--;
    }
    else
	{
        while(1)
            {
                if(LL->Next->Next==NULL)
                {
                  LL->Next=NULL;
                    break;
                }
                else
                   LL=LL->Next;
            }
		sz--;
	}
}
char top()
{
    LL=Head;
    if(sz==0)
    {
       // puts("No element in Stack");
    }
    else
    {
        int c;
        c=sz;
        while(--c)
        {
            LL=LL->Next;
        }
        return LL->Value;
        //printf("%c\n",LL->Value);
    }


}
void display()
{
    LL = Head;
    if(sz==0)
        return;
	while(LL!=NULL) // Or you can write while(LL)
	{
		printf("%d\n",LL->Value);
		LL= LL->Next;
	}
}
int main()
{
    int i,j,k,n,c=0;
    char a[100],ch;
    puts("Read a stream: ");
    cin>>a;
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]=='['||a[i]=='('||a[i]=='{')
            {
                push(a[i]);
            }
        else if((a[i]==']'||a[i]==')'||a[i]=='}'))
        {

            /*if(sz==0)
            {
                c=1;
                break;
            }*/
            ch=top();
            if(a[i]==']')
            {
                if(ch!='[')
                {
                    c=1;
                    break;
                }
                else
                {
                    pop();
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
                    pop();
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
                    pop();
                }
            }
        }
    }
    if(c==1||sz!=0)
    {
        puts("Unbalanced");
    }
    else
    {
        puts("Balanced");
    }
    return 0;
}

