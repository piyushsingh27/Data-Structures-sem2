#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

void printlist(struct node *temp)
{
	while(temp != NULL)
	{
		printf("\n %d",temp -> data);
		temp = temp -> next;
	}
}

void insert(int data1)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	
	temp -> data = data1;
	temp -> next = head;
	
	head = temp;
	
}

void insertend(struct node *temp,int newdata)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr -> data = newdata;
	ptr -> next = NULL;
	
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = ptr;
	//ptr -> next = NULL;
}


void insertlocation(struct node *temp,int newdata)
{
	int loc;
	int i;
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr -> data = newdata;
	//ptr -> next = NULL;
	
	temp = head;
	
	printf("\n Enter the location at which to enter value:");
	scanf("%d",&loc);
	
	for(i = 0;i < loc; ++i)
	{
		temp = temp -> next;
	}
	
	ptr -> next = temp -> next;
	temp -> next = ptr;
}

void count(struct node *temp)
{
	int counter = 0;
	int x;
	//int new_data;
	
	printf("\n Enter the element to be searched in the list");
	scanf("%d",&x);
	
	while(temp != NULL)
	{
		if(x == temp -> data)
		{
			counter += 1;
		}
		temp = temp -> next;
	}
	
	printf("\n frequency of the element");
	printf("%d",counter);
}

void deletebeg(struct node *temp)
{
	temp = head;
	
	head = head -> next;
	
	free(temp);
}

void deleteend(struct node *temp)
{
	struct node *ptr;
	
	temp = head;
	
	while(temp -> next != NULL)
	{
		ptr = temp;
		temp = temp -> next;
	}
	free(temp);
}

void sort(struct node *current)
{

	struct node *next;
	
	int i,j,tempdata;
	int counter = 0;
	
	while(current != NULL)
	{
		counter += 1;
		current = current -> next;
	}
	
	for(i = 0; i < counter-1; i += 1)
	{
		current = head;
	    next = head -> next;
		for(j = i + 1; j < counter; j += 1)
		{
			if(current -> data > next -> data)
			{
				tempdata = current -> data;
				current -> data = next -> data;
				next -> data = tempdata;
			}
			current = current -> next;
			next = next -> next;
		}
	}
	
	printf("\n List after sorting");
	printlist(head);
}

int main()
{
	int value;
	int choice;
	char ch;
	int i,key;
	/*
	struct node *first = NULL;
	struct node *second = NULL;
	struct node *third = NULL;
	
	
	first = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
	third = (struct node *)malloc(sizeof(struct node));
	
	
	first -> data = 1;
	first -> next = second;
	
	second -> data = 2;
	second -> next = third;
	
	third -> data = 3;
	third -> next = NULL;
	*/
	
	do
	{
		do
		{
			printf("\n MAIN MENU");
			printf("\n 1.insert");
			printf("\n 2.display");
			printf("\n 3.insertlocation");
			printf("\n 4.frequency");
			printf("\n 5.sort");
			printf("\n 6.deletebeg");
			printf("\n 7.insertend");
			printf("\n 8.deleteend");
			printf("\n 9.exit");
			printf("\n Enter your choice");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1: printf("\n You have selected insertion");
				        printf("\n Enter the value to be inserted in linked list");
	                    scanf("%d",&value);
	                    insert(value);
	                    break;
	                    
	            case 2: printf("\n You have selected displaying the values");
	                    printlist(head);
	                    break;
	                    
	            case 3: printf("\n You have selected insert at location");
				        printf("\n Enter the value to be inserted in linked list");
	                    scanf("%d",&value);
						insertlocation(head,value);
						break;
						
				case 4: printf("\n You have selected to search for an element");
				        count(head);
						break;
						
				case 5: printf("\n You have selected to do sorting");
				        sort(head);
						break;
						
				case 6: printf("\n You have selected deletion from beginning");
				        deletebeg(head);
						break;
						
				case 7: printf("\n You have selected insertion at end");
				        printf("\n Enter the value to be inserted");
						scanf("%d",&value);
						insertend(head,value);
						break;
						
				case 8: printf("\n You have selected delete from end");
				        deleteend(head);
						break;										        
	                    
	            default: printf("\n !!!!!!!wrong choice!!!!!!");
				         break;        
				                
			}
		}
		while(choice != 9);
		printf("\n Do you wish to continue");
	    getchar();
	    scanf("%c",&ch);
	}
	while(ch == 'y' || ch == 'y');

}
