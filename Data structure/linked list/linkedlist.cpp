///Asif Sir
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int Value;
	struct Node *Next;
};

struct Node *Head, *LL, *Temp,*Tail,*pot,*pot_n,*love;//Globally Declared node type struct pointer
void Create_A_Node(int V)
{
	//Temp = (struct Node *)malloc(sizeof(struct Node));//Dynamic memory allocation
      //Temp = new(Node);
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
void Option1()
{
	int V;
	printf("You have selected Option 1\n");


	if(Head==NULL) // That is, the Linked list is yet to create
	{
		printf("Enter an integer to create the Linked List ; ");
		scanf("%d",&V);
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
		printf("The Linked List is Created\n");
	}
	else
	{
		printf("The Linked List is already created\n");
	}


}
void Option2()
{
	int V;
	printf("You have selected Option 2 (Insert a value into a Linked List (at the end))\n");

	LL = Head;

	printf("Enter an integer to insert into the Linked List ; ");
	scanf("%d",&V);

	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
	}
	else
	{
		while(LL->Next) // LL will traverse till the end of the Linked List or the Node that has Null in it's next
		{
			LL = LL->Next;
		}

		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		LL->Next = Temp; // That newly created node will be added to the end of the linked list (as the LL is now at the last node after traversing Linked List
		printf("Data Inserted at the end of the Linked List\n");
	}
}
void Option3()
{
	int V;
	printf("You have selected Option 3 (Insert a value into a Linked List (at the start))\n");

	LL = Head;

	printf("Enter an integer to insert into the Linked List ; ");
	scanf("%d",&V);

	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
	}
	else
	{
	    Create_A_Node(V);
        Head = Temp;
        Head->Next = LL;
		printf("Data Inserted at the start of the Linked List\n");
	}
}
void Option4()
{
	int V,x;
	printf("You have selected Option 4 (Insert a value into a Linked List (at any position))\n");

	LL = Head;
	printf("Enter an integer to insert into the Linked List ; ");
	scanf("%d",&V);
	cout<<"Enter the position: "<<endl;
	cin>>x;


	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
	}
	else if(x==1)
    {
        Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;
		Head->Next=LL;
		printf("Data Inserted at the start of the Linked List\n");
    }
	else
	{
	    Create_A_Node(V);
        pot= Temp;
        for(int i=1;i<x;i++)
        {
            LL=LL->Next;
        }
        pot_n=LL->Next;
        LL->Next=pot;
        pot->Next=pot_n;
		printf("Data Inserted at %d position of the Linked List\n",x);
	}
}
void Option5()
{
	printf("You have selected Option 5 (delete a value into a Linked List (at the end))\n");

	LL = Head;

	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
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
		printf("Data deleted at the end of the Linked List\n");
	}

}
void Option6()
{
	printf("You have selected Option 6 (delete a value into a Linked List (at the start))\n");

	LL = Head;

	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
	}
	else
	{
	    if(LL->Next==NULL)
        {
          Free_A_Node(LL);
        }
        else
        {
            Head=LL->Next;
        }
		printf("Data deleted at the start of the Linked List\n");
	}

}
void Option7()
{
	int V=0,x;
	printf("You have selected Option 7 (Delete a value into a Linked List (at any position))\n");

	LL = Head;
	cout<<"Enter the position: ";
	cin>>x;


	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
	}
	else if(x==1)
    {
        if(LL->Next==NULL)
        {
            Free_A_Node(LL);
		    printf("Data deleted at the %d of the Linked List\n",x);
        }
        else
        {
            Head=LL->Next;
        }

    }
	else
	{
        for(int i=1;i<x-1;i++)
        {
            LL=LL->Next;
        }
        if(V==0)
        {
            pot_n=LL->Next->Next;
            LL->Next=pot_n;
            printf("Data Deleted at %d position of the Linked List\n",x);
        }
	}
}
void Option8()
{
	printf("You have selection Option 9\n");
	/*
	printf("\n 9. Print the Linked List");
	*/

	LL = Head;
	while(LL!=NULL) // Or you can write while(LL)
	{
		printf("%d\n",LL->Value);
		LL= LL->Next;
	}

}
void Menu()
{
	printf("\n 1. Create a Linked List");
	printf("\n 2. Insert a value into a Linked List (at the end)");
	printf("\n 3. Insert a value into a Linked List (at the start)");
	printf("\n 4. Insert a value into a Linked List (at any position)");
	printf("\n 5. Delete a value into a Linked List (at the end)");
	printf("\n 6. Delete a value into a Linked List (at the start)");
	printf("\n 7. Delete a value into a Linked List (at any position)");
	printf("\n 8. Print the Linked List");
	printf("\nEnter your Choice : (1-8, 0 to exit):");
}
void SelectOptions(int Ch)
{
	if(Ch==1)	    Option1();
	else if(Ch==2)  Option2();
	else if(Ch==3)  Option3();
	else if(Ch==4)  Option4();
	else if(Ch==5)  Option5();
	else if(Ch==6)  Option6();
	else if(Ch==7)  Option7();
	else if(Ch==8)  Option8();
}
int main()
{
	int Choice;
	while(1)
	{
		Menu();
		scanf("%d", &Choice);
		if(Choice==0)
			break;
		else if(Choice<0 || Choice>8)
			printf("Wrong input\n");
		else
			SelectOptions(Choice);
	}

}
