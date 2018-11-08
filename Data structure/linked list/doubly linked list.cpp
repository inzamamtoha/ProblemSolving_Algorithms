#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int Value;
	struct Node *Next;
	struct Node *Prev;
};
struct Node *Head=NULL, *LL, *Temp,*Tail=NULL,*pot,*pot_n,*love;
void Create_A_Node(int V)
{
	Temp = (struct Node *)malloc(sizeof(struct Node));//Dynamic memory allocation

	if(!Temp)
	{
		printf("Something Wrong with Node Creation\n");
		exit(0);
	}
	else if(Head==NULL)
	{
	    Temp->Value = V;//assign value
		Temp->Next = NULL;//assign NULL
		Temp->Prev = NULL;
		Head=Temp;
		Tail=Temp;
	}
	else
	{
		Temp->Value = V;//assign value
		Temp->Next = NULL;//assign NULL
		Temp->Prev = Tail;
		Tail->Next=Temp;
		Tail=Temp;
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
		printf("Enter an integer to create the Linked List : ");
		scanf("%d",&V);
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		//Head = Temp;	// Now the Head will Point to the Temp;
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

	LL =Head;

	printf("Enter an integer to insert into the Linked List ; ");
	scanf("%d",&V);

	if(LL==NULL)
	{
		printf("There is No Linked List. So, the Linked list will be created First\n");
		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		//Head = Temp;	// Now the Head will Point to the Temp;
	}
	else
	{

		Create_A_Node(V); // Calling this function with V and the new Node will be created as Temp;
		printf("Data Inserted at the end of the Linked List\n");
	}
}
void Option8()
{
	printf("You have selection Option 8\n");
	/*
	printf("\n 8. Print the Linked List");
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
	/*printf("\n 3. Insert a value into a Linked List (at the start)");
	printf("\n 4. Insert a value into a Linked List (at any position)");
	printf("\n 5. Delete a value into a Linked List (at the end)");
	printf("\n 6. Delete a value into a Linked List (at the start)");
	printf("\n 7. Delete a value into a Linked List (at any position)");*/
	printf("\n 8. Print the Linked List");
	printf("\nEnter your Choice : (1-8, 0 to exit):");
}
void SelectOptions(int Ch)
{
	if(Ch==1)	    Option1();
	else if(Ch==2)  Option2();
	/*else if(Ch==3)  Option3();
	else if(Ch==4)  Option4();
	else if(Ch==5)  Option5();
	else if(Ch==6)  Option6();
	else if(Ch==7)  Option7();*/
	else if(Ch==8)  Option8();
}
int main()
{
    double st= clock();
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
	double en=clock();
	printf("time elapsed = %.15lf\n",en-st);
	return 0;

}
