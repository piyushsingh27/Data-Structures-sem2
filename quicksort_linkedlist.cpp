#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL;


void display(struct Node *temp)
{
	while(temp != NULL)
	{
		printf("%d->",temp -> data);
		temp = temp -> next;
	}
	printf("NULL");
}


void insert(int newdata)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	
	temp -> data = newdata;
	temp -> next = head;
	
	head = temp;
}

// Returns the last node of the list
struct Node *getTail(struct Node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the last element as the pivot
struct Node *partition(struct Node *head, struct Node *end,
                       struct Node **newHead, struct Node **newEnd)
{
    struct Node *pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {           
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
 
 
//here the sorting happens exclusive of the end node
struct Node *quickSortRecur(struct Node *head, struct Node *end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    Node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct Node *pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}
 
// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(struct Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
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
	printf("\n 2.display");
	printf("\n 3.quicksort");
	printf("\n 4.exit");
	printf("\n Enter your choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1: printf("\n You have selected insertion");
		        printf("\n Enter the value to be inserted");
		        scanf("%d",&value);
		        insert(value);
		        break;
		        
		case 2: printf("\n You have selected to display the list");
		        display(head); 
		        
		case 3: printf("\n You have selected quicksort");
		        quickSort(&head);  
				break;      
				
		default : printf("\n !!!!Wrong choice!!!!");
		          break;		       
	}
	
}
while(choice != 4);
printf("\n Do you wish to continue");
getchar();
scanf("%c",&ch);
}
while(ch == 'y' || ch == 'Y');
}

