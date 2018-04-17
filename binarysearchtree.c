#include<stdio.h>
#include<stdlib.h>

typedef struct np
{
	int key;
	struct np *left, *right;
}node;

node *root = NULL;

node *newnode(int x)
{
	node *temp = (node *)malloc(sizeof(node));
	
	temp->key = x;
	temp->left = temp->right = NULL;
	
	return temp;
}


void inorder(node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d \n",root->key);
		inorder(root->right);
	}
}

void preorder(node *root)
{
	if(root != NULL)
	{
		printf("%d \n",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d \n",root->key);
	}
}


node *insert(node *node,int key)
{
	if(node == NULL)
		return newnode(key);
	
	if(key < node->key)
		node->left = insert(node->left,key);
	
	else if(key > node->key)
		node->right = insert(node->right,key);
	
	return node;
}

node *search(node *root,int key)
{
	if(root == NULL || root->key == key)
	return root;
	
	if(root->key < key)
	return search(root->right,key);
	
	else if(root->key > key)
	return search(root->left,key);
}

int main()
{
	int value,ele;
	int choice;
	char ch;
	root = newnode(1)	;
	do
	{
		do
		{
			printf("\n BST MENU");
			printf("\n    1.   Insert Node");
			printf("\n    2.   Inorder traversal");
			printf("\n    3.   Preorder traversal");
			printf("\n    4.   Postorder traversal");
			printf("\n    5.   Search");
			printf("\n    6.   Exit");
			printf("\n Enter your choice:");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:printf("\n Enter the value to be inserted into tree:");
				       scanf("%d",&value);
				       insert(root,value);
				       break;
				       
				case 2:printf("\n Inorder traversal:");
				       inorder(root);
					   break;
					   
				case 3:printf("\n Preorder traversal:");
				       preorder(root);
					   break;
					   
				case 4:printf("\n Postorder traversal:");
				       postorder(root);
					   break;
					   
				case 5:printf("\n Enter the value to be searched:");
				       scanf("%d",&ele);
					   printf("%d",search(root,ele));
					   break;	   
					   	   
				default:printf("\n !!!!WRONG CHOICE!!!!");
				        break;	   	   	          
			}
		}
		while(choice != 6);
		printf("\n Do you wish to continue?");
		getchar();
		scanf("%c",&ch);
	}
	while(ch == 'y' || ch == 'Y');
}
