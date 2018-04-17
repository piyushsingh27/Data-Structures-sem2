#define MAX 20
#define SIZE 30

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***** push operation declaration *********/
void array_insert(char []);

/***** pop operation declaration ******/
void array_delete();

/**** function for displaying values using array representation ****/
char front_value();

char rear_value();

/***** function for push operation using linked list *****/
void Enqueue(char []);

/***** function for pop operation using linked list *****/
void Dequeue();

/**** function for displaying values using linked list *****/
//void linked_display();

char Front();

char Rear();

void Print();



/****** initialising the front and rear of queue ******/
char front = -1;
char rear = -1;


int queue[MAX][SIZE];
char data[SIZE];

struct Node
{
	char data1[SIZE];
    struct Node *next;
}*front1 = NULL, *rear1 = NULL;

/******** beginning of main function ********/
int main()
{
	
	
	/***** choice of the user for switch case *******/
	int choice,choice1 ;
	char value[SIZE];
	
	/****** choice of the user for whether continuing with the program or exiting from it ******/
	char ch;
	
	/***** first do while begins ******/
	do
	{
		printf("\n QUEUE MENU");
		printf("\n 1.Using array");
		printf("\n 2.Using linked list");
		printf("\n 3.Exit");
		printf("\n Enter your choice");
		scanf("%d",&choice1);
		
		switch(choice1)
		{
			case 1: printf("\n Chosen queue operation using array");
			        do
	                {
		                printf("\n OPERATION MENU");
		                printf("\n 1.Insert into queue");
						printf("\n 2.Delete from queue");
						printf("\n 3.Display front value");
						printf("\n 4.Display rear value");
						printf("\n 5.Exit");
						printf("\n Enter your choice:");
						scanf("%d",&choice);
		
						/****************** switch case begins **********************/
						switch(choice)
						{
							case 1: printf("\n Insertion operation to be performed into queue");
			        				printf("\n Enter the value to be inserted into the queue:");
			        				if(scanf("%s",data) != 1)
			        				{
			        					printf("\n Enter string values");
			            				exit(0);
									}
									array_insert(data);
			        				break;
			        
							case 2: printf("\n Delete operation to be performed on queue");
			        				printf("\n Value deleted from queue:");
			        				array_delete();
			        				break;
			        
							case 3: printf("\n Displaying the element at the front of queue:");
			        				printf("%d",front_value()); 
									break;       
									
							case 4: printf("\n Displaying the element at the rear of queue:");
							        printf("%d",rear_value());
									break;		
					
							default : printf("!!!!!Wrong choice entered!!!!!");
			          				  break;    
			        
						}
	
					}
					while(choice!=5);
			        
			        break;
			case 2:printf("\n Chosen queue operation using linked list");
			       do
	                {
		                printf("\n OPERATION MENU");
		                printf("\n 1.Insertion into queue");
						printf("\n 2.Delete from queue");
						printf("\n 3.Front value");
						printf("\n 4.Rear value");
						printf("\n 5.Display");
						printf("\n 6.Exit");
						printf("\n Enter your choice:");
						scanf("%d",&choice);
		
						/****************** switch case begins **********************/
						switch(choice)
						{
							case 1: printf("\n Insertion operation to be performed into queue");
			        				printf("\n Enter the value to be inserted into the queue:");
			        				if(scanf("%s",value) != 1)
			        				{
			        					printf("\n Enter string values");
			            				exit(0);
									}
			        				Enqueue(value);
			        				break;
			        
							case 2: printf("\n Delete operation to be performed on queue");
			        				Dequeue();
			        				break;
			        
						    case 3: printf("\n Displaying the element at the front of queue:");
			        				printf("%d",Front()); 
									break;       
									
							case 4: printf("\n Displaying the element at the rear of queue:");
							        printf("%d",Rear());
									break;      
									
							case 5: printf("\n Displaying the elements of queue:");
							        Print();
									break;		
					
							default : printf("!!!!!Wrong choice entered!!!!!");
			          				  break;    
			        
						}
	
					}
					while(choice!=6);
			        
			        break;
					
			default: printf("\n !!!!!Wrong choice entered!!!!!");
			         break;     
		}
	
	/***** inner do while begins ******/
	
	/***** inner do while ends ******/
	
	printf("\n Do you wish to continue:");
	getchar();
	scanf("%c",&ch);
    }
	while(ch == 'Y' || ch == 'y');
	/****** outer do while ends ******/
	
	return 0;
}
/********** end of main function ***********/


void array_insert(char data[])
{
	for(int i=0;data[i]!='\0';++i)
	{
	
	
	if(rear == MAX-1)
	{
		printf("\n Queue is full,could not insert");
	}
	
	else
	{
		if(front == -1)
		front = 0;
		
		
		rear = rear + 1;
		strcpy(queue[rear][i],data); 
	}
    }
}


void array_delete()
{
	if(front == -1 || front > rear)
	{
		printf("\n Queue underflow,could not delete");
	}
	
	else
	{
		printf("\n Element deleted from queue is: %d\n", queue[front]);
		front = front + 1;
	}
}


char front_value()
{
	return queue[front];
}

char rear_value()
{
    return queue[rear];	
}


// To Enqueue an integer
void Enqueue(char x[]) 
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	strcpy(temp->data1,x); 
	temp->next = NULL;
	if(front1 == NULL && rear1 == NULL)
	{
		front1 = rear1 = temp;
		return;
	}
	rear1->next = temp;
	rear1 = temp;
}

// To Dequeue an integer.
void Dequeue() 
{
	struct Node* temp = front1;
	if(front1 == NULL) {
		printf("\n Queue is Empty");
		return;
	}
	if(front1 == rear1) {
		front1 = rear1 = NULL;
	}
	else {
		front1 = front1->next;
	}
	free(temp);
}

char Front() {
	if(front1 == NULL) {
		printf("\n Queue is empty");
		return;
	}
	return front1->data1;
}

char Rear()
{
	if(rear1 == NULL)
	{
		printf("\n Queue is empty");
		return;
	}
	return rear1->data1;
}

void Print() {
	struct Node* temp = front1;
	while(temp != NULL) {
		printf("%d ",temp->data1);
		temp = temp->next;
	}
	printf("\n");
}

