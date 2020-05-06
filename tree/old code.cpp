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
 {Recursive_Inorder(root->left);
 printf("%d",root->data);
 Recursive_Inorder(root->right);
 }
 }
 /****************************************************************************************************
 BSTpreorder traversal recursive*/
 void Recursive_Preorder(struct node *root)
 {
 if(root!=NULL)
 {printf("%d",root->data);
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
 This function inserts node to tree*/
 struct node *BSTnodeInsertion(struct node *root,struct node *data)
 {
 	if(root==NULL)
 	{
 	return data;
 	}
 	else if(root->data>data->data)
 	{
 	root->left=BSTnodeInsertion(root->left,data);
 	}
 	else if(root->data<data->data)
 	{
 	root->right=BSTnodeInsertion(root->right,data);
 	}
 }

/*************************************************************************************************************************
 This function inserts node to tree in non recursive way.*/
struct node *nonrecInsertion(struct node *root,struct node *data)
 {
 struct node *sroot=root;
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
	 	  		{
		 	  	root->left=data; break;
		 	  	}
		 	  	else { root=root->left; }
		 	 }
		 	 else
		 	 {
		 	 	 if(root->right==NULL)
		 	 	 {
		 	  	root->right=data; break;
		 	  	 }
		 	  	else { root=root->right; }
	 		 }
 	
 		
	 	}
    }
     return sroot;
 }
 
 /*****************************************************************
 Function to delete a node without parent pointer in the node*/ 
 void delete(struct node *data)
 {
 struct node *mover=data;
 struct node *parent_mover;
 if(mover->right!=NULL)
 {
 	parent_mover=mover;
  	mover=mover->right;
  	
  	if(mover->left!=NULL)
  	{	while(mover->left!=NULL)
  		{
	  	parent_mover=mover;
  		mover=mover->left;
  		}
  	
  	  parent_mover->left=mover->right;
  	  data->data=mover->data;
  	  free(mover);
  	}
  	else
  	{
  	 parent_mover->right=mover->right;
  	 data->data=mover->data;
  	 free(mover);
  	}
 }
 else if(mover->left!=NULL)
 {
	 parent_mover=mover;
	 mover=mover->left;
	 if(mover->right!=NULL)
	 {
	 	while(mover->right!=NULL)
	 	{
	 	parent_mover=mover;
	 	mover=mover->right;
	 	}
	 	
	   parent_mover->right=mover->left;
	   data->data=mover->data;
	   free(mover);
 	}
 	else
 	{
 	parent_mover->left=mover->left;
 	data->data=mover->data;
 	free(mover); 	
 	}
 }
 else
  {free(mover);}
 }
 
 
 /*********************************************************8
   */

 /*
 int main()
 {
 int q=1,t;
 struct rbnode *gen;
 while(q!=2)
 {
 printf("\n Menu driven program for red black tree");
 printf("\n1.Bst insertion.");
 printf("\n2.Bst recursive Inorder traversal.");
 printf("\n3.Bst recursive Preorder traversal.");
 printf("\n4.Bst recursive Postorder traversal.");
 printf("\n5.Bst nonrecursive Inorder traversal.");
 printf("\n6.Bst nonrecursive Preorder traversal.");
 printf("\n7.Assign balance factor to all nodes.");
 scanf("%d",&q);
 switch(q)
 {
 case 1:printf("\n Enter node data.\n ");
 	   scanf("%d",&t);
 	   gen=createNode(t);
 	   root=nonrecRBInsertion(root,gen);
 	   printf("%d",root->data);
 	   break;
 case 2:q=2;break;
 default: printf("Please enter correct option.");  
 }
 
 }
 
 
printf("%d",root->left->parent->data);
 free(root);
 return 0;
 }*/
 
 void main()
 {
 struct node *root;
 printf("fgh");
 root = BSTnodeInsertion(root,createNode(2)); printf("b");
 root = BSTnodeInsertion(root,createNode(1)); printf("c");
 root = BSTnodeInsertion(root,createNode(3)); printf("d");
 
 Recursive_Preorder(root);
 Recursive_Inorder(root);
 Recursive_Postorder(root);
 }