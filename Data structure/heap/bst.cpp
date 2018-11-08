#include <bits/stdc++.h>
using namespace std;
///Noboni
struct bstnode
{
    int value;
    bstnode* leftnode;
    bstnode* rightnode;
    int cnt;
};
bstnode* getnewnode(int data)
{
    bstnode* newnode=new bstnode();
    newnode->value=data;
    newnode->rightnode=newnode->rightnode=NULL;
    return newnode;
}
bstnode* Insert(bstnode* root,int data)
{
    if(root==NULL)
    {
        root=getnewnode(data);
    }
    else if(data<=root->value)
    {
        root->leftnode=Insert(root->leftnode,data);
    }
    else if(data>root->value)
    {
        root->rightnode=Insert(root->rightnode,data);
    }
    return root;

}
bool Search(bstnode* root,int data)
{
    if(root==NULL) return false;
    else if(root->value==data) return true;
    else if(data<=root->value)
    {
         return Search(root->leftnode,data);
    }
    else
         return Search(root->rightnode,data);


}
int Findmin(bstnode* root)
{
    if(root==NULL)
    {
    printf("Empty Tree");
    return -1;
    }
    else if(root->leftnode==NULL)
        return root->value;
    return Findmin(root->leftnode);
}
bstnode* Findminn(bstnode* root)
{
    if(root==NULL)
    {
    printf("Empty Tree");
    return root;
    }
    else if(root->leftnode==NULL)
        return root;
    return Findminn(root->leftnode);
}
int Findmax(bstnode* root)
{
    if(root==NULL)
    {
    printf("Empty Tree");
    return -1;
    }
    else if(root->rightnode==NULL)
        return root->value;
    return Findmin(root->rightnode);
}
bstnode* Delete(struct bstnode* root,int data)
{
    if(root==NULL)
    {
    printf("Empty Tree");
    return root;
    }
    else if(data<root->value)
    {
        root->leftnode=Delete(root->leftnode,data);

    }
    else if(data>root->value)
    {
        root->rightnode=Delete(root->rightnode,data);
    }
    else
    {
        if(root->leftnode==NULL && root->rightnode==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->leftnode==NULL)
        {
            struct bstnode* temp=root;
            root=root->rightnode;
            delete temp;
        }
        else if(root->rightnode==NULL)
        {
            struct bstnode* temp=root;
            root=root->leftnode;
            delete temp;
        }
        else
        {
            struct bstnode* temp=Findminn(root->rightnode);
            root->value=temp->value;
            root->rightnode=Delete(root->rightnode,data);
        }
        return root;
    }
}
void preorder(struct bstnode* root)
{
    if(root==NULL)return;
    printf("%d ",root->value);
    preorder(root->leftnode);
    preorder(root->rightnode);
}
void postorder(struct bstnode* root)
{
    if(root==NULL)return;
    postorder(root->leftnode);
    postorder(root->rightnode);
    printf("%d ",root->value);
}
void inorder(struct bstnode* root)
{
    if(root==NULL)return;
    inorder(root->leftnode);
    printf("%d ",root->value);
    inorder(root->rightnode);

}
main()
{
    bstnode* root=NULL;
    root=Insert(root,10);
    root=Insert(root,2);
    root=Insert(root,15);
    root=Insert(root,5);
    root=Insert(root,1);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    root=Delete(root,15);
    if(Search(root,9))
        printf("FOUND\n");
    else
        printf("NOT FOUND\n");
    int k=Findmax(root);
    printf("%d",k);

    return 0;
}
