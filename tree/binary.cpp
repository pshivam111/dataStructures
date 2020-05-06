#include<stdio.h>
#include<stdlib.h>

/******************************************************************************************************************
Structure of  node
It consist data variable and two pointers for pinting its left and rightr node.*/
 struct node
 {
	int data;
	struct node *left;
	struct node *right;
 
 };
struct node *root=NULL;

 /************************************************************************************************************************
 This function creates node and assign data to the node provided in the function parameter. */
 
 struct node *createNode(int x)
 {
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->left==NULL;
	temp->right==NULL;
	temp->data=x;
	return temp; 
 }

 /****************************************************************************************************
 BSTinorder traversal recursive*/
 void Recursive_Inorder(struct node *root)
 {
	if(root!=NULL)
	{
		Recursive_Inorder(root->left);
		printf("%d",root->data);
		Recursive_Inorder(root->right);
	}
 }
 /****************************************************************************************************
 BSTpreorder traversal recursive*/
 void Recursive_Preorder(struct node *root)
 {
	if(root!=NULL)
	{
		printf("%d",root->data);
		Recursive_Preorder(root->left);
		Recursive_Preorder(root->right);
	}
 }
 
 /****************************************************************************************************
 BSTpostorder traversal recursive*/
 void Recursive_Postorder(struct node *root)
 {
	if(root!=NULL)
	{
		Recursive_Postorder(root->left);
		Recursive_Postorder(root->right);
		printf("%d",root->data);
	}
 }
 
/*************************************************************************************************************************
 This function inserts node to tree in non recursive way.*/
struct node *nonrecInsertion(struct node *root,struct node *data)
 {
    struct node *saved_root=root;
 	if(root==NULL)
 	{
 	    return data;
 	}
 	else
 	{
 	 	while(1)
 	 	{
 	 		if(root->data>data->data)
		 	{
		 	 	if(root->left==NULL)
	 	  		{   root->left=data; break;     }
		 	  	else { root=root->left; }
		 	 }
		 	 else
		 	 {
		 	 	if(root->right==NULL)
		 	 	{   root->right=data; break;    }
		 	    else { root=root->right; }
	 		 } 		
	 	}
    }
    return saved_root;
 }

void insertData(int x)
{
	root=nonrecInsertion(root,createNode(x));
}
int main()
{
	insertData(5);
	insertData(7);
	insertData(3);
	insertData(1);
	insertData(4);
	insertData(6);
	insertData(8);

	Recursive_Preorder(root);
	printf("\n");
	Recursive_Inorder(root);
	printf("\n");
	Recursive_Postorder(root);
	printf("\n");
}