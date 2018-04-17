#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int data;
	struct node *next;
} node;

node *head = NULL, *start = NULL;


void insert(int newdata)
{
	if(head == NULL)
	{
		head = (node *)malloc(sizeof(node));
		head->data = newdata;
		head->next = NULL;
		start = head;
	}
	
	else
	{
		node *temp = (node *)malloc(sizeof(node));
		temp->data = newdata;
		temp->next = head;
		
		head = temp;
	}
}


void display(node *temp)
{
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("NULL");
}

void merge(node **headref,node **end,node **mid)
{
	node *temphead = *headref;
	node *tempend = *end;
	*mid = temphead + (tempend - temphead)/2;
	node *left,*right;
	while(temphead != *mid)
	{
		
	}
	
	while((*mid)->next != tempend)
	{
		
	}
}

node *mergesort(node **headref,node **end)
{
	node *mid = NULL;
	if((*headref) != *end)
	{
		mid = (*headref) + ((*end) - (*headref))/2;
		mergesort(headref,&(mid));
		mergesort(&(mid->next),end);
		merge(headref,end,&(mid));
	}
}


int main()
{
	int value;
	int choice;
	char ch;
	
	do
	{
		do
		{
			printf("\n MAIN MENU");
			printf("\n 1.insert");
			printf("\n 2.sort");
			printf("\n 3.display");
			printf("\n 4.exit");
			printf("\n Enter your choice:");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:printf("\n Enter the value to be inserted:");
				       scanf("%d",&value);
				       insert(value);
				       break;
				       
				case 2://mergesort(&head,&start);
				       break;
					   
				case 3:display(head);
				       break;
					   
				default:printf("\n !!!!WRONG CHOICE!!!!");
				        break;	   	          
			}
		}
		while(choice != 4);
		
		printf("\n Do you wish to continue?");
		getchar();
		scanf("%c",&ch);
	}
	while(ch == 'y' || ch == 'Y');
}
