#define MAX 50

#include<stdio.h>
#include<stdlib.h>

void linear_search(int);
void binary_search(int);

/* main function begins */
int main()
{
	int y;//variable declared for the element to be searched in the array
	int choice;//variable declared for taking choice of search from the user
	char ch;
	
	/* do while loop begins */
	do
	{
	/* size of the array taken from the user */
	
		
	do
	{
		printf("\n MAIN MENU");
		printf("\n 1.linear search");
		printf("\n 2.binary search");
		printf("\n 3.exit");
		printf("\n Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("\n Searching using linear search");
			        linear_search(y);
			        break;
			        
			case 2: printf("\n Searching using binary search");
			        binary_search(y);
			        break;
					
		    default : printf("\n !!!!Wrong choice entered");
			          break;			
		}
	}
	while(choice!=3);
	printf("\n Do you wish to continue");
	getchar();
	scanf("%c",&ch);
 }
 
 while(ch == 'y' || ch == 'y');
}


/* beginning of linear search function */
void linear_search(int x)
{
	int index;// for loop index for traversing array
	int ar[MAX];//array declaration
	int n;//size of the array to be entered
	int flag = 0;
	
	printf("\n Enter the size of array");
	scanf("%d",&n);
	
	printf("\n Enter array elements");
	for(index = 0;index<n;index+=1)
	{
		printf("\n Elements[%d]:",index+1);
		if(scanf("%d",&ar[index]) != 1)
		{
			printf("\n Enter integer values");
			exit(0);
		}
		
	}
	

	 
	 /* input of the variable to be searched taken from the user */
	 printf("\n Enter the variable to be searched");
	 scanf("%d",&x);
	 
	 for(index = 0; index < n; index += 1)
	 {
	 	if(x == ar[index]) //if element found
	 	{
	 		printf("\n Element found at:");
	 		printf("%d",index+=1);
	 		flag = 1;
		 }
	}
		 
		 if(flag == 0) //if element not found
		 {
		 	printf("\n Element not found");
		 }
}
/* ending of linear search function */



/* beginning of binary search function */

	
	
	
	
void binary_search(int x)
{
	int index, index2, first, last, mid,flag=0;
	int ar[MAX];
	int n,j,temp;

	
	
	
	printf("\n Enter the size of array");
	scanf("%d",&n);
	
	printf("\n Enter array elements");
	for(index = 0;index<n;index+=1)
	{
		printf("\n Elements[%d]:",index+1);
		if(scanf("%d",&ar[index]) != 1)
		{
			printf("\n Enter integer values");
			exit(0);
		}
		
	}
	
	for(index = 0; index < n-1; index += 1)
	{
		for(j = index+1;j < n; j+=1 )
		{
			if(ar[index] > ar[j])
			{
				temp = ar[index];
				ar[index] = ar[j];
				ar[j] = temp;
			}
		}
	}
	
	printf("\n Sorted array:");
	for(index = 0;index < n;index += 1)
	{
		printf("\n Element[%d]:",index+1);
		printf("%d",ar[index]);
	}
	
	
	printf("\n Enter the element to be searched:");
	scanf("%d",&x);
	
	first = 0;
	last = n-1;
	
	do
	{
		mid = (first + last)/2;
		if(ar[mid] < x)
		{
			first = mid;
		}
		else if(ar[mid] > x)
		{
			last = mid;
		}
		else if(ar[mid] == x)
		{
			printf("Element found at position %d\n",mid+1);
			flag = 1;
			break;
		}
	//	printf("%d %d %d",first,mid,last);
		if((first+1) == last)
		{
			mid = first + 1;
			if(ar[mid] == x)
			{
				printf("Element found at position %d\n",mid+1);
				flag = 1;
				break;
			}
		else
		{
			break;
			}	
		}
	}while(first < last);
	
	if(flag == 0)
	{
	    printf("\n Element not found");
	    exit(0);
	}
	return;
}

/* ending of binary search function */


