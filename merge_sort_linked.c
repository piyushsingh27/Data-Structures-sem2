#include<stdio.h>
#include<stdlib.h>

typedef struct nd
{
	int data;
	struct nd *next;
}node;

node *arr[100];

void insert(node **front , node **rear , int newdata)
{
	if( *front == NULL && *rear == NULL )
	{
		(*front) = (node *)malloc(sizeof(node));
		(*front)->data = newdata;
		(*front)->next = NULL;
		*rear = *front;
	}
	
	else
	{
		node *temp = (node *)malloc(sizeof(node));
		temp->data = newdata;
		temp->next = NULL;
		(*rear)->next = temp;
		*rear = temp;
	}
}


void display(node *temp)
{
	printf("\n\n\n");
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n\n");
}

void merge(node *left,node *right,node *mid)
{
	node *temphead = left ;
	node *tempend = mid->next ;
	
	node *left_front = NULL , *left_rear = NULL , *right_front = NULL , *right_rear = NULL ;
	//printf("\n\n\n");
	while( temphead != mid->next )
	{
		insert( &left_front , &left_rear , temphead->data );
		//printf("%3d",temphead->data);
		temphead = temphead->next;
	}
	//printf("\n\n\n");
	while( right->next != tempend )
	{
		insert( &right_front , &right_rear , tempend->data );
		//printf("%3d",tempend->data);
		tempend = tempend->next;
	}
	
	temphead = left_front ;
	tempend = right_front ;	
	node *ptr = left;
	while( temphead != NULL && tempend != NULL )
	{
		if( temphead->data < tempend->data )
		{
			ptr->data = temphead->data;
			temphead = temphead->next;
		}
		else
		{
			ptr->data = tempend->data;
			tempend = tempend->next;
		}
		ptr = ptr->next;
	}
	
	while(  temphead != NULL )
	{
		ptr->data = temphead->data;
		temphead = temphead->next;
		ptr = ptr->next;
	}
	
	while( tempend != NULL )
	{
		ptr->data = tempend->data;
		tempend = tempend->next;
		ptr = ptr->next;
	}
}

node *mergesort(node *start,node *end, int left , int right )
{
	int mid;
	if( left < right )
	{
		mid = ( left + right ) / 2;
		mergesort( arr[left] , arr[mid] , left , mid );
		mergesort( arr[mid+1] , arr[right] , mid + 1 , right );
		merge( arr[left] , arr[right] , arr[mid] );
	}
}


int main()
{
	int value;
	int choice;
	char ch;
	int count = 0;
	node *front = NULL, *rear = NULL;	
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
				       insert(&front,&rear,value);
				       arr[count] = rear;
				       count++;
				       break;
				       
				case 2:mergesort( front , rear , 0 , count - 1 );
				       break;
					   
				case 3:display(front);
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
