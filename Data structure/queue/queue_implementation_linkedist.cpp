//queue implementation
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
    printf("\nEnter a number: ");
    cin>>x;
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
        puts("No element in queue");
    }
    else if(sz==1)
    {
        Free_A_Node(Head);
        Free_A_Node(LL);
        sz--;
    }
    else
	{
        LL=Head;
        Head=LL->Next;
		sz--;
	}
}
void top()
{
    LL=Head;
    if(sz==0)
    {
        puts("No element in Stack");
    }
    else
    {
        printf("%d\n",LL->Value);
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
void menu()
{
    puts("For push press 1");
    puts("For pop press 2");
    puts("For Front press 3");
    puts("For Display press 4");
    puts("For Exit press 0");
}
int main()
{
    int n;
    while(1)
    {
        menu();
        printf("\nEnter option No.: ");
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
    }
    return 0;
}
