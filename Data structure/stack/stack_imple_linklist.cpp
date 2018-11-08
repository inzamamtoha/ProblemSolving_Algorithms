#include<bits/stdc++.h>
using namespace std;
int sz=0;
struct Node
{
	int Value;
	struct Node *Next;
};

struct Node *Head, *LL, *Temp,*Tail,*pot,*pot_n,*love;//Globally Declared node type struct pointer
void Create_A_Node(int V)
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
void push()
{
    int x;
    printf("Enter a number: ");
    cin>>x;
    Create_A_Node(x);
    if(sz==0)
    {
        Head=Temp;
        pot = Temp;
        pot_n=Head;
    }
    else
    {
        pot->Next=Temp;
        pot_n=pot;
        pot=Temp;
    }
    sz++;
}
void pop()
{
    if(sz==0)
    {
        puts("No element in stack");
    }
    else if(sz==1)
    {
        sz--;
        Head=NULL;
    }
    else
    {
        sz--;
        pot=pot_n;
        pot->Next=NULL;
        LL = Head;
        while(LL->Next->Next!=NULL) // Or you can write while(LL)
        {
            LL= LL->Next;
            pot_n=LL;
        }
    }
}
void top()
{
    printf("%d\n",pot->Value);
}
void display()
{
    LL = Head;
	while(LL!=NULL) // Or you can write while(LL)
	{
		printf("%d\n",LL->Value);
		LL= LL->Next;
	}
}
void menu()
{
    puts("For push press 1");
    puts("For pop press 2");
    puts("For Top press 3");
    puts("For Display press 4");
    puts("For Exit press 0");
}
int main()
{
    int n;
    while(1)
    {
        menu();
        cin>>n;
        if(n==0)
            break;
        else if(n==1)
            push();
        else if(n==2)
            pop();
        else if(n==4)
            display();
        else if(n==3)
            top();
        puts("");
    }
}
