///Md. Inzamam-Ul-Haque
///Roll:85
///Asif Sir
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int Value;
	struct Node *Next;
};

struct Node *Head, *LL, *Temp,*pot,*pot_n,*love;//Globally Declared node type struct pointer

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
void Menu()
{
	printf("\n 1. Create a Linked List");
	printf("\n 2. Insert a value into a Linked List (at the end)");
	printf("\n 3. Insert a value into a Linked List (after a specific value)");
	printf("\n 4. Insert a value into a Linked List (before a specific value)");
	printf("\n 5. Update a value with another value");
	printf("\n 6. Delete a value from the Linked List");
	printf("\n 7. Delete a value which is before a specific value");
	printf("\n 8. Delete a value which is after a specific value");
	printf("\n 9. Print the Linked List");
	printf("\n10. Print the Linked List in Reverse Order (For Bonus Marks)");
	printf("\nEnter your Choice : (1-10, 0 to exit):");
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

	/*
		printf("\n 3. Insert a value into a Linked List (after a specific value)");
	*/
	/*
		This is function, you have to scan two values, Say U and V. Then V will be inserted after the first occurence of U. That is,
		whenever you will find the first U, you have to insert V after that node. There might be some part of the Linked list after the U,
		and that Link will be added now after V.
		Example: Current status: 7 19 3 4 84
		Insert 5 after 3, the Linked list will be
		7 19 3 5 4 84
	*/

	printf("You have selected Option 3 (Insert a value into a Linked List (after a specific value))\n");
    int V,U;
	LL = Head;

	printf("Enter an integer to insert into the Linked List(after a specific value):\n");
	scanf("%d",&V);

	printf("Enter the specific value From the Linked List:\n");
	scanf("%d",&U);

	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
	}
	else
    {
        pot=Head;
        while(pot->Value!=U)//searching the specific value
        {
            pot=pot->Next;
        }
        Create_A_Node(V);
        if(pot->Next==NULL)//if it is last element of list
        {
            pot->Next=Temp;
        }
        else //if we put the value in the middle of the list
        {
            pot_n=pot->Next;
            pot->Next=Temp;
            Temp->Next=pot_n;
        }
	}

}

void Option4()
{
	/*
	printf("\n 4. Insert a value into a Linked List (before a specific value)");
	*/
	printf("You have selected Option 4 (Insert a value into a Linked List (before a specific value))\n");
    int V,U,c=0;
	LL = Head;
	printf("Enter an integer to insert the Linked List(before a specific value)):\n ");
	scanf("%d",&V);

	printf("Enter the specific value From the Linked List:\n ");
	scanf("%d",&U);

	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
	}
	else {
        pot=Head;
        LL=Head;
        while(LL->Value!=U)
        {
            LL=LL->Next;
            if(c!=0)
                pot=pot->Next;//save previous  node address
            c++;
        }

        Create_A_Node(V);
        if(pot==Head && c==0)//if only head exists
        {
            Head=Temp;
            Head->Next=pot;
        }
        else {
            pot_n=pot->Next;
            pot->Next=Temp;
            Temp->Next=pot_n;
        }
	}


}

void Option5()
{
	printf("You have selected Option 5\n");
	/*
	printf("\n 5. Update a value with another value");
	*/
	int V,U;

    printf("Enter an integer to update the Linked List :\n ");
    scanf("%d",&V);
    printf("Enter the value From the Linked List which you want to update : \n");
    scanf("%d",&U);
    LL=Head;
	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
	}
	else
    {
        pot=Head;
        while(1)
        {
            if(pot->Value==U)//searching
                pot->Value=V;
            if(pot->Next==NULL)
            {
                break;
            }
            pot=pot->Next;
        }
    }
}

void Option6()
{
	printf("You have selected Option 6\n");
	/*
	printf("\n 6. Delete a value from the Linked List");
	*/
    printf("Enter the value From the Linked List which you want to delete : \n");
    int V,c=0;
	scanf("%d",&V);

	LL=Head;

	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
	}
	else
    {
        pot=Head;
        LL=Head;
        while(1)
        {
            if(LL->Value==V)
            {
                break;
            }
            if(c!=0)
            {
                pot=pot->Next;
            }
            c++;
            LL=LL->Next;
        }
        if(pot==Head && c==0)
         {
            if(Head->Next==NULL)
            {
                Head=NULL;
            }
            else
            {
                Head=Head->Next;
            }
         }
       else if(LL->Next==NULL)
        {
            pot->Next=NULL;
        }
       else {
            pot->Next=LL->Next;
        }
    }
}

void Option7()
{
	printf("You have selected Option 7\n");
	/*
	printf("\n 7. Delete a value which is before a specific value");
	*/

	int U,c=0;
    printf("Enter the value From the Linked List which you want to delete before the specific value : \n");
	scanf("%d",&U);
	pot=Head;
    LL=Head;
    love=Head;
    while(1)
    {
        if(LL->Value==U)
            break;
        if(c!=0)
            pot=pot->Next;
        if(c>1)
            love=love->Next;
        c++;
        LL=LL->Next;
    }
    if(c==1)
    {
        Head=LL;
    }
    else if(c>1)
    {
        love->Next=LL;
    }
}

void Option8()
{
	printf("You have selection Option8\n");
	/*
	printf("\n 8. Delete a value which is after a specific value");
	*/

	int U;
    printf("Enter the value From the Linked List which you want to delete after the specific value : ");
	scanf("%d",&U);
    LL=Head;
    while(1)
    {
        if(LL->Value==U)
            break;
        LL=LL->Next;
    }
    if(LL->Next->Next==NULL)
        LL->Next=NULL;
    else if(LL->Next->Next!=NULL)
        LL->Next=LL->Next->Next;

}

void Option9()
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

void Option10()
{
	printf("You have selected Option 10\n");
	/*
	printf("\n10. Print the Linked List in Reverse Order (For Bonus Marks)");
	*/
	int V;
	LL=Head;
	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		puts("Enter an ineger to create Node");
		scanf("%d",&V);
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		Head = Temp;	// Now the Head will Point to the Temp;
	}
    else
    {
        pot=Head;
        pot_n=NULL;
        LL=Head;
        while(LL!=NULL)//LL traverse till NULL
        {
            pot=LL->Next;//save next memory address
            LL->Next=pot_n;//swaping(at first NULL)
            pot_n=LL;
            LL=pot;
        }
        Head=pot_n;//Creating New head
        puts("Linked List is Reversed");
    }

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
	else if(Ch==9)  Option9();
	else if(Ch==10) Option10();
}

void main()
{
	int Choice;
	while(1)
	{
		Menu();
		scanf("%d", &Choice);
		if(Choice==0)
			break;
		else if(Choice<0 || Choice>10)
			printf("Wrong input\n");
		else
			SelectOptions(Choice);
	}

}

