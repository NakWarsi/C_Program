#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* left;
struct node* right;
};

//creating new node
struct node* new_node(int data)
{
struct node* node=(struct node*)malloc(sizeof(struct node));

node->data=data;
node->left=NULL;
node->right=NULL;
return (node);
}


void print_preorder(struct node* node)
{
if(node== NULL)
return;

printf("%d ",node->data);
print_preorder(node->left);
print_preorder(node->right);
}

void print_inorder(struct node* node)
{
if(node==NULL)
return;

print_inorder(node->left);
printf("%d ",node->data);
print_inorder(node->right);
}

void print_postorder(struct node* node)
{
if(node==NULL)
return;
print_postorder(node->left);
print_postorder(node->right);
printf("%d ",node->data);
}

int main()
{
struct node *root=new_node(1);

root->left=new_node(2);
root->right=new_node(3);
root->left->left=new_node(4);
root->left->right=new_node(5);

printf("...................preorder traversal.....................\n");
print_preorder(root);
printf("\n...................inorder traversal......................\n");
print_inorder(root);
printf("\n...................postorder traversal....................\n");
print_postorder(root);

return 0;}
