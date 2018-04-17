#define MAX 100

#include<stdio.h>
#include<stdlib.h>

typedef struct np
{
	int data;
	struct np *left, *right;
}node;

node *root = NULL;



node **createQueue(int *front,int *rear)
{
	node **queue = (node **)malloc(sizeof(node *)*MAX);
	
	*front = *rear = 0;
	return queue;
}

void enqueue(node **queue,int *rear,node *new_node)
{
	queue[*rear] = new_node;
	(*rear) += 1;
}

node *dequeue(node **queue,int *front)
{
	(*front) += 1;
	return queue[(*front) - 1];
}

void levelOrder(node *root)
{
	int front,rear;
	node **queue = createQueue(&front,&rear);
	node *temp_node = root;
	
	while(temp_node)
	{
		printf("\n %d",temp_node->data);
		
		if(temp_node->left)
		enqueue(queue,&rear,temp_node->left);
		
		if(temp_node->right)
		enqueue(queue,&rear,temp_node->right);
		
		temp_node = dequeue(queue,&front);
	}
}

node *newnode(int x)
{
	node *temp = (node *)malloc(sizeof(node));
	if(NULL == temp)
	{
		printf("\n Malloc failed");
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


int main()
{
	
	int value,ele;
	int choice;
	char ch;
	
	root = newnode(1);
	
	do
	{
		do
		{
			printf("\n BFS MENU");
			printf("\n 1.insert");
			printf("\n 2.levelOrder traversal");
			printf("\n 3.exit");
			printf("\n Enter your choice:");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:printf("\n Enter the value to be inserted into tree:");
				       scanf("%d",&value);
				       insert(root,value);
				       break;
				       
				case 2:printf("\n levelOrder traversal:");
				       levelOrder(root);
					   break;
					   	   
					   	   
				default:printf("\n !!!!WRONG CHOICE!!!!");
				        break;	   	   	          
			}
		}
		while(choice != 3);
		printf("\n Do you wish to continue?");
		getchar();
		scanf("%c",&ch);
	}
	while(ch == 'y' || ch == 'Y');
	
 
    return 0;
}
