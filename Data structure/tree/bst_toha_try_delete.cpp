#include<stdio.h>
#include<stdlib.h>
int flag,check;
struct node
{
    int num;
    int cnt;
    int frq;
    struct node *right;
    struct node *left;
};

struct node *insert(struct node *temp1,int num)
{
    if(temp1==NULL)
    {
        temp1=(struct node *)malloc(sizeof(struct node));
        temp1->num=num;
        temp1->cnt=1;
        temp1->left=NULL;
        temp1->right=NULL;
        return temp1;
    }
    else
    {
        if(num<temp1->num){
            temp1->left=insert(temp1->left,num);
        }
        else if(num>temp1->num)
        temp1->right=insert(temp1->right,num);
        else
        temp1->cnt++;
        return temp1;
    }
}
void Inorder(struct node  *temp)
{
    int i;
    if(temp!=NULL)
    {
        Inorder(temp->left);
        for(i=1;i<=temp->cnt;i++)
        {
            printf("%d ",temp->num);
        }
        Inorder(temp->right);
    }
}
void Preorder(struct node  *temp)
{
    int i;
    if(temp!=NULL)
    {
        for(i=1;i<=temp->cnt;i++)
        {
            printf("%d ",temp->num);
        }
        Preorder(temp->left);

        Preorder(temp->right);
    }
}
void postorder(struct node *temp)
{
    int i;
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        for(i=1;i<=temp->cnt;i++)
        {
            printf("%d ",temp->num);
        }

    }
}

int search(struct node *temp ,int v)
{
    if(temp!=NULL)
    {
        if(v==temp->num)
        {
            printf("FOUND\n");
            flag=1;
        }
        search(temp->left,v);
        search(temp->right,v);
    }

}
node* FindMin(node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}
struct node* Delete(struct node *root, int data)
{
    if(root == NULL) return root;
    else if(data < root->num) root->left = Delete(root->left,data);
    else if (data > root->num) root->right = Delete(root->right,data);
// Wohoo... I found you, Get ready to be deleted
    else {
    // Case 1: No child
    if(root->left == NULL && root->right == NULL) {

            if(root->cnt==0)
            {
                delete root;
                root = NULL;
            }
            else
            {
                root->cnt--;
            }
        }
        //Case 2: One child
    else if(root->left == NULL) {
    struct node *temp = root;
    root = root->right;
    delete temp;
    }
    else if(root->right == NULL) {
    struct node *temp = root;
    root = root->left;
    delete temp;
    }
    // case 3: 2 children
    else {
    struct node *temp = FindMin(root->right);
    root->num = temp->num;
    root->right = Delete(root->right,temp->num);
    }
    }
    return root;
}
int main()
{
    int i,n,data;
    struct node *head=NULL;
    while(1)
    {

        printf("press 1 to insert\n");
        printf("press 2 to inorder\n");
        printf("press 3 to preorder\n");
        printf("press 4 to postorder\n");
        printf("press 5 to search\n");
        printf("press 6 to delete\n");
        printf("press 7 to exit\n");
        scanf("%d",&n);
        if(n==1)
        {
            scanf("%d",&data);
            head=insert(head,data);
        }
        else if(n==2)
        {

            printf("Inorder\n");
            Inorder(head);
        }
        else if(n==3)
        {

            printf("\n preorder\n");
            Preorder(head);
        }
        else if(n==4)
        {
            printf("\n postorder\n");
            postorder(head);
        }
        else if(n==5)
        {
            flag=0;
            scanf("%d",&data);
            search(head,data);
            if(flag==0)
                printf("Not FOUND\n");
        }
        else if(n==6)
        {
            check=0;
            scanf("%d",&data);
            Delete(head,data);
        }
        else if(n==7)
            return 0;
        else   {
            printf("Invalid operation\n");
            continue;
        }
    }


}

