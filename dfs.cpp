#include<stdio.h>
#include<stdlib.h>

typedef struct np
{
	int data;
	struct np *left, *right;
}node;

node *root = NULL;

node *newnode(int x)
{
	node *temp = (node *)malloc(sizeof(node));
	if(NULL == temp)
	{
		printf("\n Malloc failed!!!!");
		exit(0);
	}
	
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}


node *insert(node *node,int data)
{
	if(node == NULL)
	return newnode(data);
	
	if(data < node->data)
	node->left = insert(node->left,data);
	
	else if(data > node->data)
	node->right = insert(node->right,data);
	
	return node;
}


node *search(node *root,int data)
{
	if(root == NULL || root->data == data)
	return root;
	
	if(data < root->data)
	return search(root->left,data);
	
	else if(data > root->data)
	return search(root->right,data);
}

void inorder(node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("\t %d",root->data);
		inorder(root->right);
	}
}

void preorder(node *root)
{
	if(root != NULL)
	{
		printf("\t %d",root->data);
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
		printf("\t %d",root->data);
	}
}

int main()
{
	int choice;
	int value,ele;
	char ch;
	
	root = newnode(5);
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

